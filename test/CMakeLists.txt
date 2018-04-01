add_executable(HitTest HitTest.cpp)
target_link_libraries(HitTest Collision Geometrie ${SFML_LIBRARIES};${SFML_DEPENDENCIES} -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(CollisionTest CollisionTest.cpp ../include/BlobEngine/CollisionDetectorException.hpp)
target_link_libraries(CollisionTest  Collision Geometrie ${SFML_LIBRARIES};${SFML_DEPENDENCIES} -static-libgcc -static-libstdc++ -static -lpthread)
