cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

project(BlobEngine LANGUAGES CXX C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

option(BLOBTEST "Build the tests" OFF)
option(BLOBVK "Build Vulkan" OFF)

find_package(OpenGL REQUIRED)
if (NOT OPENGL_FOUND)
    message(ERROR "OpenGL not found")
endif ()
include_directories(${OPENGL_INCLUDE_DIR})

if (BLOBVK)
    find_package(Vulkan REQUIRED)
    if (NOT Vulkan_FOUND)
        message(ERROR "Vulkan not found")
    endif ()
    include_directories(${VULKAN_INCLUDE_DIR})
endif ()

add_subdirectory(libs)
add_subdirectory(src)

if (BLOBTEST)
    add_subdirectory(test)
endif ()
