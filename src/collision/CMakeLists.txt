add_library(BlobCollision CollisionDetector.cpp)
add_library(Blob::Collision ALIAS BlobCollision)
target_link_libraries(BlobCollision Geometrie)
target_include_directories(BlobCollision PUBLIC ../../include)
