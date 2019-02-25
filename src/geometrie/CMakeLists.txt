add_library(BlobGeometrie Mat2.cpp Line.cpp Rectangle.cpp)
add_library(Blob::Geometrie ALIAS BlobGeometrie)
target_include_directories(BlobGeometrie PUBLIC ../../include)
