message("Blob Test are enable")

add_executable(TestglTF2 TestglTF2.cpp)
target_link_libraries(TestglTF2 Blob Blob::glTF2)

add_executable(TestImGUI TestImGUI.cpp)
target_link_libraries(TestImGUI Blob)# -static -static-libgcc -static-libstdc++ -lpthread)

add_executable(TestWindowCore TestWindowCore.cpp)
target_link_libraries(TestWindowCore Blob)

add_executable(TestColor TestColor.cpp)
target_link_libraries(TestColor Blob)

add_executable(TestShapes TestShapes.cpp)
target_link_libraries(TestShapes Blob)

add_executable(TestShaders TestShaders.cpp)
target_link_libraries(TestShaders Blob)

#STATIC : -lmingw32 SDL2main SDL2-static
#STATIC : -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid

add_subdirectory(GL)
add_subdirectory(VK)
add_subdirectory(Maths)
add_subdirectory(Collision)
