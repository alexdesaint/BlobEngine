add_executable (CollisionTest CollisionTest.cpp)

add_executable (HitTest HitTest.cpp)

set(CMAKE_MODULE_PATH "C:/msys64/mingw64/cmake/Modules")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED window graphics network audio system)
IF (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
else()
    message(WARNING "SFML not found")
endif()

target_link_libraries(CollisionTest BlobEngine ${SFML_LIBRARIES};${SFML_DEPENDENCIES} -static-libgcc -static-libstdc++ -static -lpthread)
target_link_libraries(HitTest Hit Geometrie ${SFML_LIBRARIES};${SFML_DEPENDENCIES} -static-libgcc -static-libstdc++ -static -lpthread)