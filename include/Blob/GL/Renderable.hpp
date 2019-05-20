#ifndef BLOBENGINE_RENDERABLE_HPP
#define BLOBENGINE_RENDERABLE_HPP

#include <vector>
#include <string>

#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/GL/Movable.hpp>

namespace Blob::GL {

	class Renderable : public Movable {
		friend class Graphic;
	private:

		//TODO: create a subclass for the index
		unsigned short *indices{};
		int32_t numOfIndices{};
		uint32_t indicesType{};

		bool indexed = false;

		VertexArrayObject vao;

		ShaderProgram *shaderProgram = nullptr;

		Texture *texture = nullptr;

        Blob::Vec2f textureScale = {1, 1};

	public:
		bool cullFace = true;
		bool depthTest = true;
		bool scissorTest = false;

		void setShaderProgram(ShaderProgram &shaderProgram);

        void setBuffer(VertexBufferObject &vbo, int32_t stride, uint32_t dataOffset = 0, uint32_t pos = 0);

		void setTexture(Texture &t);

        void setArrayVAO(uint32_t valuePerVector, const char *name, uint32_t dataType,
                         uint32_t relativeOffset, bool normalized = false, uint32_t pos = 0);

        void setBufferIndices(VertexBufferObject &vbo);

		void setIndices(unsigned short *indices, int32_t numOfIndices, uint32_t indicesType);

		const VertexArrayObject &getVao() const;

        const Vec2f &getTextureScale() const;

        void setTextureScale(const Vec2f &textureScale);
    };
}

#endif //BLOBENGINE_RENDERABLE_HPP
