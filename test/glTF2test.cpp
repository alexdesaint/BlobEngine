#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/glTF2/SceneManager.hpp>
#include <BlobEngine/BlobException.hpp>

#include <iostream>

int main(int argc, char *argv[]) {

	try {

		BlobEngine::BlobGL::Graphic graphic(640, 480);

		//BlobEngine::Renderable shape("../data/sphere.obj");

		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");
		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");
		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf");
		BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Box/glTF/Box.gltf");

		std::cout << sm;

		BlobEngine::glTF2::Scene &mainScene = sm.getScene(0);

		BlobEngine::glTF2::Shape &triangle1 = mainScene.getShape(0);
		//BlobEngine::glTF2::Shape &triangle2 = mainScene.getShape(1);

		BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		graphic.setCameraPosition(0, 0, 5);

		while (graphic.isOpen()) {
			graphic.clear();

			graphic.draw(triangle1, shaderProgram);
			//graphic.draw(triangle2, shaderProgram);

			graphic.display();
		}

	} catch (BlobException &exception) {
		std::cout << exception.what() << std::endl;
	}

	return 0;
}

