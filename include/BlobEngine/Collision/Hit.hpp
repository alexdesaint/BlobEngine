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
		
		Point2f A, B, C, D, E, F, G, H;
		float rayonA, rayonB;
		
		bool hit = false;

		Vec2f vecAF{};
		Vec2f n{};

		Vec2f frameMove{};
		
		float sng(float x) {
			if (x < 0)
				return -1;
			return 1;
		}

	public:
		bool load2();
		
		void load(Circle object, Point2f target);

		void load(Circle object, Circle target);

		void load(Circle object, Line target);

		Hit() {};
		
		Hit(Circle object, Point2f target, Vec2f frameMove) :
				frameMove(frameMove),
				A(object.position),
				B(target),
				rayonA(object.rayon),
				rayonB(0),
				D(A + frameMove) {
			hit = load2();
		}
		
		Hit(Circle object, Circle target, Vec2f frameMove) :
				frameMove(frameMove),
				A(object.position),
				B(target.position),
				rayonA(object.rayon),
				rayonB(target.rayon),
				D(A + frameMove) {
			hit = load2();
		}

		Hit(Circle object, Line target, Vec2f frameMove) : frameMove(frameMove) {
			load(object, target);
		}

		bool hitTarget() {
			return hit;
		}

		Vec2f getReactionVec(Reaction reaction, Vec2f &speed);

		Vec2f getVecToTarget() {
			return vecAF;
		}

		bool isCloserObstacle(Hit second) {
			return (vecAF.length2() < second.vecAF.length2());
		}
	};
}

#endif //BLOBENGINE_HIT_HPP
