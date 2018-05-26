//
// Created by alexa on 20/05/2018.
//

#include <SFML/Graphics.hpp>

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(600, 600), "BlobEngine test", sf::Style::Close, settings);
	window.setFramerateLimit(60);

	sf::RectangleShape shape(sf::Vector2f(20, 20));
	shape.setPosition(100, 100);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen()) {
		window.clear();

		sf::Event event{};

		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed :
					window.close();
					break;
				case sf::Event::MouseButtonPressed :
					break;
				case sf::Event::MouseButtonReleased :
					break;
				case sf::Event::KeyPressed :
					break;
				case sf::Event::KeyReleased :
					break;
				default:
					break;
			}
		}

		window.draw(shape);
		window.display();
	}

	return 0;
}