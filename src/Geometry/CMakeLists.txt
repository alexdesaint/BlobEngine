add_library(BlobGeometryForms STATIC Line.cpp Rectangle.cpp Circle.cpp Point.cpp)
add_library(Blob::Geometry::Forms ALIAS BlobGeometryForms)
target_include_directories(BlobGeometryForms PUBLIC ../../include)
