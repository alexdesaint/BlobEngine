add_library(BlobCollision STATIC Circle.cpp Line.cpp Point.cpp Rectangle.cpp)
target_link_libraries(BlobCollision Blob::Includes)
add_library(Blob::Collision ALIAS BlobCollision)
