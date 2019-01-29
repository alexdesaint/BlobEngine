add_executable(CollisionTest CollisionTest.cpp)
target_link_libraries(CollisionTest Collision BlobGL)

add_executable(glTF2test glTF2test.cpp)
target_link_libraries(glTF2test glTF2 BlobGL glad FileReader JsonExplorer -lglu32 -lopengl32 ${SDL2_LIBRARIES})

add_executable(BlobGLtest BlobGLtest.cpp test.cpp)
target_link_libraries(BlobGLtest BlobGL -static -static-libgcc -static-libstdc++ -lpthread)

add_executable(imguiTest imguiTest.cpp)
target_link_libraries(imguiTest BlobGL imgui -static -static-libgcc -static-libstdc++ -lpthread)

#STATIC : -lmingw32 SDL2main SDL2-static
#STATIC : -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid
