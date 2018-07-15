add_subdirectory(glTF2)
add_subdirectory(BlobGL)

add_library(Graphic Graphic.cpp Shape.cpp)
target_link_libraries(Graphic BlobGL)
