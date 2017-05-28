cmake_minimum_required(VERSION 2.8)

project(glad)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(glad_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)

add_library(glad glad.c)
