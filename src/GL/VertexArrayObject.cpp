#include <Blob/GL/VertexArrayObject.hpp>
#include <glad/glad.h>
#include <Blob/Exception.hpp>


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

    void VertexArrayObject::setBuffer(const VertexBufferObject &vbo, GLsizei stride, GLuint dataOffset, uint32_t pos) {

		//ajoute le buffer au VAO et donne la taille des vecteurs
        glVertexArrayVertexBuffer(vertexArrayObject, pos, vbo.getVertexBufferObject(), dataOffset, stride);
	}

	void VertexArrayObject::setIndicesBuffer(const VertexBufferObject &vbo) {
        glVertexArrayElementBuffer(vertexArrayObject, vbo.getVertexBufferObject());
	}

	void VertexArrayObject::setArray(GLuint numValuePerArray, GLuint outPosition, GLenum dataType,
                                     GLuint relativeOffset, bool normalized, uint32_t pos) {

        //autorise l'utilisation de cet atribut
		glEnableVertexArrayAttrib(vertexArrayObject, outPosition);

		//définit le format de l'atribut
		glVertexArrayAttribFormat(vertexArrayObject, outPosition, numValuePerArray, dataType,
                                  static_cast<GLboolean>(normalized), relativeOffset);

		//lie l'attribu avec le buffer
        glVertexArrayAttribBinding(vertexArrayObject, outPosition, pos);
	}

	template<class C, typename T>
	void VertexArrayObject::setArray() {
		auto offset = ((uint32_t)&reinterpret_cast<char const volatile&>((((C*)0)->T)));
		GLuint numValuePerArray = sizeof(T) / sizeof(array[0]);
	}
}
