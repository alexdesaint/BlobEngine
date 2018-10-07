#include <BlobEngine/BlobGL/VertexBufferObject.hpp>

#include <BlobEngine/BlobException.hpp>


namespace BlobEngine::BlobGL {

	VertexBufferObject::VertexBufferObject() {
		glCreateBuffers(1, &vertexBufferObject);
	}

	VertexBufferObject::~VertexBufferObject() {
		glDeleteBuffers(1, &vertexBufferObject);
	}

	void VertexBufferObject::setData(const std::vector<GLfloat> &data) {
		typeSize = sizeof(GLfloat);
		dataSize = data.size();
		dataType = GL_FLOAT;

		glNamedBufferStorage(vertexBufferObject, typeSize * dataSize, data.data(), 0);
	}

	void VertexBufferObject::setData(const std::vector<GLuint> &data) {
		typeSize = sizeof(GLuint);
		dataSize = data.size();
		dataType = GL_UNSIGNED_INT;

		glNamedBufferStorage(vertexBufferObject, typeSize * dataSize, data.data(), 0);
	}

	void VertexBufferObject::setData(const std::vector<GLubyte> &data) {
		typeSize = sizeof(GLubyte);
		dataSize = data.size();
		dataType = GL_UNSIGNED_BYTE;

		glNamedBufferStorage(vertexBufferObject, typeSize * dataSize, data.data(), 0);

		//TODO ajouter la taille du buffer à ajouter et l'offset
	}

	void VertexBufferObject::setData(const std::vector<glm::vec3> &data) {
		typeSize = sizeof(GLfloat);
		dataSize = data.size() * 3;
		dataType = GL_FLOAT;

		glNamedBufferStorage(vertexBufferObject, typeSize * dataSize, data.data(), 0);
	}

	void VertexBufferObject::setData(const std::vector<glm::vec2> &data) {
		typeSize = sizeof(GLfloat);
		dataSize = data.size() * 2;
		dataType = GL_FLOAT;

		glNamedBufferStorage(vertexBufferObject, typeSize * dataSize, data.data(), 0);
	}
}