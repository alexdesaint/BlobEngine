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

		uint8_t *indices{};
		int32_t numOfIndices{};
		uint32_t indicesType{};

		bool indexed = false;

		VertexArrayObject vao;

		Texture *texture = nullptr;
	public:

		//explicit Renderable(const std::string &file);

		//Renderable(const std::vector<glm::vec3> &points, const std::vector<GLushort> &indices);

		void setBuffer(VertexBufferObject &vbo, int32_t stride, uint32_t dataOffset = 0);

		void setTexture(Texture &t);

		void setTexturePositionVAO(uint32_t valuePerVector, uint32_t dataType, uint32_t arrayOffset);

		void setPositionVAO(uint32_t valuePerVector, uint32_t dataType, uint32_t arrayOffset);

		void setNormalVAO(uint32_t valuePerVector, uint32_t dataType, uint32_t arrayOffset);

		void setIndices(uint8_t *indices, int32_t numOfIndices, uint32_t indicesType);

		const VertexArrayObject &getVao() const;
	};
}

#endif //BLOBENGINE_RENDERABLE_HPP
