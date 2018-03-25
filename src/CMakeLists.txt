add_library(BlobException BlobException.cpp)

add_subdirectory(geometrie)
add_subdirectory(collision)

add_library(BlobEngine)
set_target_properties(BlobEngine PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(BlobEngine Collision Geometrie BlobException)
