#include <iostream>

#include <BomberBlob/Box.hpp>
#include <BomberBlob/BomberBlob.hpp>

using namespace BlobEngine;
using namespace BlobEngine::BlobGL;

int main() {

	try {
		Graphic graphic(false);

		(BomberBlob(graphic));

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