#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <BlobEngine/BlobException.hpp>

namespace BlobEngine::BlobGL {

	VertexArrayObject::VertexArrayObject() {
		glCreateVertexArrays(1, &vertexArrayObject);
	}

	VertexArrayObject::~VertexArrayObject() {
			glDeleteVertexArrays(1, &vertexArrayObject);
	}

	GLuint VertexArrayObject::getVertexArrayObject() const {
		return vertexArrayObject;
	}

	void VertexArrayObject::addBuffer(const VertexBufferObject &vbo, GLuint numValuePerVertex, GLuint typeSize,
									  GLuint outPosition, GLenum dataType) {

		numberOfElements = numValuePerVertex;

		//ajoute le buffer au VAO et donne la taille des vecteurs
		glVertexArrayVertexBuffer(vertexArrayObject, 0, vbo.vertexBufferObject, 0,
								  numValuePerVertex * (GLuint) typeSize);

		//autorique l'utilisation de cet atribut
		glEnableVertexArrayAttrib(vertexArrayObject, outPosition);

		//définit le format de l'atribut
		glVertexArrayAttribFormat(vertexArrayObject, outPosition, numValuePerVertex, dataType, GL_FALSE, 0);

		//lie l'attribu avec le buffer
		glVertexArrayAttribBinding(vertexArrayObject, outPosition, 0);
	}

	GLsizei VertexArrayObject::getNumberOfElements() const {
		return numberOfElements;
	}
}