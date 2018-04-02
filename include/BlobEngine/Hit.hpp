//
// Created by alexa on 16/03/2018.
//

#ifndef BLOBENGINE_HIT_HPP
#define BLOBENGINE_HIT_HPP

#include <BlobEngine/Geometrie.hpp>
#include <BlobEngine/Reaction.hpp>

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
		void load(Circle object, Point2f target);

		void load(Circle object, Circle target);

		void load(Circle object, Line target);

		Hit() {};

		Hit(Circle object, Point2f target, Vec2f frameMove) : frameMove(frameMove) {
			load(object, target);
		}

		Hit(Circle object, Circle target, Vec2f frameMove) : frameMove(frameMove) {
			load(object, target);
		}

		Hit(Circle object, Line target, Vec2f frameMove) : frameMove(frameMove) {
			load(object, target);
		}

		bool hitTarget() {
			return hit;
		}

		Vec2f getReactionVec(Reaction reaction, Vec2f &speed);

		Vec2f getVecToTarget() {
			vecAF.round(2);

			return vecAF;
		}

		bool isCloserObstacle(Hit second) {
			return (vecAF.length2() < second.vecAF.length2());
		}
	};
}

#endif //BLOBENGINE_HIT_HPP
