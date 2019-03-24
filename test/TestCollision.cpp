#include <iostream>
#include <list>
#include <deque>

#include <Blob/Collision/CollisionDetector.hpp>

#include <Blob/GL/Graphic.hpp>
#include <Blob/GL/Shapes.hpp>
#include <imgui.h>


using namespace Blob;
using namespace Blob::Collision;
using namespace Blob::GL;

class MainRect : public RectDynamic, public Shapes::Cube {
private:
	const std::array<bool, Key::KeyCount> &keys;
	bool isHit = false;

	void preCollisionUpdate() final {
		isHit = false;
		Vec2f Acceleration;

		if (keys[Key::LEFT]) {
			Acceleration.y -= 1;
		}
		if (keys[Key::RIGHT]) {
			Acceleration.y += 1;
		}
		if (keys[Key::UP]) {
			Acceleration.x -= 1;
		}
		if (keys[Key::DOWN]) {
			Acceleration.x += 1;
		}

		if (!Acceleration.isNull()) {
			speed = Acceleration.setLength(3);
		} else
			speed.reset();
	}

	void postCollisionUpdate() final {
<<<<<<< HEAD
		if(isHit)
=======
		if (isHit)
>>>>>>> tmp
			setColor(255, 0, 0);
		else
			setColor(0, 100, 100);
		setPosition(position.x, position.y, 0.5f);
	}

public:

	explicit MainRect(float x, float y, float r, const std::array<bool, Key::KeyCount> &keys) : RectDynamic(1),
																								keys(keys) {
		position = {x, y};
		size = {r, r};

		setScale(r, r, r);
		setPosition(x, y, 0.5f);
	}

<<<<<<< HEAD
	Reaction hit(int objectType, Object &object) final {
		isHit = true;
		return STOP;
=======
	void hit(int objectType, Object &object) final {
		isHit = true;
>>>>>>> tmp
	}
};

class Box : public RectStatic, public Shapes::Cube {
public:
	explicit Box(float x, float y, float r = 1) : RectStatic({x, y}, {r, r}, 0) {
		setScale(r, r, r);
		setPosition(x, y, r / 2);
	}
};

int main() {

	try {
		Graphic graphic(false);

		CollisionDetector collisionDetector;

<<<<<<< HEAD
		MainRect mainRect(4, 4, 1, Graphic::getKeys());
=======
		MainRect mainRect(4.5f, 4.5f, 1, Graphic::getKeys());
>>>>>>> tmp

		std::list<Box> rectanges;

		rectanges.emplace_back(1, 0);
		rectanges.emplace_back(0, 1);
		rectanges.emplace_back(-1, 0);
		rectanges.emplace_back(0, -1);

		rectanges.emplace_back(2.5, 2.5, 0.8);

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