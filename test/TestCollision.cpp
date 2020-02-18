#include <iostream>
#include <list>
#include <deque>

class test_class;
#include <Blob/Collision/CollisionDetector.hpp>

#include <Blob/GL/Graphic.hpp>
#include <Blob/GL/Shapes.hpp>
#include <imgui.h>


using namespace std;
using namespace Blob;
using namespace Blob::Collision;
using namespace Blob::GL;

class test_class {
public:
    CollisionDetector collisionDetector;

    test_class() {
        Vec2f p1(-3.4, -2.9), p2(3, -2), p3(3, 2), p4(-3, 2);

        if(p1.cast<int>() != CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p1)))
            cout << "ERROR : " << p1 << " --hash--unhash-> " <<
            CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p1)) << endl;

        if(p2.cast<int>() != CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p2)))
            cout << "ERROR : " << p1 << " --hash--unhash-> " <<
                 CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p2)) << endl;

        if(p3.cast<int>() != CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p3)))
            cout << "ERROR : " << p1 << " --hash--unhash-> " <<
                 CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p3)) << endl;

        if(p4.cast<int>() != CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p4)))
            cout << "ERROR : " << p1 << " --hash--unhash-> " <<
                 CollisionDetector::unhashCoor(CollisionDetector::hashCoor(p4)) << endl;
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
        for(const auto& p : CollisionDetector::spacialHash) {
            cout << CollisionDetector::unhashCoor(p.first) << endl;
            for(Object* k : p.second) {
                cout << k << endl;
            }
        }


        RectStatic rs({2.5, 2.5}, {0.1, 0.1}, 0);
        cout << "adding : " << &rs << " to map" << endl;

        RectDynamic rd({3.5, 2.5}, {0.1, 0.1}, 0);
        cout << "adding : " << &rd << " to map" << endl;

        cout << "spacialHash :" << endl;
        for(auto p : CollisionDetector::spacialHash) {
            cout << CollisionDetector::unhashCoor(p.first) << endl;
            for(Object* k : p.second) {
                cout << k << endl;
            }
        }

        cout << "Old pos : " << rd.position << endl;

        //CollisionDetector::computeLocalCollision(rd, CollisionDetector::spacialHash[CollisionDetector::hashCoor(rs.getPosition())],
        //        {-2, 0});

        cout << "New pos : " << rd.position << endl;

        cout << "spacialHash :" << endl;
        for(auto p : CollisionDetector::spacialHash) {
            cout << CollisionDetector::unhashCoor(p.first) << endl;
            for(Object* k : p.second) {
                cout << k << endl;
            }
        }


        //test rasterize
        cout << "Rasterize" << endl;
        for(auto i : Rectangle({2, 2}, {2, 2}).rasterize())
            cout << i << endl;

        cout << "Rasterize" << endl;
        for(auto i : Rectangle({2, 2}, {1, 3}).rasterize())
            cout << i << endl;

        cout << "Rasterize" << endl;
        for(auto i : Rectangle({2.5, 2.5}, {0.8, 0.8}).rasterize())
            cout << i << endl;
    }

    ~test_class() {
        cout << "spacialHash (should be empty) :" << endl;
        for(auto p : CollisionDetector::spacialHash) {
            cout << CollisionDetector::unhashCoor(p.first) << endl;
            for(Object* k : p.second) {
                cout << k << endl;
            }
        }
    }
};

class MainRect : public RectDynamic, public Shapes::Cube {
private:
	bool isHit = false;

	void preCollisionUpdate() final {
		isHit = false;
		Vec2f Acceleration;

        if (Controls::Keys::LEFT) {
			Acceleration.y -= 1;
		}
        if (Controls::Keys::RIGHT) {
			Acceleration.y += 1;
		}
        if (Controls::Keys::UP) {
			Acceleration.x -= 1;
		}
        if (Controls::Keys::DOWN) {
			Acceleration.x += 1;
		}

		if (!Acceleration.isNull()) {
			speed = Acceleration.setLength(3);
		} else
			speed.reset();
	}

	void postCollisionUpdate() final {
		if (isHit)
            setTexture(*Colors::red);
		else
            setTexture(*Colors::blue);
        Cube::setPosition(position, 0.5f);
	}

public:

    explicit MainRect(float x, float y, float r) :
            RectDynamic({x, y}, {r, r}, 1) {
        Cube::setScale(r, r, r);
        Cube::setPosition(x, y, 0.5f);
	}

	void hit(int objectType, Object &object) final {
		isHit = true;
	}
};

class Box : public RectStatic, public Shapes::Cube {
public:
	Box(float x, float y, float r = 1) : RectStatic({x, y}, {r, r}, 0) {
        Cube::setScale(r, r, r);
        Cube::setPosition(x, y, r / 2);
	}
};

int main() {

    (test_class());

	try {
		Graphic graphic(false);

		CollisionDetector collisionDetector;

        MainRect mainRect(4.5f, 4.5f, 1);

		std::list<Box> rectanges;

		rectanges.emplace_back(1, 0);
		rectanges.emplace_back(0, 1);
		rectanges.emplace_back(-1, 0);
		rectanges.emplace_back(0, -1);

		rectanges.emplace_back(3, 3, 0.8);

		graphic.setCameraPosition(10, 0, 10);

		while (graphic.isOpen()) {
			graphic.clear();
			ImGui::NewFrame();
			ImGui::Begin("Debug");

			for (auto &rect : rectanges) {
				graphic.draw(rect);
			}

			collisionDetector.update();

			graphic.draw(mainRect);

			ImGui::End();
			graphic.drawImGUI();
			graphic.display();

		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}