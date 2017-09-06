cmake_minimum_required(VERSION 2.8) 
PROJECT (opencvtest)
find_package(OpenCV REQUIRED )
set( NAME_SRC
    	src/main.cpp   
	src/extraFunc.cpp
)

set( NAME_HEADERS
	include/extraFunc.h
)

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( opencvtest ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries( opencvtest ${OpenCV_LIBS} )