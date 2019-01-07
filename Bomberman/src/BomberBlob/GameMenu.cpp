#include "BomberBlob/GameMenu.hpp"

#include <BomberBlob/BomberBlob.hpp>

using namespace sf;

sf::Text GameMenu::createText(const sf::String &str, unsigned int size, int x , int y) {
	sf::Text text(str, font);
	text.setCharacterSize(size);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	text.setPosition(x, y);

	return text;
}

GameMenu::GameMenu(sf::RenderWindow &window) : window(window) {

	font.loadFromFile("../data/FFFFORWA.TTF");

	Text title = createText("BomberBlob", 50, window.getSize().x/2, 100);

	Text start = createText("-- Press Any Button --", 15, window.getSize().x/2, window.getSize().y/2);

	sf::Clock timer;
	timer.restart();

	while (window.isOpen()) {
		Keyboard::Key Key;
		Event event{};
		while (window.pollEvent(event)) {
			switch (event.type) {
				case Event::Closed :
					window.close();
				case Event::KeyPressed :
					Key = event.key.code;

					switch (Key) {
						case Keyboard::Left :
						case Keyboard::Right :
						case Keyboard::Up :
						case Keyboard::Down :
						case Keyboard::Enter :
						default:
							BomberBlob bomberBlob(window);
							break;
					}
					break;
				default:
					break;
			}
		}
		window.clear(sf::Color::Red);

		window.draw(title);

		if(timer.getElapsedTime().asMilliseconds()%2000>1000)
			window.draw(start);

		window.display();
	}
}
