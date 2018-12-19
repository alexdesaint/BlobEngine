add_executable(HitTest HitTest.cpp)
target_link_libraries(HitTest Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(CollisionTest CollisionTest.cpp)
target_link_libraries(CollisionTest Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(SFMLGraphicTest SFMLGraphicTest.cpp)
target_link_libraries(SFMLGraphicTest Graphic glad sfml-system sfml-graphics sfml-window -lglu32 -lopengl32 -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(glTF2test glTF2test.cpp)
target_link_libraries(glTF2test glTF2 BlobGL glad FileReader JsonExplorer -lglu32 -lopengl32 ${SDL2_LIBRARIES})

add_executable(OpenGLtest OpenGLtest.cpp)
target_link_libraries(OpenGLtest BlobGL glad -lglu32 -lopengl32 ${SDL2_LIBRARIES})

add_executable(BlobGLtest BlobGLtest.cpp)
target_link_libraries(BlobGLtest BlobGL glad FileReader JsonExplorer -lglu32 -lopengl32 ${SDL2_LIBRARIES})

#STATIC -lmingw32 SDL2main SDL2-static
#STATIC -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid
#STATIC : -static -static-libgcc -static-libstdc++ -lpthread

add_executable(TestFileReader TestFileReader.cpp)
target_link_libraries(TestFileReader Shape -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(Box2DTest Box2DTest.cpp)
target_link_libraries(Box2DTest Box2D Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)
