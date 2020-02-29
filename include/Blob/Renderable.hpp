#pragma once

#include <vector>
#include <string>

#include <Blob/GL/VertexArrayObject.hpp>
//#include <Blob/GL/VertexBufferObject.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/Movable.hpp>
#include <Blob/RenderOptions.hpp>

namespace Blob {

	class Renderable : public Movable { // TODO: rename as "Model", make fully a pubic object
		friend class Window;

	private:
		GL::VertexArrayObject &vertexArrayObject;

		GL::ShaderProgram &shaderProgram;

		GL::Texture &texture;

	public:
		RenderOptions renderOptions;

		Renderable(GL::VertexArrayObject &vertexArrayObject, GL::ShaderProgram &shaderProgram, GL::Texture &texture);

		void setShaderProgram(GL::ShaderProgram &shaderProgram);

		void setTexture(GL::Texture &texture);

		void setVertexArrayObject(GL::VertexArrayObject &vertexArrayObject);

		void setIndices(unsigned short *indices, int32_t numOfIndices, uint32_t indicesType);
    };
}
