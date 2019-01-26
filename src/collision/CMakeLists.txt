add_library(Collision CollisionDetector.cpp)
target_link_libraries(Collision Geometrie)
target_include_directories(Collision PUBLIC ../../include)
