add_subdirectory(glTF2)
add_subdirectory(BlobGL)
add_subdirectory(Reader)

add_library(Graphic Shape.cpp)
target_link_libraries(Graphic BlobGL)
