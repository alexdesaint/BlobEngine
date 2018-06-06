cmake_minimum_required(VERSION 3.9)

project(BlobEngine LANGUAGES CXX VERSION 1.0.0 DESCRIPTION "Game utility tools")

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(SFML_DIR "${PROJECT_SOURCE_DIR}/../SFML/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML CONFIG COMPONENTS window graphics network audio system)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
else()
	message(WARNING "SFML not found")
endif()

file(GLOB_RECURSE Box2Dsrc
		"Box2D/*.cpp"
		)

add_library(Box2D SHARED "${Box2Dsrc}")

include_directories(include)
subdirs(src)
subdirs(test)

enable_testing()
add_test(NAME CollisionTest COMMAND CollisionTest)
add_test(NAME HitTest COMMAND HitTest)