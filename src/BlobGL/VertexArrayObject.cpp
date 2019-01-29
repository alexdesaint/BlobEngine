#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <glad/glad.h>


namespace Blob::GL {

	VertexArrayObject::VertexArrayObject() {
		glCreateVertexArrays(1, &vertexArrayObject);
	}

	VertexArrayObject::~VertexArrayObject() {
		glDeleteVertexArrays(1, &vertexArrayObject);
	}

	GLuint VertexArrayObject::getVertexArrayObject() const {
		return vertexArrayObject;
	}

	void VertexArrayObject::setBuffer(const VertexBufferObject &vbo, GLsizei stride, GLuint dataOffset) {

		//ajoute le buffer au VAO et donne la taille des vecteurs
		glVertexArrayVertexBuffer(vertexArrayObject, 0, vbo.vertexBufferObject, dataOffset, stride);
	}

	GLsizei VertexArrayObject::getNumberOfElements() const {
		return numberOfElements;
	}

	void VertexArrayObject::setArray(GLuint numValuePerArray, GLuint outPosition, GLenum dataType,
									 GLuint arrayOffset) {
		numberOfElements = 3;

		//autorique l'utilisation de cet atribut
		glEnableVertexArrayAttrib(vertexArrayObject, outPosition);

		//définit le format de l'atribut
		glVertexArrayAttribFormat(vertexArrayObject, outPosition, numValuePerArray, dataType, GL_FALSE, arrayOffset);

		//lie l'attribu avec le buffer
		glVertexArrayAttribBinding(vertexArrayObject, outPosition, 0);
	}
}