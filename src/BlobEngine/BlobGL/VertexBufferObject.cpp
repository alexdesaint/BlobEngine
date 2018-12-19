#include <BlobEngine/BlobGL/VertexBufferObject.hpp>

#include <BlobEngine/BlobException.hpp>


namespace BlobEngine::BlobGL {

	VertexBufferObject::VertexBufferObject() {
		glCreateBuffers(1, &vertexBufferObject);
	}

	VertexBufferObject::~VertexBufferObject() {
		glDeleteBuffers(1, &vertexBufferObject);
	}

	void VertexBufferObject::setData(GLubyte *data, GLsizeiptr ds) {
		dataSize = ds;

		glNamedBufferStorage(vertexBufferObject, dataSize, data, 0);
	}
}