add_executable (Test test.cpp)

set(CMAKE_MODULE_PATH "C:/msys64/mingw64/cmake/Modules")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED window graphics network audio system)
IF (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    message("SFML found")
else()
    message(WARNING "SFML not found")
endif()


target_link_libraries (Test ${EXECUTABLE_NAME} ${SFML_LIBRARIES};${SFML_DEPENDENCIES} -static-libgcc -static-libstdc++ -static -lpthread)