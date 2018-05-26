add_executable(HitTest HitTest.cpp)
target_link_libraries(HitTest Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(CollisionTest CollisionTest.cpp)
target_link_libraries(CollisionTest Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(GraphicTest GraphicTest.cpp)
target_link_libraries(GraphicTest sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)
