add_library(Collision CollisionDetector.cpp Hit.cpp CollisionDetectorException.cpp CollisionDetectorException.cpp)
target_link_libraries(Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)
