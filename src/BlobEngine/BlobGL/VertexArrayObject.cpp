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
									  GLuint outPosition, GLenum dataType) {

		switch (dataType) {
			case GL_BYTE:
				typeSize = sizeof(GLbyte);

				break;
			case GL_UNSIGNED_BYTE:
				typeSize = sizeof(GLubyte);
				break;
			case GL_SHORT:
				typeSize = sizeof(GLshort);
				break;
			case GL_UNSIGNED_SHORT:
				typeSize = sizeof(GLushort);
				break;
			case GL_UNSIGNED_INT:
				typeSize = sizeof(GLuint);
				break;
			case GL_FLOAT:
				typeSize = sizeof(GLfloat);
				break;
			default:
				typeSize = vbo.typeSize;
				dataType = vbo.dataType;
				break;
		}

		numberOfElements = vbo.dataSize / ((GLsizei)numValuePerVertex * typeSize);

		if (vbo.dataSize % (numValuePerVertex * typeSize) != 0)
			throw BlobException("incorrect number of value par vertex");

		//ajoute le buffer au VAO et donne la taille des vecteurs
		glVertexArrayVertexBuffer(vertexArrayObject, indexPositoin, vbo.vertexBufferObject, 0,
								  numValuePerVertex * (GLuint) typeSize);

		//autorique l'utilisation de cet atribut
		glEnableVertexArrayAttrib(vertexArrayObject, outPosition);

		//définit le format de l'atribut
		glVertexArrayAttribFormat(vertexArrayObject, outPosition, numValuePerVertex, dataType, GL_FALSE, 0);

		//lie l'attribu avec le buffer
		glVertexArrayAttribBinding(vertexArrayObject, outPosition, indexPositoin);
	}

	GLsizei VertexArrayObject::getNumberOfElements() const {
		return numberOfElements;
	}
}