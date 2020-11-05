cmake_minimum_required(VERSION 3.9)

project(BlobEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BLOBTEST "Build the tests" ON)
option(BLOBVK "Build Vulkan" OFF)
option(BUILD_DOC "Build documentation" ON)

set(OpenGL_GL_PREFERENCE "GLVND")
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

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN NO)
    set(DOXYGEN_DISTRIBUTE_GROUP_DOC YES)
    set(DOXYGEN_FULL_PATH_NAMES YES)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
    set(DOXYGEN_STRIP_FROM_INC_PATH ${PROJECT_SOURCE_DIR}/include)
    #set(DOXYGEN_UML_LOOK YES)
    #set(DOXYGEN_EXTRACT_ALL YES)

    doxygen_add_docs(
            doxygen
            README.md
            src
            include
    )

else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_subdirectory(libs)
add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(test)
endif ()
