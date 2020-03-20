add_library(BlobGeometrie STATIC Mat2.cpp Line.cpp Rectangle.cpp ModelTransform.cpp ProjectionTransform.cpp ViewTransform.cpp)
target_link_libraries(BlobGeometrie glm)
add_library(Blob::Geometrie ALIAS BlobGeometrie)
target_include_directories(BlobGeometrie PUBLIC ../../include)
