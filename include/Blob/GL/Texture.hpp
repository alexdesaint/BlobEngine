#ifndef BLOBENGINE_TEXTURE_HPP
#define BLOBENGINE_TEXTURE_HPP

#include <string>
#include <Blob/Geometrie.hpp>

namespace Blob::GL {

	class Window;

	class Texture {
		friend Window;
	private:

		unsigned int texture = -1; // the opengl texture

		int height = 0, width = 0, bitPerPixel = 0;//images data

		bool depth = false, textureLoaded = false;

		void init();
	public:
		Texture() = default;

		explicit Texture(const std::string &path, bool nearest = false);

		Texture(uint8_t r, uint8_t g, uint8_t b);

        Texture(const Texture &) = delete;

        ~Texture();

		void loadBMP(const std::string &path, bool nearest = false);

		void setColor(uint8_t r, uint8_t g, uint8_t b);

        void setImage(const std::string &path);

		void setRGBA32data(uint8_t *pixels, unsigned int width, unsigned int height, bool nearest = false);

		unsigned int getTextureID() const;

		Vec2f getTextureSize() const;
	};
}

#endif
