//
// Created by Muta on 21/06/2018.
//

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

		GLenum dataType;

		GLsizei typeSize;

		GLsizei dataSize;

		GLsizei numberOfElements;

	public:
		VertexBufferObject();

		void setData(GLubyte *points, int dataSize);

		~VertexBufferObject();

		void setData(const std::vector<GLfloat> &data);

		void setData(const std::vector<GLuint> &data);

		void setData(const std::vector<GLubyte> &data);

		void setData(const std::vector<glm::vec3> &data);

		void setData(const std::vector<glm::vec2> &data);
	};
}

#endif //BLOBENGINE_VERTEXBUFFEROBJECT_HPP
