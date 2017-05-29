CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(game CXX)


SET(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
SET(glm_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/modules/glm)

SET(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable build of docs" FORCE)
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable build of tests" FORCE)
SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable build of examples" FORCE)
SET(GLFW_INSTALL OFF CACHE BOOL "Generate installation target" FORCE)


ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/modules/glfw)
ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/modules/glad)
ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/modules/imgui)

include_directories(
	${glfw_INCLUDE_DIRS}
	${glad_INCLUDE_DIRS}
	${glm_INCLUDE_DIRS}
	${imgui_INCLUDE_DIRS}
)

ADD_EXECUTABLE(game ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/imgui_impl_glfw_gl3.cpp ${CMAKE_SOURCE_DIR}/src/imgui_impl_glfw_gl3.h)

TARGET_LINK_LIBRARIES(game glad glfw imgui)

if (APPLE)
	set_target_properties(game PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Game")
endif ()

TARGET_COMPILE_FEATURES(game PRIVATE cxx_range_for)                                                      
