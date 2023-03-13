cmake_minimum_required(VERSION 3.8)

PROJECT(dmiconv)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

ADD_DEFINITIONS(-DUSE_DMICONV)

ModuleImport("dmformat" "thirdparty/dmformat")
ModuleImport("dmchardet" "thirdparty/dmchardet")
ModuleImport("libiconv" "thirdparty/libiconv")

IF (WIN32)
    INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/windows)
ENDIF(WIN32)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/test)

IF (WIN32)
   SET(ICONV_VERSION_STRING "1.11.1")
   SET(ICONV_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/win/include")
   SET(ICONV_LIBRARIES "iconv;charset")

   INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIRS})
   LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/win/lib)

   MESSAGE(STATUS "Found Iconv version: ${ICONV_VERSION_STRING}")
   MESSAGE(STATUS "Using Iconv include dir(s): ${ICONV_INCLUDE_DIRS}")
   MESSAGE(STATUS "Using Iconv lib(s): ${ICONV_LIBRARIES}")
ELSE(WIN32)
    MESSAGE(STATUS "Looking for libiconv")
    SET(ICONV_VERSION_STRING "1.11.1")
    SET(ICONV_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/include")
    #SET(ICONV_LIBRARIES "iconv" "charset")
    LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/libcharset/lib/.libs)
    LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/lib/.libs)	
    INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIRS})
ENDIF(WIN32)

IF (WIN32)
    LibImportDepends("dmiconv" "src/dmiconv_module" "${ICONV_LIBRARIES};dmchardet")
    ExeImport("test" "dmiconv;${ICONV_LIBRARIES};dmchardet")

    ADD_CUSTOM_COMMAND(
	TARGET dmiconvtest
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/win/bin/iconv.dll $<TARGET_FILE_DIR:dmiconvtest>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/win/bin/charset.dll $<TARGET_FILE_DIR:dmiconvtest>
    )

ELSE(WIN32)
    ADD_DEFINITIONS(-DLIBICONV_PLUG)

    DllImportDepends("dmiconv" "src/dmiconv_module" "libiconv.so;libcharset.so;libuchardet")
    ExeImport("test" "dmiconv;libiconv.so;libcharset.so;libuchardet")

    ADD_CUSTOM_COMMAND(
        TARGET dmiconv
        PRE_BUILD
        COMMAND ./configure
        COMMAND make
        COMMAND echo "make finish"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/lib/.libs/libiconv.so $<TARGET_FILE_DIR:dmiconv>/libiconv.so
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv/libcharset/lib/.libs/libcharset.so $<TARGET_FILE_DIR:dmiconv>/libcharset.so
        COMMAND echo "copy finish"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libiconv
        )

ENDIF(WIN32)
