#include <Blob/GL/Graphic.hpp>
#include <Blob/glTF2/SceneManager.hpp>
#include <Blob/Exception.hpp>

#include <iostream>
#include <Blob/Time.hpp>
#include <Blob/GL/Shapes.hpp>

using namespace Blob;

void test(const std::string &path, float x = 0, float y = 1, float z = -3, Blob::Vec2f cameraRange = {1, 100}) {
    try {
        std::cout << "test : " << path << std::endl;

        Blob::GL::Graphic graphic(false, 640, 480);

        Blob::glTF2::SceneManager sm(path);

        //std::cout << sm;

        Blob::GL::Shape &mainScene = sm.scenes.front();

        graphic.setCameraPosition(x, y, z);
        graphic.setCameraRange(cameraRange);

        Time::TimePoint start = Time::now();

        while (graphic.isOpen()) {
            graphic.clear();

            Blob::Time::Duration flow = start - Time::now();

            mainScene.setRotation(flow.count(), 0, 1, 0);

            graphic.draw(mainScene);

            graphic.display();
        }

    } catch (Exception &exception) {
        std::cout << exception.what() << std::endl;
    }
}

int main(int argc, char *argv[]) {
    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");

	return 0;
    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/Box/glTF/Box.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/BoxInterleaved/glTF/BoxInterleaved.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/BoxTextured/glTF/BoxTextured.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/Duck/glTF/Duck.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/CesiumMilkTruck/glTF/CesiumMilkTruck.gltf");

    test("/home/patapouf/Projects/Shapes/test.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/TextureCoordinateTest/glTF/TextureCoordinateTest.gltf",
         1000, 0, 0, {100, 2000});

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/2CylinderEngine/glTF/2CylinderEngine.gltf",
            1000, 0, 0, {100, 2000});

	return 0;
}
