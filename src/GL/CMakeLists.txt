add_library(BlobGL STATIC
		Core.cpp
		FrameBufferObject.cpp
		ShaderProgram.cpp
		Texture.cpp
		VertexArrayObject.cpp
		VertexBufferObject.cpp
		)

target_link_libraries(BlobGL glad ${OPENGL_gl_LIBRARY} stb glfw)
target_include_directories(BlobGL PUBLIC ../../include)
add_library(Blob::GL ALIAS BlobGL)
