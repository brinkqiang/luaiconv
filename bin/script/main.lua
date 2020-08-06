-- lua script

local luaiconv = require("luaiconv")

print(luaiconv.U2A(luaiconv.A2U("世界人民你们好!")))

print(luaiconv.U2G(luaiconv.A2U("世界人民你们好!")))

print(luaiconv.U2A((luaiconv.G2U(luaiconv.U2G(luaiconv.A2U("世界人民你们好!"))))))
