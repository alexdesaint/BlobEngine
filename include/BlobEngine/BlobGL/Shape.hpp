#ifndef BLOBENGINE_SHAPE_HPP
#define BLOBENGINE_SHAPE_HPP

#include <vector>
#include <string>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include <BlobEngine/Color.hpp>
#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <BlobEngine/BlobGL/VertexBufferObject.hpp>
#include <BlobEngine/BlobGL/ShaderProgram.hpp>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Renderable {
		friend Graphic;
	protected:

		glm::mat4 translateMatrix = glm::mat4(1.f);
		glm::mat4 rotateMatrix = glm::mat4(1.f);
		glm::mat4 scaleMatrix = glm::mat4(1.f);

		GLubyte *indices{};
		GLsizei numOfIndices{};
		GLenum indicesType{};

		bool indexed = false;

		VertexBufferObject vboPoints;
		VertexArrayObject vao;

		//VertexBufferObject vboColor;

		void loadObjFile(const std::string &file);

	public:

		Renderable() = default;

		explicit Renderable(const std::string &file);

		//Renderable(const std::vector<glm::vec3> &points, const std::vector<GLushort> &indices);

		void setData(GLubyte *points, GLsizei numOfPoints, GLenum type, GLsizei valuePerPoint);

		void setIndices(GLubyte *indices, GLsizei numOfIndices, GLenum indicesType);

		void setPosition(float x, float y, float z);

		void move(float x, float y, float z);

		void setRotation(float r, float x, float y, float z);

		void rotate(float r, float x, float y, float z);

		void setScale(float x, float y, float z);

		void rescale(float x, float y, float z);

		glm::mat4 getModelMatrix() const;
	};
}

#endif //BLOBENGINE_SHAPE_HPP
