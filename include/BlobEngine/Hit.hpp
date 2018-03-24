//
// Created by alexa on 16/03/2018.
//

#ifndef BLOBENGINE_HIT_HPP
#define BLOBENGINE_HIT_HPP

#include "Geometrie.hpp"

namespace BlobEngine {

	class Hit {
	private:
		/*
		 * Points :
		 * A : centre du cercle en mouvement (object.position)
		 * B : centre du cercle cible (target.position)
		 * F : position du cercle en collision
		 *
		 * D : A + vecteur vitesse
		 * E : Point sur la trajectoire le plus proche de la cible
		 *
		 * u : normalized vector
		 * */
		bool hit = false;

		Vec2f vecAF{};
		Vec2f n{};

		Vec2f frameMove{};

	public:
		void load(Circle object, Circle target, Vec2f frameMove);

		void load(Circle object, Line target, Vec2f frameMove);

		Hit() {};
		
		Hit(Circle object, Circle circleTarget, Vec2f frameMove) : frameMove(frameMove) {
			load(object, circleTarget, frameMove);
		}

		Hit(Circle object, Line lineTarget, Vec2f frameMove) : frameMove(frameMove) {
			load(object, lineTarget, frameMove);
		}

		bool hitTarget() {
			return hit;
		}

		Vec2f getRoll(Vec2f *speed);

		Vec2f getBounce(Vec2f *speed);

		Vec2f getHitPoint() {
			return vecAF;
		}

		bool isCloserObstacle(Hit second) {
			return (vecAF.length2() < second.vecAF.length2());
		}
	};
}

#endif //BLOBENGINE_HIT_HPP
