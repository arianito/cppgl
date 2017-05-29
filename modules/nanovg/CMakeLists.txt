cmake_minimum_required(VERSION 2.8)

project(nanovg)

file(GLOB SRC_FILES
    *.c
    *.h
)


set(nanovg_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)

add_library(nanovg ${SRC_FILES})
