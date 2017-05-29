cmake_minimum_required(VERSION 2.8)

project(imgui)

file(GLOB SRC_FILES
    *.c
	*.cpp
    *.h
)


set(imgui_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)

add_library(imgui ${SRC_FILES})
