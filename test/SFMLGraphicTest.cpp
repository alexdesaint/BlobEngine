#include <iostream>

#include <SFML/Window.hpp>

#include <BlobEngine/BlobGL/Graphic.hpp>

int main() {

	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 4;
	settings.minorVersion = 5;

	sf::Window App(sf::VideoMode(640, 480), "glTest", sf::Style::Default, settings);

	settings = App.getSettings();

	std::cout << "depth bits:" << settings.depthBits << std::endl;
	std::cout << "stencil bits:" << settings.stencilBits << std::endl;
	std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
	std::cout << "version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;

	BlobEngine::Graphic graphic("glTest", 640, 480);

	while (App.isOpen()) {

		sf::Event Event{};
		while (App.pollEvent(Event)) {

			if (Event.type == sf::Event::Closed)
				App.close();

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				App.close();

		}

		graphic.clear();

		App.display();
	}

	return EXIT_SUCCESS;
}