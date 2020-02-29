#include <Blob/Renderable.hpp>

#include <Blob/Reader/FileReader.hpp>
#include <Blob/Exception.hpp>

#include <glad/glad.h>


using namespace std;

namespace Blob {

	using namespace GL;

    Renderable::Renderable(VertexArrayObject &vertexArrayObject, ShaderProgram &shaderProgram, Texture &texture) :
            texture(texture), vertexArrayObject(vertexArrayObject), shaderProgram(shaderProgram){
    }

	void Renderable::setTexture(Texture &t) {
		texture = t;
	}

    void Renderable::setShaderProgram(ShaderProgram &shaderProgram) {
        Renderable::shaderProgram = shaderProgram;
    }

    void Renderable::setVertexArrayObject(VertexArrayObject &vertexArrayObject) {
        Renderable::vertexArrayObject = vertexArrayObject;
    }

	void Renderable::setIndices(unsigned short *i, int32_t noi, uint32_t it) {
		renderOptions.indices = i;
		renderOptions.indicesType = it;
		renderOptions.numOfIndices = noi;

		renderOptions.indexed = true;
	}
}
