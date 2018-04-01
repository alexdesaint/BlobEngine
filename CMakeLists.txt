cmake_minimum_required(VERSION 3.9)

project(BlobEngine LANGUAGES CXX VERSION 1.0.0 DESCRIPTION "Game utility tools")

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

set(CMAKE_MODULE_PATH "C:/msys64/mingw64/cmake/Modules")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED window graphics network audio system)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
else()
	message(WARNING "SFML not found")
endif()

subdirs(src)
subdirs(test)

enable_testing()
add_test(NAME CollisionTest COMMAND CollisionTest)
add_test(NAME HitTest COMMAND HitTest)