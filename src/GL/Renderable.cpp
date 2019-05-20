#include <Blob/GL/Renderable.hpp>

#include <Blob/Reader/FileReader.hpp>
#include <Blob/Exception.hpp>

#include <glad/glad.h>


using namespace std;

namespace Blob::GL {

    void Renderable::setBuffer(VertexBufferObject &vbo, GLsizei stride, GLuint dataOffset, uint32_t pos) {
        vao.setBuffer(vbo, stride, dataOffset, pos);
	}

	void Renderable::setTexture(Texture &t) {
		texture = &t;
	}

    void Renderable::setArrayVAO(uint32_t valuePerVector, const char *name, uint32_t dataType,
                                 uint32_t relativeOffset, bool normalized, uint32_t pos) {
		if(shaderProgram == nullptr)
			throw Exception("Error in Renderable : Can't set Array in VAO if no Shader is set");

        vao.setArray(valuePerVector, shaderProgram->getAttribLocation(name), dataType, relativeOffset, normalized, pos);
    }

    void Renderable::setBufferIndices(VertexBufferObject &vbo) {
        vao.setIndicesBuffer(vbo);
	}

	void Renderable::setIndices(unsigned short *i, int32_t noi, uint32_t it) {
		indices = i;
		indicesType = it;
		numOfIndices = noi;

		indexed = true;
	}

	const VertexArrayObject &Renderable::getVao() const {
		return vao;
	}

	void Renderable::setShaderProgram(ShaderProgram &shaderProgram) {
		Renderable::shaderProgram = &shaderProgram;
	}

    const Vec2f &Renderable::getTextureScale() const {
        return textureScale;
    }

    void Renderable::setTextureScale(const Vec2f &textureScale) {
        Renderable::textureScale = textureScale;
    }

}