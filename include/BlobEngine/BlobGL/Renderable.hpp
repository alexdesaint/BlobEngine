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
	private:

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

		void setTexturePositionVAO(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset);

		void setPositionVAO(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset);

		void setNormalVAO(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset);

		void setIndices(GLubyte *indices, GLsizei numOfIndices, GLenum indicesType);

		const VertexArrayObject &getVao() const;
	};
}

#endif //BLOBENGINE_RENDERABLE_HPP
