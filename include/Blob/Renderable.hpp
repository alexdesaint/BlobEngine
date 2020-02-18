#pragma once

#include <vector>
#include <string>

#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/Movable.hpp>

namespace Blob {

	class Renderable : public Movable { // TODO: rename "model", make fully a pubic object
		friend class Window;
	private:

		//TODO: move this in VAO and buffer it in VBO
		unsigned short *indices{};
		int32_t numOfIndices{};
		uint32_t indicesType{};

		bool indexed = false;

		GL::VertexArrayObject &vertexArrayObject;

		GL::ShaderProgram &shaderProgram;

		GL::Texture &texture;

        Blob::Vec2f textureScale = {1, 1}; // TODO: move this in texture ???????

	public:
		bool cullFace = true;
		bool depthTest = true;
		bool scissorTest = false;

		Renderable(GL::VertexArrayObject &vertexArrayObject, GL::ShaderProgram &shaderProgram, GL::Texture &texture);

		void setShaderProgram(GL::ShaderProgram &shaderProgram);

		void setTexture(GL::Texture &texture);

        void setVertexArrayObject(GL::VertexArrayObject &vertexArrayObject);

		void setIndices(unsigned short *indices, int32_t numOfIndices, uint32_t indicesType);

        void setTextureScale(const Vec2f &textureScale);
    };
}
