
#include "dmiconv.h"
#include "uchardet.h"
#include <string.h>

iconvpp::converter::converter(const std::string& out_encode,
                              const std::string& in_encode, bool ignore_error /*= false*/)
    : ignore_error_(ignore_error)
{
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

    std::vector<char> buf(src_size * 6);
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

std::string iconvpp::detect(const std::string& input)
{
    uchardet_t  handle = uchardet_new();
    char* charset;
    size_t len = input.size();
    int retval = uchardet_handle_data(handle, input.data(), len);

    if (retval != 0)
    {
        fprintf(stderr,
                "uchardet-tests: handle data error.\n");
        exit(1);
    }

    uchardet_data_end(handle);

    charset = strdup(uchardet_get_charset(handle));

    for (int i = 0; charset[i]; i++)
    {
        /* Our test files are lowercase. */
        charset[i] = tolower(charset[i]);
    }

    uchardet_delete(handle);

    return charset;
}

std::string iconvpp::convert(const std::string& out_encode, const std::string& in_encode, const std::string& in)
{
    iconvpp::converter conv(out_encode, in_encode, true);
    std::string out;
    conv.convert(in, out);
    return std::move(out);
}

std::string iconvpp::toLatin(const std::string& in)
{
    iconvpp::converter conv("iso-8859-1//TRANSLIT", detect(in), true);
    std::string out;
    conv.convert(in, out);
    return std::move(out);
}

std::string iconvpp::toUtf8(const std::string& in)
{
    iconvpp::converter reconv("UTF-8//TRANSLIT", detect(in), true);
    std::string out;
    reconv.convert(in, out);
    return std::move(out);
}

std::string iconvpp::toAscii(const std::string& in)
{
    iconvpp::converter conv("ASCII//TRANSLIT", detect(in), true);
    std::string out;
    conv.convert(in, out);
    return std::move(out);
}

std::string iconvpp::toGbk(const std::string& in)
{
    iconvpp::converter conv("GBK//TRANSLIT", detect(in), true);
    std::string out;
    conv.convert(in, out);
    return std::move(out);
}

std::string iconvpp::toGb18030(const std::string& in)
{
    iconvpp::converter conv("GB18030//TRANSLIT", detect(in), true);
    std::string out;
    conv.convert(in, out);
    return std::move(out);
}