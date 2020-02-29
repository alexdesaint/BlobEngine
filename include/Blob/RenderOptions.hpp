#pragma once

#include <Blob/Geometrie.hpp>

namespace Blob {
	struct RenderOptions {
		bool cullFace = true;
		bool depthTest = true;
		bool scissorTest = false;

		// Texture options
		Blob::Vec2f textureScale = {1, 1};

		// IndicesOptions
		bool indexed = false;

		// Index options
		unsigned short *indices = nullptr;
		int32_t numOfIndices = 0;
		uint32_t indicesType = 0;

		// direct draw options
		int32_t elementOffset = 0, numOfElements = 0;
	};
}
