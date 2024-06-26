# luaiconv

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![luaiconv](https://img.shields.io/badge/brinkqiang-luaiconv-blue.svg?style=flat-square)](https://github.com/brinkqiang/luaiconv)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/luaiconv/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/luaiconv.svg?label=Stars)](https://github.com/brinkqiang/luaiconv) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/luaiconv.svg?label=Fork)](https://github.com/brinkqiang/luaiconv)

## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/luaiconv/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/luaiconv/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/luaiconv/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/luaiconv/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/luaiconv/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/luaiconv/actions/workflows/win.yml "win build status"

## env
install cmake

## Intro
luaiconv
```lua
local luaiconv = require("luaiconv")

local test_str = "谦逊是藏于土中甜美的根,所有崇高的美德由此发芽滋长 hello"
print("[1]" .. luaiconv.detect(test_str))
print("[2]" .. test_str)
print("[3]" .. luaiconv.toLatin(test_str))
print("[4]" .. luaiconv.toUtf8(test_str))
print("[5]" .. luaiconv.toAscii(test_str))
print("[6]" .. luaiconv.toUtf8(luaiconv.toUtf8(test_str)))
print("[7]" .. luaiconv.toGbk(test_str))
print("[8]" .. luaiconv.toGb18030(test_str))
print("[9]" .. luaiconv.convert("utf-8", "gb18030", test_str))
print("[10]" .. luaiconv.convert("gb18030", "utf-8", test_str))

```

windows output
```
lua ../script/main.lua
[1]utf-8
[2]瀵嗘秴鐡︾殑鐚ご楣板湪榛勬槒璧烽 hello
[3] hello
[4]瀵嗘秴鐡︾殑鐚ご楣板湪榛勬槒璧烽 hello
[5] hello
[6]瀵嗘秴鐡︾殑鐚ご楣板湪榛勬槒璧烽 hello
[7]谦逊是藏于土中甜美的根,所有崇高的美德由此发芽滋长 hello
[8]谦逊是藏于土中甜美的根,所有崇高的美德由此发芽滋长 hello
[9]鐎靛棙绉撮悺锔炬畱閻氼偄銇旀ィ鏉挎躬姒涘嫭妲掔挧鐑筋棧 hello
[10]密涅瓦的猫头鹰在黄昏起飞 hello
```
linux output
```
./lua ../script/main.lua
[1]utf-8
[2]谦逊是藏于土中甜美的根,所有崇高的美德由此发芽滋长 hello
[3]???????????? hello
[4]谦逊是藏于土中甜美的根,所有崇高的美德由此发芽滋长 hello
[5]???????????? hello
[6]谦逊是藏于土中甜美的根,所有崇高的美德由此发芽滋长 hello
[7]èͷӥello
[8]èͷӥello
[9]瀵嗘秴鐡︾殑鐚ご楣板湪榛勬槒璧烽 hello
[10]èͷӥello
```

## Contacts

## Thanks
