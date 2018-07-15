//
// Created by Muta on 20/06/2018.
//

#ifndef BLOBENGINE_SHADERPROGRAM_HPP
#define BLOBENGINE_SHADERPROGRAM_HPP

#include <string>
#include <glad/glad.h>

namespace BlobEngine::BlobGL {

	class ShaderProgram {
	private:
		GLuint program;

		GLuint vertexShader, fragmentShader;

	public:
		ShaderProgram();

		void addVertexShader(std::string src);

		void addFragmentShader(std::string src);

		void linkShaders();

		GLuint getProgram() const;
	};

}

#endif //BLOBENGINE_SHADERPROGRAM_HPP
