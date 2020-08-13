
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "luaiconv.h"
#include "dmiconv.h"

Cluaiconv::Cluaiconv(sol::this_state L)
    : m_oState(L)
{

}

std::string Cluaiconv::detect(std::string& in)
{
    return std::move(iconvpp::detect(in));
}

std::string Cluaiconv::toLatin(std::string& in)
{
    return std::move(iconvpp::toLatin(in));
}

std::string Cluaiconv::toUtf8(std::string& in)
{
    return iconvpp::toUtf8(in);
}

std::string Cluaiconv::toAscii(std::string& in)
{
    return std::move(iconvpp::toAscii(in));
}

std::string Cluaiconv::toGbk(std::string& in)
{
    return std::move(iconvpp::toGbk(in));
}

std::string Cluaiconv::toGb18030(std::string& in)
{
    return std::move(iconvpp::toGb18030(in));
}
