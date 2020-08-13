-- lua script

local luaiconv = require("luaiconv")

print(luaiconv.detect("世界人民你们好 hello"))
print(luaiconv.toLatin("世界人民你们好 hello"))
print(luaiconv.toUtf8("世界人民你们好 hello"))
print(luaiconv.toAscii("世界人民你们好 hello"))
print(luaiconv.toUtf8(luaiconv.toUtf8("世界人民你们好 hello")))
print(luaiconv.toGbk("世界人民你们好 hello"))
print(luaiconv.toGb18030("世界人民你们好 hello"))