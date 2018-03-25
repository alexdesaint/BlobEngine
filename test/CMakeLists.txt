set(CMAKE_MODULE_PATH "C:/msys64/mingw64/cmake/Modules")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED window graphics network audio system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
else()
    message(WARNING "SFML not found")
endif()

add_executable(HitTest HitTest.cpp)
target_link_libraries(HitTest Collision Geometrie ${SFML_LIBRARIES};${SFML_DEPENDENCIES} -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(CollisionTest CollisionTest.cpp)
target_link_libraries(CollisionTest  Collision Geometrie ${SFML_LIBRARIES};${SFML_DEPENDENCIES} -static-libgcc -static-libstdc++ -static -lpthread)
