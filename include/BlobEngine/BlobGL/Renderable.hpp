#ifndef BLOBENGINE_RENDERABLE_HPP
#define BLOBENGINE_RENDERABLE_HPP

#include <vector>
#include <string>

#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <BlobEngine/BlobGL/VertexBufferObject.hpp>
#include <BlobEngine/BlobGL/ShaderProgram.hpp>
#include <BlobEngine/BlobGL/Texture.hpp>
#include <BlobEngine/BlobGL/Movable.hpp>

namespace Blob::GL {

	class Graphic;

	class Renderable : public Movable {
		friend Graphic;
	private:

		unsigned short *indices{};
		int32_t numOfIndices{};
		uint32_t indicesType{};

		bool indexed = false;

		VertexArrayObject vao;

		ShaderProgram *shaderProgram = nullptr;

		Texture *texture = nullptr;
	public:

		void setShaderProgram(ShaderProgram *shaderProgram);

		void setBuffer(VertexBufferObject &vbo, int32_t stride, uint32_t dataOffset = 0);

		void setTexture(Texture &t);

		void setArrayVAO(uint32_t valuePerVector, const char *name, uint32_t dataType, uint32_t arrayOffset, bool normalized = false);

		void setIndices(unsigned short *indices, int32_t numOfIndices, uint32_t indicesType);

		const VertexArrayObject &getVao() const;
	};
}

#endif //BLOBENGINE_RENDERABLE_HPP
