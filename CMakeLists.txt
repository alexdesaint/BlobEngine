cmake_minimum_required(VERSION 3.9)

project(BlobEngine VERSION 1.0.0 DESCRIPTION "Game utility tools")

set(CMAKE_CXX_STANDARD 14)

subdirs(BlobEngine)
subdirs(test)

enable_testing ()
add_test (NAME MyTest COMMAND Test)