#ifndef BLOBENGINE_VERTEXARRAY_HPP
#define BLOBENGINE_VERTEXARRAY_HPP

#include <BlobEngine/BlobGL/VertexBufferObject.hpp>

namespace BlobEngine::BlobGL {

	class VertexArrayObject {
	private:

		GLsizei numberOfElements;

		GLuint vertexArrayObject;

	public:
		GLuint getVertexArrayObject() const;

		GLsizei getNumberOfElements() const;

		VertexArrayObject();

		~VertexArrayObject();

		void addBuffer(const VertexBufferObject &vbo, GLuint numValuePerVertex, GLuint typeSize,
					   GLuint outPosition, GLenum dataType);

		//void addBuffer(const VertexBufferObject<GLubyte>&, GLuint indexPositoin, GLuint outPosition);

		//void addBuffer(const VertexBufferObject<glm::vec3>&, GLuint indexPositoin, GLuint outPosition);

		//void addBuffer(const VertexBufferObject<glm::vec2>&, GLuint indexPositoin, GLuint outPosition);

		//void addBuffer(const VertexBufferObject<BlobEngine::Color>&, GLuint indexPositoin, GLuint outPosition);

	};
}


#endif //BLOBENGINE_VERTEXARRAY_HPP
