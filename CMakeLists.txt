cmake_minimum_required(VERSION 3.9)

project(Blob)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(SFML 2.5 COMPONENTS window graphics network audio system REQUIRED)
if (NOT SFML_FOUND)
	message(ERROR "SFML not found")
endif()

find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
	message(ERROR "SDL2 not found")
endif()
include_directories(${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
if (NOT OPENGL_FOUND )
	message(ERROR "OpenGL not found")
endif()
include_directories(${OPENGL_INCLUDE_DIR})

add_subdirectory(libs)
add_subdirectory(BlobEngine)
add_subdirectory(Bomberman)
