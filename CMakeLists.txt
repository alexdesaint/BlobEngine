cmake_minimum_required(VERSION 3.9)

project(BlobEngine LANGUAGES C CXX VERSION 1.0.0 DESCRIPTION "Game utility tools")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)
link_directories(lib)

set(SFML_DIR "${PROJECT_SOURCE_DIR}/../SFML/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS window graphics network audio system REQUIRED)
if (NOT SFML_FOUND)
	message(WARNING "SFML not found")
endif()

include_directories("${PROJECT_SOURCE_DIR}/../SFML/include")

subdirs(src)
subdirs(test)

enable_testing()
add_test(NAME CollisionTest COMMAND CollisionTest)
add_test(NAME HitTest COMMAND HitTest)