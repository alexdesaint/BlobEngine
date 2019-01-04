#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/glTF2/SceneManager.hpp>
#include <BlobEngine/BlobException.hpp>

#include <iostream>
#include <BlobEngine/Time.hpp>

#define TEST2

int main(int argc, char *argv[]) {

#ifdef TEXT1
	try {

		BlobEngine::BlobGL::Graphic graphic(640, 480);

		//BlobEngine::Renderable shape("../data/sphere.obj");

		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");
		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");
		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf");
		BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Box/glTF/Box.gltf");
		//BlobEngine::glTF2::SceneManager sm("../data/poteau/poteau.gltf");

		std::cout << sm;

		BlobEngine::glTF2::Scene &mainScene = sm.getScene(0);

		BlobEngine::glTF2::Shape &s1 = mainScene.getShape(0);


		BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		graphic.setCameraPosition(10, 10, 10);

		while (graphic.isOpen()) {
			graphic.clear();

			graphic.draw(s1, shaderProgram);

			graphic.display();
		}

	} catch (BlobException &exception) {
		std::cout << exception.what() << std::endl;
	}
#endif
#ifdef TEST2
	try {

		BlobEngine::BlobGL::Graphic graphic(640, 480);

		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");
		BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");
		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf");
		//BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Box/glTF/Box.gltf");
		//BlobEngine::glTF2::SceneManager sm("../data/poteau/poteau.gltf");

		std::cout << sm;

		BlobEngine::glTF2::Scene &mainScene = sm.getScene(0);

		BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		graphic.setCameraPosition(10, 10, 0);

		while (graphic.isOpen()) {
			graphic.clear();

			float angle = BlobEngine::getTime();

			mainScene.setRotation(angle * 40, 0.f, 0.f, 1.f);

			graphic.draw(mainScene, shaderProgram);

			graphic.display();
		}

	} catch (BlobException &exception) {
		std::cout << exception.what() << std::endl;
	}
#endif
	return 0;
}

