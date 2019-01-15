#include <BomberBlob/GameMenu.hpp>

#include <BlobEngine/BlobGL/Text.hpp>
#include <BlobEngine/Time.hpp>
#include <BomberBlob/BomberBlob.hpp>


using namespace BlobEngine::Time;
using namespace BlobEngine::BlobGL;

GameMenu::GameMenu(Graphic &window) : window(window) {

	Text::Text title("BOMBERBLOB");
	title.setScale(0.3, 0.3, 1);

	Text::Text start("-- PRESS SPACE BAR --");
	start.setScale(0.1, 0.1, 1);
	start.setPosition(0, -0.5f, 0);

	ShaderProgram shaderProgram("data/vertex2D.glsl", "data/fragment2D.glsl");

	const std::array<bool, Key::KeyCount> &keys = Graphic::getKeys();

	TimePoint flow = now();

	bool space = false, escape = false;

	while (window.isOpen()) {
		window.clear();

		window.draw(title, shaderProgram);

		Duration d = now() - flow;

		if(d.count() < 1)
			window.draw(start, shaderProgram);
		else if(d.count() > 2)
			flow = now();

		window.display();

		if(keys[SPACE] && !space) {
			space = true;
		} else if(!keys[SPACE] && space) {
			(BomberBlob(window));
			space = false;
		}

		if(keys[ESCAPE] && !escape) {
			escape = true;
		} else if(!keys[ESCAPE] && escape) {
			window.close();
			escape = false;
		}
	}
}
