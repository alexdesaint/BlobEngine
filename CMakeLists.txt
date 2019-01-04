cmake_minimum_required(VERSION 3.9)

project(BlobEngine LANGUAGES C CXX VERSION 1.0.0 DESCRIPTION "Game utility tools")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)
link_directories(lib)

find_package(SFML 2.5 COMPONENTS window graphics network audio system REQUIRED)
if (NOT SFML_FOUND)
	message(ERROR "SFML not found")
endif()

find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
	message(ERROR "SDL2 not found")
endif()
include_directories(${SDL2_INCLUDE_DIRS})

subdirs(src)
subdirs(test)