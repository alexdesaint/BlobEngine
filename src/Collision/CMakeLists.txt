add_library(BlobCollision STATIC Circle.cpp Line.cpp Point.cpp Rectangle.cpp)
add_library(Blob::Collision ALIAS BlobCollision)
target_include_directories(BlobCollision PUBLIC ${INCLUDE_FOLDER})
