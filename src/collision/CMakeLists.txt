add_library(Collision CollisionDetector.cpp Hit.cpp CollisionDetectorException.cpp CollisionDetectorException.cpp)
target_link_libraries(Collision Geometrie ${SFML_LIBRARIES};${SFML_DEPENDENCIES} -static-libgcc -static-libstdc++ -static -lpthread)
