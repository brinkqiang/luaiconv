set(
	UCHARDET_SOURCES
	uchardet.cpp
	getopt_long.cpp
)

set(UCHARDET_BINARY uchardet)

add_executable(
	${UCHARDET_BINARY}
	${UCHARDET_SOURCES}
)

target_link_libraries(
	${UCHARDET_BINARY}
	${UCHARDET_LIBRARY}
)

install(
	TARGETS
		${UCHARDET_BINARY}
	RUNTIME DESTINATION
		${CMAKE_INSTALL_BINDIR}
)
