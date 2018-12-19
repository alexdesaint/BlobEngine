#include <vector>
#include <iostream>

#include <BlobEngine/BlobGL/ShaderProgram.hpp>
#include <BlobEngine/Reader/FileReader.hpp>
#include <BlobEngine/BlobException.hpp>

BlobEngine::BlobGL::ShaderProgram::ShaderProgram() {
	// Get a program object.
	program = glCreateProgram();
}

BlobEngine::BlobGL::ShaderProgram::ShaderProgram(const std::string &pathVertex, const std::string &pathFragment) {
	program = glCreateProgram();

	addVertexShaderFile(pathVertex);

	addFragmentShaderFile(pathFragment);

	linkShaders();
}

void BlobEngine::BlobGL::ShaderProgram::addVertexShader(const std::string &src) {

	// Create an empty vertex shader handle
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// Send the vertex shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	const GLchar *source = src.c_str();

	glShaderSource(vertexShader, 1, &source, nullptr);

	// Compile the vertex shader
	glCompileShader(vertexShader);

	GLint isCompiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(vertexShader);

		// Use the infoLog as you see fit.

		// In this simple program, we'll just leave

		throw BlobException(infoLog.data());
	}

	GLint maxLength = 0;

	glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

	if (maxLength != 0) {
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

		std::cout << "Shader compilation warning for shader :" << std::endl << source << std::endl << infoLog.data();
	}
}

void BlobEngine::BlobGL::ShaderProgram::addFragmentShader(const std::string &src) {
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Send the vertex shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	const GLchar *source = src.c_str();
	glShaderSource(fragmentShader, 1, &source, 0);

	// Compile the vertex shader
	glCompileShader(fragmentShader);

	GLint isCompiled = 0;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(fragmentShader);

		// Use the infoLog as you see fit.

		// In this simple program, we'll just leave

		throw BlobException(infoLog.data());
	}

	GLint maxLength = 0;

	glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

	if (maxLength != 0) {
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

		std::cout << "Shader compilation warning for shader :" << std::endl << source << std::endl << infoLog.data();
	}
}

void BlobEngine::BlobGL::ShaderProgram::linkShaders() {
	// Vertex and fragment shaders are successfully compiled.
	// Now time to link them together into a program.

	// Attach our shaders to our program
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	GLint maxLength = 0;
	glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);
	if (maxLength != 0) {
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

		std::cout << "Shader compilation warning for shader :" << std::endl << infoLog.data();
	}

	// Link our program
	glLinkProgram(program);

	// Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

		// We don't need the program anymore.
		glDeleteProgram(program);
		// Don't leak shaders either.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		throw BlobException(infoLog.data());
	}

	maxLength = 0;

	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

	if (maxLength != 0) {
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

		std::cout << "Shader linking warning :" << std::endl << infoLog.data();
	}

	// Always detach shaders after a successful link.
	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);

	model = glGetUniformLocation(program, "model");
	view = glGetUniformLocation(program, "view");
	projection = glGetUniformLocation(program, "projection");
}

GLuint BlobEngine::BlobGL::ShaderProgram::getProgram() const {
	return program;
}

void BlobEngine::BlobGL::ShaderProgram::addFragmentShaderFile(const std::string &path) {
	Reader::FileReader f(path);
	addFragmentShader(f.toString());
}

void BlobEngine::BlobGL::ShaderProgram::addVertexShaderFile(const std::string &path) {
	Reader::FileReader f(path);
	addVertexShader(f.toString());
}

