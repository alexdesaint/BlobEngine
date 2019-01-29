#include <BlobEngine/BlobGL/VertexBufferObject.hpp>

#include <glad/glad.h>


namespace Blob::GL {

	VertexBufferObject::VertexBufferObject() {
		glCreateBuffers(1, &vertexBufferObject);
	}

	VertexBufferObject::VertexBufferObject(GLubyte *data, GLsizeiptr dataSize) {
		glCreateBuffers(1, &vertexBufferObject);

		setData(data, dataSize);
	}

	VertexBufferObject::~VertexBufferObject() {
		glDeleteBuffers(1, &vertexBufferObject);
	}

	void VertexBufferObject::setData(GLubyte *data, GLsizeiptr ds) {
		dataSize = ds;

		glNamedBufferStorage(vertexBufferObject, dataSize, data, 0);
	}

}