#ifndef BLOBENGINE_SHADERPROGRAM_HPP
#define BLOBENGINE_SHADERPROGRAM_HPP

#include <string>

namespace BlobEngine::BlobGL {

	class Graphic;

	class ShaderProgram {
		friend Graphic;
	private:
		unsigned int program;

		unsigned int vertexShader, fragmentShader;

		int model, view, projection;

	public:
		ShaderProgram();

		ShaderProgram(const std::string &pathVertex, const std::string &pathFragment);

		void addVertexShader(const std::string &src);

		void addVertexShaderFile(const std::string &path);

		void addFragmentShader(const std::string &src);

		void addFragmentShaderFile(const std::string &path);

		void linkShaders();

		unsigned int getProgram() const;

		int getPosition(std::string name);
	};

}

#endif //BLOBENGINE_SHADERPROGRAM_HPP
