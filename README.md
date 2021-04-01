# luaiconv

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![luaiconv](https://img.shields.io/badge/brinkqiang-luaiconv-blue.svg?style=flat-square)](https://github.com/brinkqiang/luaiconv)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/luaiconv/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/luaiconv.svg?label=Stars)](https://github.com/brinkqiang/luaiconv) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/luaiconv.svg?label=Fork)](https://github.com/brinkqiang/luaiconv)

## Build status
| [Linux][lin-link] | [MacOSX][osx-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![osx-badge]       | ![win-badge]        |

[lin-badge]: https://travis-ci.org/brinkqiang/luaiconv.svg?branch=master "Travis build status"
[lin-link]:  https://travis-ci.org/brinkqiang/luaiconv "Travis build status"
[osx-badge]: https://travis-ci.org/brinkqiang/luaiconv.svg?branch=master "Travis build status"
[osx-link]:  https://travis-ci.org/brinkqiang/luaiconv "Travis build status"
[win-badge]: https://ci.appveyor.com/api/projects/status/github/brinkqiang/luaiconv?branch=master&svg=true "AppVeyor build status"
[win-link]:  https://ci.appveyor.com/project/brinkqiang/luaiconv "AppVeyor build status"

## env
install cmake

## Intro
luaiconv
```lua
local luaiconv = require("luaiconv")

local test_str = "密涅瓦的猫头鹰在黄昏起飞 hello"
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
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/luaiconv/Lobby.svg)](https://gitter.im/brinkqiang/luaiconv)

## Thanks
