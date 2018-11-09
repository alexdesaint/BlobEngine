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

namespace BlobEngine {

	using namespace BlobGL;

	class Graphic;

	class Shape {
		friend Graphic;
	private:

		std::vector<glm::vec3> points;
		std::vector<glm::vec2> textCoords;
		std::vector<glm::vec3> normals;

		//VertexArrayObject vao;

		glm::mat4 translateMatrix = glm::mat4(1.f);
		glm::mat4 rotateMatrix = glm::mat4(1.f);
		glm::mat4 scaleMatrix = glm::mat4(1.f);

		//VertexBufferObject vboPoints;
		//VertexBufferObject vboColor;

		ShaderProgram shaderProgram;

		GLint mvpLocation{};

		//void loadObjFile(std::string file);

		//void loadglTF(const std::string &file);

	public:

		//explicit Shape(std::string file);

		void setVertexShaderProgram(const std::string &src) {
			shaderProgram.addVertexShader(src);
		}

		void setFragmentShaderProgram(const std::string &src) {
			shaderProgram.addFragmentShader(src);
		}

		void linkShaders();

		void setPosition(float x, float y, float z);

		void move(float x, float y, float z);

		void setRotation(float r, float x, float y, float z);

		void rotate(float r, float x, float y, float z);

		void setScale(float x, float y, float z);

		void rescale(float x, float y, float z);

		glm::mat4 getModelMatrix();
	};
}

#endif //BLOBENGINE_SHAPE_HPP
