
#include "dmiconv.h"

iconvpp::converter::converter(const std::string& out_encode,
                              const std::string& in_encode, bool ignore_error /*= false*/,
                              size_t buf_size /*= 10240*/) : ignore_error_(ignore_error),
    buf_size_(buf_size)
{
    if (buf_size == 0)
    {
        throw std::runtime_error("buffer size must be greater than zero");
    }

    iconv_t conv = ::iconv_open(out_encode.c_str(), in_encode.c_str());

    if (conv == (iconv_t)-1)
    {
        if (errno == EINVAL)
            throw std::runtime_error(
                "not supported from " + in_encode + " to " + out_encode);
        else
        {
            throw std::runtime_error("unknown error");
        }
    }

    iconv_ = conv;
}

iconvpp::converter::~converter()
{
    iconv_close(iconv_);
}

void iconvpp::converter::convert(const std::string& input,
                                 std::string& output) const
{
    std::vector<char> in_buf(input.begin(), input.end());
    char* src_ptr = &in_buf[0];
    size_t src_size = input.size();

    std::vector<char> buf(buf_size_);
    std::string dst;

    while (0 < src_size)
    {
        char* dst_ptr = &buf[0];
        size_t dst_size = buf.size();
#ifdef WIN32
        size_t res = ::iconv(iconv_, (const char**)&src_ptr, &src_size, &dst_ptr,
                             &dst_size);
#else
        size_t res = ::iconv(iconv_, &src_ptr, &src_size, &dst_ptr, &dst_size);
#endif

        if (res == (size_t)-1)
        {
            if (errno == E2BIG)
            {
                // ignore this error
            }
            else if (ignore_error_)
            {
                // skip character
                ++src_ptr;
                --src_size;
            }
            else
            {
                 check_convert_error();
            }
        }

        dst.append(&buf[0], buf.size() - dst_size);
    }

    dst.swap(output);
}

void iconvpp::converter::check_convert_error() const
{
    switch (errno)
    {
    case EILSEQ:
    case EINVAL:
        throw std::runtime_error("invalid multibyte chars");

    default:
        throw std::runtime_error("unknown error");
    }
}

std::string iconvpp::Utf8toLatin(std::string& in)
{
    iconvpp::converter conv("iso-8859-1", "UTF-8", true);
    std::string out;
    conv.convert(in, out);
    return std::move(out);
}

std::string iconvpp::LatintoUtf8(std::string& in)
{
    iconvpp::converter reconv("UTF-8", "iso-8859-1", true);
    std::string out;
    reconv.convert(in, out);
    return std::move(out);
}

std::string iconvpp::Utf8toGB18030(std::string& in)
{
    iconvpp::converter conv("GB18030", "UTF-8", true);
    std::string out;
    conv.convert(in, out);
    return std::move(out);
}

std::string iconvpp::GB18030toUtf8(std::string& in)
{
    iconvpp::converter reconv("UTF-8", "GB18030", true);
    std::string out;
    reconv.convert(in, out);
    return std::move(out);
}
