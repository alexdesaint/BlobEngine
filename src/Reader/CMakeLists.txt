add_library(BlobFileReader FileReader.cpp)
target_include_directories(BlobFileReader PUBLIC ../../include)
add_library(Blob::FileReader ALIAS BlobFileReader)
