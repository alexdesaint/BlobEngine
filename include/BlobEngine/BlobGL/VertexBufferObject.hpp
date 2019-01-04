#ifndef BLOBENGINE_VERTEXBUFFEROBJECT_HPP
#define BLOBENGINE_VERTEXBUFFEROBJECT_HPP

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>

namespace BlobEngine::BlobGL {

	class VertexArrayObject;

	class VertexBufferObject {
		friend VertexArrayObject;
	private:
		GLuint vertexBufferObject;

		GLsizeiptr dataSize;

	public:
		VertexBufferObject();

		VertexBufferObject(GLubyte *data, GLsizeiptr dataSize);

		void setData(GLubyte *data, GLsizeiptr dataSize);

		~VertexBufferObject();
	};
}

#endif //BLOBENGINE_VERTEXBUFFEROBJECT_HPP
