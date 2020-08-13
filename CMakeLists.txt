cmake_minimum_required(VERSION 3.2)

PROJECT(luaiconv)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/LuaModule.cmake)
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(LUA_MODULE lua53)
SET(LUAICONV_VERSION_MAJOR "1")
SET(LUAICONV_VERSION_MINOR "0")
SET(LUAICONV_VERSION_PATCH "1")
SET(LUAICONV_VERSION "${LUAICONV_VERSION_MAJOR}.${LUAICONV_VERSION_MINOR}.${LUAICONV_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${LUAICONV_VERSION}")

ADD_DEFINITIONS(-DUSE_LUAICONV)
ADD_DEFINITIONS(-DLUA_COMPAT_5_1)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

IF (WIN32)
    INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/dmiconv/thirdparty/libiconv/win/include)
    LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/dmiconv/thirdparty/libiconv/win/lib)
ELSE(WIN32)
    INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/dmiconv/thirdparty/libiconv/include)
    LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/libiconv/libcharset/lib/.libs)	
    LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/lib/.libs)	
ENDIF(WIN32)

ModuleImport("dmiconv" "thirdparty/dmiconv")
LuaModuleImport("${LUA_MODULE}" "luaiconv" "src/luaiconv" "dmiconv iconv charset")

