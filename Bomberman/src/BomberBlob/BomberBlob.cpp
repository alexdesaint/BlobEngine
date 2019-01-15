#include <cmath>
#include <list>
#include <iostream>

#include <BomberBlob/BomberBlob.hpp>

#include <BomberBlob/Explosion.hpp>
#include <BomberBlob/Player.hpp>
#include <BomberBlob/IndestructibleBox.hpp>
#include <BomberBlob/Box.hpp>
#include <BomberBlob/InfoBar.hpp>
#include <BomberBlob/BombManager.hpp>
#include <BomberBlob/Bonus.hpp>

using namespace BlobEngine;

BomberBlob::BomberBlob(BlobGL::Graphic &window) {
	int width = 11 + 6, height = 11 + 6;

	BlobGL::Plane ground;

	ground.loadBMPtexture("data/Grass.bmp");
	ground.setPosition(height / 2.f, height / 2.f, 0);
	ground.setScale(width - 2, height - 2, 1);
	ground.setTextureScale(width - 2);

	//BombManager bombManager(&world);

	const std::array<bool, BlobGL::Key::KeyCount> &keys = BlobGL::Graphic::getKeys();

	std::list<BombManager> bombs;

	Player player(1.5f, 1.5f, bombs);
	player.setAction(Player::right, &keys[BlobGL::Key::RIGHT]);
	player.setAction(Player::left, &keys[BlobGL::Key::LEFT]);
	player.setAction(Player::up, &keys[BlobGL::Key::UP]);
	player.setAction(Player::down, &keys[BlobGL::Key::DOWN]);
	player.setAction(Player::putBomb, &keys[BlobGL::Key::SPACE]);

	//InfoBar infoBar;

	std::list<IndestructibleBox> indestructibleBoxs;
	std::list<Box> boxs;
	std::list<Bonus> bonus;

	for (int i = 4; i < width - 4; i += 2) {
		boxs.emplace_back(0.5f + i, 0.5f + 1);
		boxs.emplace_back(0.5f + i, height - 0.5f - 1);
	}

	for (int i = 4; i < height - 4; i += 2) {
		boxs.emplace_back(0.5f + 1, 0.5f + i);
		boxs.emplace_back(width - 0.5f - 1, 0.5f + i);
	}

	for (int i = 3; i < width - 3; i += 2) {
		for (int j = 2; j < height - 2; j += 2) {
			boxs.emplace_back(0.5 + i, 0.5 + j);
		}
	}

	for (int i = 2; i < width - 2; i += 2) {
		for (int j = 3; j < height - 3; j += 2) {
			boxs.emplace_back(0.5f + i, 0.5 + j);
		}
	}

	for (int i = 0; i < width; i += 1) {
		indestructibleBoxs.emplace_back(0.5f + i, 0.5f);
	}

	for (int i = 0; i < width; i += 1) {
		indestructibleBoxs.emplace_back(0.5f + i, height - 0.5f);
	}

	for (int i = 1; i < height - 1; i += 1) {
		indestructibleBoxs.emplace_back(0.5f, 0.5f + i);
	}

	for (int i = 1; i < height - 1; i += 1) {
		indestructibleBoxs.emplace_back(width - 0.5f, 0.5f + i);
	}

	for (int i = 2; i < width - 2; i += 2) {
		for (int j = 2; j < height - 2; j += 2) {
			indestructibleBoxs.emplace_back(0.5f + i, 0.5f + j);
		}
	}

//	Bomb bomb(7.5f, 1.5f);

	InfoBar infoBar;

	Collision::CollisionDetector collisionDetector{};

	BlobGL::ShaderProgram shaderProgram("data/vertex.glsl", "data/fragment.glsl");
	BlobGL::ShaderProgram shaderProgram2D("data/vertex2D.glsl", "data/fragment2D.glsl");

	window.setCameraPosition(width, height / 2.f, (width+height)/2.f + 4);

	window.setCameraLookAt(width / 2.f, height / 2.f, 0);

	//window.setOrthoProjection(-width/2.f, width/2.f, -height/2.f, height/2.f, 1,20);

	bool endGmae = false, escape = false;

	while(window.isOpen() && !endGmae) {

		window.clear();

		window.draw(ground, shaderProgram);

		for (auto &ib : indestructibleBoxs)
			window.draw(ib, shaderProgram);

		for (auto i = bombs.begin(); i != bombs.end();) {
			if (i->update()) {
				i = bombs.erase(i);
			} else {
				window.draw(*i, shaderProgram);
				i++;
			}
		}

		collisionDetector.update();

		//evolutive objects :

		for (auto i = boxs.begin(); i != boxs.end();) {
			if (i->isDestroy()) {
				bonus.emplace_back(i->position);

				i = boxs.erase(i);
			}
			else {
				window.draw(*i, shaderProgram);
				i++;
			}
		}

		for (auto i = bonus.begin(); i != bonus.end();) {
			if (i->update()) {
				i = bonus.erase(i);
			}
			else {
				window.draw(*i, shaderProgram);
				i++;
			}
		}

		window.draw(player, shaderProgram);

		//window.draw(infoBar, shaderProgram2D);

		window.display();

		//if(!player.isAlive())
		//	endGmae = true;

		if(keys[BlobGL::ESCAPE] && !escape) {
			escape = true;
		} else if(!keys[BlobGL::ESCAPE] && escape) {
			endGmae = true;
		}
	}
}
