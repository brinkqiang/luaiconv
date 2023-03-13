-- lua script

local luaiconv = require("luaiconv")

local test_str = "谦逊是藏于土中甜美的根,所有崇高的美德由此发芽滋长"
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


