add_library(BlobCoreRenderOptions STATIC RenderOptions.cpp)
target_link_libraries(BlobCoreRenderOptions Blob::GL)
target_include_directories(BlobCoreRenderOptions PUBLIC ../../include)
add_library(Blob::Core::RenderOptions ALIAS BlobCoreRenderOptions)
