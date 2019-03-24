cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

project(BlobEngine LANGUAGES CXX C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenGL REQUIRED)
if (NOT OPENGL_FOUND )
	message(ERROR "OpenGL not found")
endif()
include_directories(${OPENGL_INCLUDE_DIR})

find_package(Vulkan REQUIRED)
if (NOT Vulkan_FOUND )
	message(ERROR "Vulkan not found")
endif()
include_directories(${VULKAN_INCLUDE_DIR})

add_subdirectory(libs)
add_subdirectory(src)
add_subdirectory(test)
