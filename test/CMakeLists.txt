message(WARNING "Test are enable")

add_executable(TestCollision TestCollision.cpp)
target_link_libraries(TestCollision Blob::Collision Blob::GL)
target_compile_definitions(TestCollision PUBLIC TEST)

add_executable(TestglTF2 TestglTF2.cpp)
target_link_libraries(TestglTF2 Blob::glTF2)

add_executable(TestGL TestGL.cpp)
target_link_libraries(TestGL BlobGL)# -static -static-libgcc -static-libstdc++ -lpthread)

add_executable(TestImGUI TestImGUI.cpp)
target_link_libraries(TestImGUI BlobGL)# -static -static-libgcc -static-libstdc++ -lpthread)

add_executable(Testentt Testentt.cpp)
target_link_libraries(Testentt BlobGL)

#STATIC : -lmingw32 SDL2main SDL2-static
#STATIC : -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid

if (BLOBVK)
    add_subdirectory(VK)
endif ()