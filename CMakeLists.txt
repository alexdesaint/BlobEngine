cmake_minimum_required(VERSION 3.9)

project(BlobEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)

option(BLOBTEST "Build the tests" OFF)

# add_compile_options("-stdlib=libc++")
# add_link_options("-fuse-ld=lld")
# link_libraries(c++)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN NO)

    # grouping documentation
    set(DOXYGEN_DISTRIBUTE_GROUP_DOC YES)

    # main page
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)

    # for include
    set(DOXYGEN_FULL_PATH_NAMES YES)
    set(DOXYGEN_STRIP_FROM_INC_PATH ${PROJECT_SOURCE_DIR}/include)

    doxygen_add_docs(
            doxygen
            README.md
            src
            include
    )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

set(INCLUDE_FOLDER ${PROJECT_SOURCE_DIR}/include)
add_subdirectory(libs)
add_subdirectory(shaders)
add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR BLOBTEST)
    add_subdirectory(test)
endif ()
