#ifndef BLOBENGINE_RENDERABLE_HPP
#define BLOBENGINE_RENDERABLE_HPP

#include <vector>
#include <string>

#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <BlobEngine/BlobGL/VertexBufferObject.hpp>
#include <BlobEngine/BlobGL/ShaderProgram.hpp>
#include <BlobEngine/BlobGL/Texture.hpp>
#include <BlobEngine/BlobGL/Movable.hpp>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Renderable : public Movable {
		friend Graphic;
	protected:

		GLubyte *indices{};
		GLsizei numOfIndices{};
		GLenum indicesType{};

		bool indexed = false;

		VertexArrayObject vao;

		Texture *texture = nullptr;
	public:

		//explicit Renderable(const std::string &file);

		//Renderable(const std::vector<glm::vec3> &points, const std::vector<GLushort> &indices);

		void setBuffer(VertexBufferObject &vbo, GLsizei stride, GLuint dataOffset = 0);

		void setTexture(Texture &t);

		void setTexture(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset);

		void setPosition(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset);

		void setNormal(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset);

		void setIndices(GLubyte *indices, GLsizei numOfIndices, GLenum indicesType);

	};
}

#endif //BLOBENGINE_RENDERABLE_HPP
