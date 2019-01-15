#ifndef BOMBERMAN_INFOBAR_HPP
#define BOMBERMAN_INFOBAR_HPP

#include <BlobEngine/BlobGL/Text.hpp>
#include <BlobEngine/BlobGL/Shape.hpp>

#include <BomberBlob/Player.hpp>

class InfoBar : public BlobEngine::BlobGL::Shape {
private:
	BlobEngine::BlobGL::Text::Plane2D rightPanel, leftPanel;

	BlobEngine::BlobGL::Text::Text p1;

public:
	InfoBar();
};

#endif //BOMBERMAN_INFOBAR_HPP
