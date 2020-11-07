#include <Blob/Exception.hpp>
#include <Blob/Window.hpp>
#include <Blob/glTF2/SceneManager.hpp>

#include <Blob/Shapes.hpp>
#include <Blob/Time.hpp>
#include <iostream>

using namespace Blob;

void test(const std::string &path, const Geometry::Vec3<> &position = {0, 1, -3}, const Geometry::Vec2<> &cameraRange = {1, 100}) {
    try {
        std::cout << "test : " << path << std::endl;

        Core::Camera camera;

        Core::Window window(camera);

        glTF2::SceneManager sm(path);

        std::cout << sm;

        Core::Scene &mainScene = sm.scenes.front();

        camera.setPosition(position);

        window.setRange(cameraRange.x, cameraRange.y);

        Time::TimePoint start = Time::now();

        while (window.isOpen()) {
            Blob::Time::Duration flow = start - Time::now();

            window.draw(mainScene);

            window.display();
        }

    } catch (Core::Exception &exception) { std::cout << exception.what() << std::endl; }
}

int main(int argc, char *argv[]) {
    //    test("data/models/cube.gltf");
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");
    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf");
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf");

    // More complex models

    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/Box/glTF/Box.gltf");
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/BoxInterleaved/glTF/BoxInterleaved.gltf");
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/BoxTextured/glTF/BoxTextured.gltf");
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/Duck/glTF/Duck.gltf");
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/CesiumMilkTruck/glTF/CesiumMilkTruck.gltf");
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/TextureCoordinateTest/glTF/TextureCoordinateTest.gltf", {1000, 0, 0}, {100, 2000});
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/2CylinderEngine/glTF/2CylinderEngine.gltf", {1000, 0, 0}, {100, 2000});

    return 0;
}
