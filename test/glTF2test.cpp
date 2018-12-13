#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/glTF2/SceneManager.hpp>
#include <BlobEngine/BlobException.hpp>

#include <iostream>

int main(int argc, char *argv[]) {

	try {

		//BlobEngine::BlobGL::Graphic graphic(640, 480);

		//BlobEngine::Shape shape("../data/sphere.obj");
		//BlobEngine::Shape shape("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");

		BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");

		std::cout << sm;

		/*BlobEngine::glTF2::Scene &mainScene = sm.getScene(0);

		BlobEngine::glTF2::Shape &triangle = mainScene.getShape(0);

		BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		while (graphic.isOpen()) {
			graphic.clear();

			graphic.draw(shaderProgram, triangle.mesh.getVAO());

			graphic.display();
		}
*/
	} catch (BlobException &exception) {
		std::cout << exception.what() << std::endl;
	}

	return 0;
}

