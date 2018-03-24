add_library(Hit Hit.cpp)
target_link_libraries(Hit Geometrie)

add_library(CollisionDetector CollisionDetector.cpp)
target_link_libraries(CollisionDetector Hit)
