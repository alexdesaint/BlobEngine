#include <Blob/GL/VertexBufferObject.hpp>

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

	void VertexBufferObject::setData(GLubyte *data, GLsizeiptr ds, bool dynamic) {
		if(targetSet) {
			glDeleteBuffers(1, &vertexBufferObject);
			glCreateBuffers(1, &vertexBufferObject);
		}
		dataSize = ds;

		if(dynamic)
			glNamedBufferStorage(vertexBufferObject, dataSize, data, GL_DYNAMIC_STORAGE_BIT);
		else
			glNamedBufferStorage(vertexBufferObject, dataSize, data, 0);

		targetSet = true;
	}

	void VertexBufferObject::setSubData(uint8_t *data, int64_t dataSize, int64_t offset) {
		glNamedBufferSubData(vertexBufferObject, offset, dataSize, data);
	}

	uint32_t VertexBufferObject::getVertexBufferObject() const {
		return vertexBufferObject;
	}
}