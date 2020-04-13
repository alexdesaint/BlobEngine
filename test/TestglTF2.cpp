#include <Blob/Exception.hpp>
#include <Blob/Window.hpp>
#include <Blob/glTF2/SceneManager.hpp>

#include <Blob/Shapes.hpp>
#include <Blob/Time.hpp>
#include <iostream>

#include <tiny_gltf.h>

using namespace Blob;

void test(const std::string &path, float x = 0, float y = 1, float z = -3, Blob::Vec2f cameraRange = {1, 100}) {
    try {
        std::cout << "test : " << path << std::endl;

        Camera camera;

        Window window(camera);

        glTF2::SceneManager sm(path);

        std::cout << sm;

        Scene &mainScene = sm.scenes.front();

        camera.setPosition(x, y, z);
        window.setRange(cameraRange.x, cameraRange.y);

        Time::TimePoint start = Time::now();

        while (window.isOpen()) {
            Blob::Time::Duration flow = start - Time::now();

            window.draw(mainScene);

            window.display();
        }

    } catch (Exception &exception) { std::cout << exception.what() << std::endl; }
}

int main(int argc, char *argv[]) {
    test("data/models/cubeOpti.gltf");

    return 0;

    test("../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/Box/glTF/Box.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/BoxInterleaved/glTF/BoxInterleaved.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/BoxTextured/glTF/BoxTextured.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/Duck/glTF/Duck.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/CesiumMilkTruck/glTF/CesiumMilkTruck.gltf");

    test("/home/patapouf/Projects/Shapes/test.gltf");

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/TextureCoordinateTest/glTF/TextureCoordinateTest.gltf", 1000, 0, 0, {100, 2000});

    test("/home/patapouf/Projects/glTF-Sample-Models/2.0/2CylinderEngine/glTF/2CylinderEngine.gltf", 1000, 0, 0, {100, 2000});

    return 0;
}
