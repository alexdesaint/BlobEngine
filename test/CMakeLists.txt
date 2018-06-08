add_executable(HitTest HitTest.cpp)
target_link_libraries(HitTest Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(CollisionTest CollisionTest.cpp)
target_link_libraries(CollisionTest Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(GraphicTest GraphicTest.cpp)
target_link_libraries(GraphicTest sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(Box2DTest Box2DTest.cpp)
target_link_libraries(Box2DTest Box2D sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(NewFonctionTest NewFonctionTest.cpp)
target_link_libraries(NewFonctionTest Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)
