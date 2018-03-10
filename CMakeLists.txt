cmake_minimum_required(VERSION 3.9)

set(EXECUTABLE_NAME "BlobEngine")
project(${EXECUTABLE_NAME} VERSION 1.0.0 DESCRIPTION "Game utility tools")

set(CMAKE_CXX_STANDARD 14)

subdirs(src)
subdirs(test)

enable_testing ()
add_test (NAME MyTest COMMAND Test)