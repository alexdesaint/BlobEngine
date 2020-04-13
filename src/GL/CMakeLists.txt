add_library(BlobGL STATIC
		Core.cpp
		FrameBufferObject.cpp
		ShaderProgram.cpp
		Texture.cpp
		VertexArrayObject.cpp
		VertexBufferObject.cpp
		)

target_link_libraries(BlobGL Blob::FileReader glad ${OPENGL_gl_LIBRARY} glfw libs) #TODO remove libs and let tinygltf handle texture
target_include_directories(BlobGL PUBLIC ../../include)
add_library(Blob::GL ALIAS BlobGL)
