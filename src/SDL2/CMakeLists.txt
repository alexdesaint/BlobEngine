add_library(BlobSDL2 STATIC Window.cpp Controls.cpp)
target_link_libraries(BlobSDL2 LINK_PUBLIC  Blob::Includes SDL2::SDL2main SDL2::SDL2-static)
