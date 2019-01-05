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

		if (keys[Key::Left]) {
			Acceleration.y -= 1;
		}
		if (keys[Key::Right]) {
			Acceleration.y += 1;
		}
		if (keys[Key::Up]) {
			Acceleration.x -= 1;
		}
		if (keys[Key::Down]) {
			Acceleration.x += 1;
		}

		if (!Acceleration.isNull()) {
			speed = Acceleration.setLength(2);
		} else
			speed.reset();
	}

	void postCollisionUpdate() final {
		setPosition(position.x, position.y, 0.5f);
	}

public:

	explicit MainRect(float x, float y, float r, const std::array<bool, Key::KeyCount> &keys) : RectDynamic(1), keys(keys) {
		position = {x, y};
		size = {r, r};

		setScale(r, r, r);
		setPosition(x, y, 0.5f);
	}
};

class Box : public RectStatic, public Cube {
private:

public:
	explicit Box(float x, float y, float r = 1.f) : RectStatic(0) {
		position = {x, y};
		size = {r, r};

		setScale(r, r, r);
		setPosition(x, y, 0.5f);
	}
};

int main() {

	try {
		Graphic graphic(640, 480);
		ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		CollisionDetector collisionDetector;

		Plane p;

		p.move(0, 2, 0);

		p.setScale(2,2,2);

		MainRect mainRect(4, 4, 0.8f, graphic.getKeys());

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

/*
int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;

	unsigned int width = 1920, height = 1080;

	sf::RenderWindow window(sf::VideoMode(width, height), "BomberMan", sf::Style::Default, settings);

	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	GameMenu gameMenu(window);

	return 0;
}
 */