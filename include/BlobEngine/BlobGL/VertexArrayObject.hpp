#ifndef BLOBENGINE_VERTEXARRAY_HPP
#define BLOBENGINE_VERTEXARRAY_HPP

#include <vector>

#include <glad/glad.h>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <BlobEngine/Color.hpp>

#include "VertexBufferObject.hpp"

namespace BlobEngine::BlobGL {

	class VertexArrayObject {
	private:

		unsigned int size;

		GLuint vertexArrayObject;

	public:
		GLuint getVertexArrayObject() const;

		VertexArrayObject();

		~VertexArrayObject();

		void addBuffer(const VertexBufferObject &vbo, GLint numValuePerVertex, GLuint indexPositoin,
					   GLuint outPosition);

		//void addBuffer(const VertexBufferObject<GLubyte>&, GLuint indexPositoin, GLuint outPosition);

		//void addBuffer(const VertexBufferObject<glm::vec3>&, GLuint indexPositoin, GLuint outPosition);

		//void addBuffer(const VertexBufferObject<glm::vec2>&, GLuint indexPositoin, GLuint outPosition);

		//void addBuffer(const VertexBufferObject<BlobEngine::Color>&, GLuint indexPositoin, GLuint outPosition);

	};
}


#endif //BLOBENGINE_VERTEXARRAY_HPP
