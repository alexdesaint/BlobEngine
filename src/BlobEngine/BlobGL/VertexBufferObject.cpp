#include <BlobEngine/BlobGL/VertexBufferObject.hpp>

#include <BlobEngine/BlobException.hpp>


namespace BlobEngine::BlobGL {

	VertexBufferObject::VertexBufferObject() {
		glCreateBuffers(1, &vertexBufferObject);
	}

	VertexBufferObject::~VertexBufferObject() {
		glDeleteBuffers(1, &vertexBufferObject);
	}

	VertexBufferObject::VertexBufferObject(GLubyte *points, GLsizei dataSize) : dataSize(dataSize) {
		glCreateBuffers(1, &vertexBufferObject);

		glNamedBufferStorage(vertexBufferObject, dataSize, points, 0);
	}

	void VertexBufferObject::setData(const std::vector<GLfloat> &data) {
		typeSize = sizeof(GLfloat);
		dataSize = (GLsizei)data.size() * typeSize;
		dataType = GL_FLOAT;

		glNamedBufferStorage(vertexBufferObject, dataSize, data.data(), 0);
	}

	void VertexBufferObject::setData(const std::vector<GLuint> &data) {
		typeSize = sizeof(GLuint);
		dataSize = (GLsizei)data.size() * typeSize;
		dataType = GL_UNSIGNED_INT;

		glNamedBufferStorage(vertexBufferObject, dataSize, data.data(), 0);
	}

	void VertexBufferObject::setData(const std::vector<GLubyte> &data) {
		typeSize = sizeof(GLubyte);
		dataSize = (GLsizei)data.size() * typeSize;
		dataType = GL_UNSIGNED_BYTE;

		glNamedBufferStorage(vertexBufferObject, dataSize, data.data(), 0);

		//TODO ajouter l'offset
	}

	void VertexBufferObject::setData(const std::vector<glm::vec3> &data) {
		typeSize = sizeof(GLfloat);
		dataSize = (GLsizei)data.size() * 3 * typeSize;
		dataType = GL_FLOAT;
		numberOfElements = (GLsizei)data.size();

		glNamedBufferStorage(vertexBufferObject, dataSize, data.data(), 0);
	}

	void VertexBufferObject::setData(const std::vector<glm::vec2> &data) {
		typeSize = sizeof(GLfloat);
		dataSize = (GLsizei)data.size() * 2 * typeSize;
		dataType = GL_FLOAT;

		glNamedBufferStorage(vertexBufferObject, dataSize, data.data(), 0);
	}
}