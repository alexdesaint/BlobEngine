#include <deque>
#include <iostream>
#include <list>

class test_class;
#include <Blob/Collision/CollisionDetector.hpp>

#include <Blob/Controls.hpp>
#include <Blob/Maths.inl>
#include <Blob/Shape.hpp>
#include <Blob/Shapes.hpp>
#include <Blob/Window.hpp>
#include <imgui.h>

using namespace std;
using namespace Blob;
using namespace Blob::Core;
using namespace Blob::Collision;

class test_class {
public:
    CollisionDetector collisionDetector;

    test_class() {
        Maths::Vec2<> p1(-3.4, -2.9), p2(3, -2), p3(3, 2), p4(-3, 2);

        if (p1.cast<int64_t>() != CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p1)))
            cout << "ERROR : " << p1 << " --hash--unhash-> " << CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p1)) << endl;

        if (p2.cast<int64_t>() != CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p2)))
            cout << "ERROR : " << p1 << " --hash--unhash-> " << CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p2)) << endl;

        if (p3.cast<int64_t>() != CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p3)))
            cout << "ERROR : " << p1 << " --hash--unhash-> " << CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p3)) << endl;

        if (p4.cast<int64_t>() != CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p4)))
            cout << "ERROR : " << p1 << " --hash--unhash-> " << CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p4)) << endl;
        /*
                for(auto &p : CollisionDetector::getPath(p1, p2))
                    cout << CollisionDetector::unhashCoor(p) << endl;

                for(auto &p : CollisionDetector::getPath(p2, p3))
                    cout << CollisionDetector::unhashCoor(p) << endl;

                for(auto &p : CollisionDetector::getPath(p3, p4))
                    cout << CollisionDetector::unhashCoor(p) << endl;

                for(auto &p : CollisionDetector::getPath(p4, p1))
                    cout << CollisionDetector::unhashCoor(p) << endl;*/

        cout << "spacialHash :" << endl;
        for (const auto &p : CollisionDetector::spacialHash) {
            cout << CollisionDetector::unhashCoor(p.first) << endl;
            for (Object *k : p.second) {
                cout << k << endl;
            }
        }

        RectStatic rs({2.5, 2.5}, {0.1, 0.1}, 0);
        cout << "adding : " << &rs << " to map" << endl;

        RectDynamic rd({3.5, 2.5}, {0.1, 0.1}, 0);
        cout << "adding : " << &rd << " to map" << endl;

        cout << "spacialHash :" << endl;
        for (auto p : CollisionDetector::spacialHash) {
            cout << CollisionDetector::unhashCoor(p.first) << endl;
            for (Object *k : p.second) {
                cout << k << endl;
            }
        }

        cout << "Old pos : " << rd.position << endl;

        // CollisionDetector::computeLocalCollision(rd, CollisionDetector::spacialHash[CollisionDetector::hashCoor(rs.getPosition())],
        //        {-2, 0});

        cout << "New pos : " << rd.position << endl;

        cout << "spacialHash :" << endl;
        for (auto p : CollisionDetector::spacialHash) {
            cout << CollisionDetector::unhashCoor(p.first) << endl;
            for (Object *k : p.second) {
                cout << k << endl;
            }
        }

        // test rasterize
        cout << "Rasterize" << endl;
        for (auto i : Geometry::Rectangle({2, 2}, {2, 2}).rasterize())
            cout << i << endl;

        cout << "Rasterize" << endl;
        for (auto i : Geometry::Rectangle({2, 2}, {1, 3}).rasterize())
            cout << i << endl;

        cout << "Rasterize" << endl;
        for (auto i : Geometry::Rectangle({2.5, 2.5}, {0.8, 0.8}).rasterize())
            cout << i << endl;
    }

    ~test_class() {
        cout << "spacialHash (should be empty) :" << endl;
        for (auto p : CollisionDetector::spacialHash) {
            cout << CollisionDetector::unhashCoor(p.first) << endl;
            for (Object *k : p.second) {
                cout << k << endl;
            }
        }
    }
};

class MainRect : public RectDynamic, public Shape, private KeyboardEvents { // TODO: Object (add this to entt), Controllable, RectDynamic, Shape
private:
    bool isHit = false;

    Material::SingleColorMaterial material;
    Shapes::Cube mesh;

    void keyboardUpdate(const Keyboard &keyboard) final {
        Maths::Vec2<> Acceleration;

        if (keyboard.LEFT)
            Acceleration.y -= 1;
        if (keyboard.RIGHT)
            Acceleration.y += 1;
        if (keyboard.UP)
            Acceleration.x -= 1;
        if (keyboard.DOWN)
            Acceleration.x += 1;

        if (!Acceleration.isNull())
            speed = Acceleration.setLength(3);
        else
            speed = {0, 0};
    }

    void postCollisionUpdate() final {
        if (isHit) {
            material.albedo = Color::Red;
            isHit = false;
        } else
            material.albedo = Color::Blue;
        Shape::setPosition(position);
    }

public:
    MainRect(float x, float y, float r) : RectDynamic({x, y}, {r, r}, 1), Shape(mesh, {x, y}, {r, r}), mesh(material) {}

    void hit(int objectType, Object &object) final {
        (void) (objectType);
        (void) (object);
        isHit = true;
    }
};

class Box : public RectStatic, public Shape {
public:
    Box(Mesh &mesh, float x, float y, float r = 1) : RectStatic({x, y}, {r, r}, 0), Shape(mesh, {x, y}, {r, r}) {}
};

int main() {

    (test_class());

    try {
        Camera camera;
        Window window(camera);

        CollisionDetector collisionDetector;

        MainRect mainRect(4.5f, 4.5f, 1);

        Material::SingleColorMaterial boxMaterial, groundMaterial(Color::BurlyWood);
        Shapes::Cube boxMesh(boxMaterial);
        Shapes::Plane plane(groundMaterial);

        Shape ground(plane, {0, 0, -.5f}, {10, 10, 1});

        std::list<Box> rectanges;

        rectanges.emplace_back(boxMesh, 1, 0);
        rectanges.emplace_back(boxMesh, 0, 1);
        rectanges.emplace_back(boxMesh, -1, 0);
        rectanges.emplace_back(boxMesh, 0, -1);

        rectanges.emplace_back(boxMesh, 3, 3, 0.8);

        rectanges.emplace_back(boxMesh, 1, 3, 0.2);

        camera.setPosition({10, 0, 10});

        while (window.isOpen()) {

            for (auto &rect : rectanges)
                window.draw(rect);

            window.draw(ground);

            collisionDetector.update();

            window.draw(mainRect);

            window.display();
        }
    } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    return 0;
}
