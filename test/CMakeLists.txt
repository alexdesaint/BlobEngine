add_executable(HitTest HitTest.cpp)
target_link_libraries(HitTest Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(CollisionTest CollisionTest.cpp)
target_link_libraries(CollisionTest Collision Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(SFMLGraphicTest SFMLGraphicTest.cpp)
target_link_libraries(SFMLGraphicTest Graphic glad sfml-system sfml-graphics sfml-window -lglu32 -lopengl32 -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(SDLGraphicTest SDLGraphicTest.cpp)
target_link_libraries(SDLGraphicTest Graphic glad)
#opengl
target_link_libraries(SDLGraphicTest -lglu32 -lopengl32)
#SDL

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(SDLGraphicTest
		${SDL2_LIBRARIES}
		#-lmingw32 SDL2main SDL2-static
		#-mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid
		)

#STATIC : -static -static-libgcc -static-libstdc++ -lpthread

add_executable(TestFileReader TestFileReader.cpp)
target_link_libraries(TestFileReader Shape -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(Box2DTest Box2DTest.cpp)
target_link_libraries(Box2DTest Box2D Geometrie sfml-system sfml-graphics sfml-window -static-libgcc -static-libstdc++ -static -lpthread)

add_executable(CppParser CppParser.cpp)
target_link_libraries(CppParser libclang)