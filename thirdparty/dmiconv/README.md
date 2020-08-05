# dmiconv

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[dmiconv GitHub](https://github.com/brinkqiang/dmiconv)

## Build status
| [Linux][lin-link] | [MacOSX][osx-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![osx-badge]       | ![win-badge]        |

[lin-badge]: https://travis-ci.org/brinkqiang/dmiconv.svg?branch=master "Travis build status"
[lin-link]:  https://travis-ci.org/brinkqiang/dmiconv "Travis build status"
[osx-badge]: https://travis-ci.org/brinkqiang/dmiconv.svg?branch=master "Travis build status"
[osx-link]:  https://travis-ci.org/brinkqiang/dmiconv "Travis build status"
[win-badge]: https://ci.appveyor.com/api/projects/status/github/brinkqiang/dmiconv?branch=master&svg=true "AppVeyor build status"
[win-link]:  https://ci.appveyor.com/project/brinkqiang/dmiconv "AppVeyor build status"

## Intro
dmiconv
```cpp

#include "dmos.h"
#include "dmutil.h"
#include "dmtypes.h"
#include "dmformat.h"
#include "dmiconv.h"

int main(int argc, char* argv[]) {
    {
        std::string in = "hello iconv";
        std::string out = iconvpp::LatintoUtf8(in);
        fmt::fprintf(stdout, "%s\n", out.c_str());
        std::string out2 = iconvpp::Utf8toLatin(out);
        fmt::fprintf(stdout, "%s\n", out2.c_str());
    }
    {
        std::string in = "今天天气不错";
        std::string out = iconvpp::LatintoUtf8(in);
        fmt::fprintf(stdout, "%s\n", out.c_str());
        std::string out2 = iconvpp::Utf8toLatin(out);
        fmt::fprintf(stdout, "%s\n", out2.c_str());
    }
    {
        std::string in = "2018 你好";
        std::string out = iconvpp::LatintoUtf8(in);
        fmt::fprintf(stdout, "%s\n", out.c_str());
        std::string out2 = iconvpp::Utf8toLatin(out);
        fmt::fprintf(stdout, "%s\n", out2.c_str());
    }
    return 0;
}

```
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/dmiconv/Lobby.svg)](https://gitter.im/brinkqiang/dmiconv)

## Thanks
