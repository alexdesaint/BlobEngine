#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/glTF2/SceneManager.hpp>
#include <BlobEngine/BlobException.hpp>

#include <iostream>
#include <BlobEngine/Time.hpp>

#define TEST2

int main(int argc, char *argv[]) {

#ifdef TEXT1
	try {

		Blob::GL::Graphic graphic(640, 480);

		//Blob::Renderable shape("../data/sphere.obj");

		//Blob::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");
		//Blob::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");
		//Blob::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf");
		Blob::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Box/glTF/Box.gltf");
		//Blob::glTF2::SceneManager sm("../data/poteau/poteau.gltf");

		std::cout << sm;

		Blob::glTF2::Scene &mainScene = sm.getScene(0);

		Blob::glTF2::Shape &s1 = mainScene.getShape(0);


		Blob::GL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

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

		Blob::GL::Graphic graphic(640, 480);

		//Blob::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");
		Blob::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");
		//Blob::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf");
		//Blob::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/Box/glTF/Box.gltf");
		//Blob::glTF2::SceneManager sm("../data/poteau/poteau.gltf");

		std::cout << sm;

		Blob::glTF2::Scene &mainScene = sm.getScene(0);

		Blob::GL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		graphic.setCameraPosition(10, 10, 0);

		while (graphic.isOpen()) {
			graphic.clear();

			float angle = Blob::getTime();

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

