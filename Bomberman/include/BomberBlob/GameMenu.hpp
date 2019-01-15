#ifndef BOMBERMAN_GAMEMENU_HPP
#define BOMBERMAN_GAMEMENU_HPP

#include <BlobEngine/BlobGL/Graphic.hpp>

class GameMenu {
private:
	BlobEngine::BlobGL::Graphic &window;

public:
	explicit GameMenu(BlobEngine::BlobGL::Graphic &window);
};


#endif //BOMBERMAN_GAMEMENU_HPP
