#include <iostream>
#include <list>
#include <deque>

#include <BlobEngine/Collision/CollisionDetector.hpp>

#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

using namespace BlobEngine;
using namespace BlobEngine::BlobGL;

class MainRect : public RectDynamic, public Cube {
private:
	const std::array<bool, Key::KeyCount> &keys;

	void preCollisionUpdate() final {
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
			speed = Acceleration.setLength(1);
		} else
			speed.reset();
	}

	void postCollisionUpdate() final {
		setPosition(position.x, position.y, 0.5f);
	}

public:

	explicit MainRect(int x, int y, int r, const std::array<bool, Key::KeyCount> &keys) : RectDynamic(1), keys(keys) {
		position = {(float)x, (float)y};
		size = {(float)r, (float)r};

		setScale(r, r, r);
		setPosition(x, y, 0.5f);
	}
};

class Box : public RectStatic, public Cube {
private:

public:
	explicit Box(int x, int y, int r = 1) : RectStatic(0) {
		position = {(float)x, (float)y};
		size = {(float)r, (float)r};

		setScale(r, r, r);
		setPosition(x, y, 0.5f);
	}
};

int main() {

	try {
		Graphic graphic(640, 480);
		ShaderProgram shaderProgram("../BlobEngine/data/vertex.glsl", "../BlobEngine/data/fragment.glsl");

		CollisionDetector collisionDetector;

		Plane p;

		p.move(0, 2, 0);

		MainRect mainRect(4, 4, 1, graphic.getKeys());

		std::list<Box> rectanges;

		rectanges.emplace_back(1, 0);
		rectanges.emplace_back(0, 1);
		rectanges.emplace_back(-1, 0);
		rectanges.emplace_back(0, -1);

		graphic.setCameraPosition(10, 0, 10);

		while (graphic.isOpen()) {
			graphic.clear();

			for(auto &rect : rectanges) {
				graphic.draw(rect, shaderProgram);
			}

			collisionDetector.update();

			graphic.draw(p, shaderProgram);
			graphic.draw(mainRect, shaderProgram);

			graphic.display();

		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}