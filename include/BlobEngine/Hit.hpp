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
		Point2f A, B, F, D;
		float rayonA, rayonB;
		
		bool hit = false;
		bool superposition = false;

		Vec2f n{};

		Vec2f frameMove{};

		Vec2f rectificationPosition{};

		void load();
		
		void load(Circle object, Line target);
	
	public:
		
		Hit() = default;

		Hit(Circle object, Point2f target, Vec2f frameMove) : frameMove(frameMove),
															  A(object.position),
															  B(target),
															  rayonA(object.rayon),
															  rayonB(0),
															  D(A + frameMove) {
			load();
		}

		Hit(Circle object, Circle target, Vec2f frameMove) : frameMove(frameMove),
															 A(object.position),
															 B(target.position),
															 rayonA(object.rayon),
															 rayonB(target.rayon),
															 D(A + frameMove) {
			load();
		}

		Hit(Circle object, Line target, Vec2f frameMove) : frameMove(frameMove) {
			load(object, target);
		}
		
		const Vec2f &getRectificationPosition() const;
		
		bool hitTarget() {
			return hit;
		}
		
		bool superpositionOnTarget() {
			return superposition;
		}

		Vec2f getReactionVec(Reaction reaction, Vec2f &speed);

		Point2f getHitPoint() {
			return F;
		}

		bool isCloserObstacle(Hit second) {
			return (Vec2f(A, F).length2() < Vec2f(second.A, second.F).length2());
		}
	};
}

#endif //BLOBENGINE_HIT_HPP
