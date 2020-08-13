
#ifndef __DMICONV_H_INCLUDE__
#define __DMICONV_H_INCLUDE__

#include <errno.h>
#include <iconv.h>

#include <stdexcept>
#include <string>
#include <vector>

namespace iconvpp
{

class converter
{
public:
    converter(const std::string& out_encode,
              const std::string& in_encode,
              bool ignore_error = false);

    ~converter();

    void convert(const std::string& input, std::string& output) const;

private:
    void check_convert_error() const;

    iconv_t iconv_;
    bool ignore_error_;
};

std::string detect(std::string& input);

std::string toLatin(std::string& in);
std::string toUtf8(std::string& in);
std::string toAscii(std::string& in);
std::string toGbk(std::string& in);
std::string toGb18030(std::string& in);

}  // namespace iconvpp

#endif // __DMICONV_H_INCLUDE__
