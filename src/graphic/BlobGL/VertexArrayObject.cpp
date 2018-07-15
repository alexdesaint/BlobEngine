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

	void VertexArrayObject::addBuffer(const VertexBufferObject &vbo, GLint numValuePerVertex, GLuint indexPositoin,
									  GLuint outPosition) {
		if (vbo.dataSize % numValuePerVertex != 0)
			throw BlobException("incorrect number of value par vertex");

		//ajoute le buffer au VAO et donne la taille des vecteurs
		glVertexArrayVertexBuffer(vertexArrayObject, indexPositoin, vbo.vertexBufferObject, 0,
								  numValuePerVertex * (GLuint) vbo.typeSize);

		//autorique l'utilisation de cet atribut
		glEnableVertexArrayAttrib(vertexArrayObject, outPosition);

		//définit le format de l'atribut
		glVertexArrayAttribFormat(vertexArrayObject, outPosition, numValuePerVertex, vbo.dataType, GL_FALSE, 0);

		//lie l'attribu avec le buffer
		glVertexArrayAttribBinding(vertexArrayObject, outPosition, indexPositoin);
	}
}