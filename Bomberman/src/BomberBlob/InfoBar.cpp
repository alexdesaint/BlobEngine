#include <BomberBlob/InfoBar.hpp>

using namespace BlobEngine::BlobGL::Text;

InfoBar::InfoBar() : p1("PLAYER 1:"){
	leftPanel.setScale(0.3, 2, 1);
	leftPanel.setPosition(-1.f, -1.f, 0);

	rightPanel.setScale(0.3, 2, 1);
	rightPanel.setPosition(0.7f, -1.f, 0);

	addRenderable(&rightPanel);
	addRenderable(&leftPanel);

	p1.setPosition(-0.85f, 0.9, 0.f);
	p1.setScale(0.06f, 0.06f, 1);

	addRenderable(&p1);
}
