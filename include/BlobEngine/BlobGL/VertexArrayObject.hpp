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

		void setBuffer(const VertexBufferObject &vbo, GLsizei stride);

		void setArray(GLuint numValuePerArray, GLuint outPosition, GLenum dataType,
					  GLuint arrayOffset, GLuint dataOffset);

	};
}


#endif //BLOBENGINE_VERTEXARRAY_HPP
