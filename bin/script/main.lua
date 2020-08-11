-- lua script

local luaiconv = require("luaiconv")

print(luaiconv.L2U("世界人民你们好nihao!"))

print(luaiconv.U2L(luaiconv.L2U("世界人民你们好nihao!")))
