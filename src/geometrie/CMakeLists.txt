add_library(Mat2 Mat2.cpp)

add_library(Line Line.cpp)

add_library(Geometrie)
set_target_properties(Geometrie PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Geometrie Mat2 Line)
