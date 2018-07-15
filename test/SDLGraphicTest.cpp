#include <BlobEngine/Graphic.hpp>
#include <BlobEngine/Shape.hpp>

#include <BlobEngine/Time.hpp>
#include <BlobEngine/BlobException.hpp>
#include <iostream>

int main(int argc, char *argv[]) {

	try {

		BlobEngine::Graphic graphic(640, 480);

		//BlobEngine::Shape shape("../data/sphere.obj");
		BlobEngine::Shape shape(
				"../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");

		shape.setVertexShaderProgram(R"(
#version 410

layout(location = 0) in vec3 vertex_position;
uniform mat4 mvp;
// use z position to shader darker to help perception of distance
out float dist;

void main() {
	gl_Position = mvp * vec4 (vertex_position, 1.0);
	dist = vertex_position.z;//1.0 - (-pos_eye.z / 10.0);
}

		)");

		shape.setFragmentShaderProgram(R"(
#version 410

in float dist;
out vec4 frag_colour;

void main() {
	frag_colour = vec4 (1.0, 0.0, 0.0, 1.0);
	// use z position to shader darker to help perception of distance
	frag_colour.xyz *= dist;
}
		)");

		shape.linkShaders();

		while (graphic.isOpen()) {
			graphic.clear();

			float angle = BlobEngine::getTime();

			float mod = std::cos(angle) / 2 + 1;

			shape.setScale(mod, mod, mod);
			shape.setRotation(angle * 40, 0.f, 1.f, 0.f);
			shape.rotate(angle * 40, 1.f, 0.f, 0.f);
			shape.setPosition(0, 1, 0);
			graphic.draw(shape);

			shape.setPosition(1, 0, 0);
			graphic.draw(shape);

			shape.setPosition(0, 0, 1);
			graphic.draw(shape);

			graphic.display();
		}
	} catch (BlobException &exception) {
		std::cout << exception.what() << std::endl;
	}

	return 0;
}
