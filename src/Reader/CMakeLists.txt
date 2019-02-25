add_library(BlobJsonExplorer JsonExplorer.cpp)
target_include_directories(BlobJsonExplorer PUBLIC ../../include)
add_library(Blob::JsonExplorer ALIAS BlobJsonExplorer)

add_library(BlobFileReader FileReader.cpp)
target_include_directories(BlobFileReader PUBLIC ../../include)
add_library(Blob::FileReader ALIAS BlobFileReader)
