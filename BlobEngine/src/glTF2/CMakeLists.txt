add_library(glTF2 SceneManager.cpp Asset.cpp Buffer.cpp BufferView.cpp Accessor.cpp Mesh.cpp Shape.cpp Scene.cpp)
target_include_directories(glTF2 PUBLIC ../../include)
