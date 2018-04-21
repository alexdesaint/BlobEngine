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
		Point2i A, B;
		
		bool hit = false;
		bool superposition = false;
		
		Vec2i vecAF{};
		Vec2f n{};
		
		Vec2i frameMove{};
		
		Vec2i rectificationPosition{};
		
		void load(Circle object, Circle target);
		
		void load(Circle object, Line target);
	
	public:
		
		Hit() = default;
		
		Hit(Circle object, Point2f target, Vec2f frameMove) : frameMove(static_cast<int>(frameMove.x * 100),
																		static_cast<int>(frameMove.y * 100)),
															  A(static_cast<int>(object.position.x * 100),
																static_cast<int>(object.position.y * 100)),
															  B(static_cast<int>(target.x * 100),
																static_cast<int>(target.y * 100)) {
			load(object, Circle(target, 0));
		}
		
		Hit(Circle object, Circle target, Vec2f frameMove) : frameMove(static_cast<int>(frameMove.x * 100),
																	   static_cast<int>(frameMove.y * 100)),
															 A(static_cast<int>(object.position.x * 100),
															   static_cast<int>(object.position.y * 100)),
															 B(static_cast<int>(target.position.x * 100),
															   static_cast<int>(target.position.y * 100)) {
			load(object, target);
		}
		
		Hit(Circle object, Line target, Vec2f frameMove) : frameMove(static_cast<int>(frameMove.x * 100),
																	 static_cast<int>(frameMove.y * 100)) {
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

		Vec2f getVecToTarget() {
			return {(float) vecAF.x / 100, (float) vecAF.y / 100};
		}

		bool isCloserObstacle(Hit second) {
			return (vecAF.length2() < second.vecAF.length2());
		}
	};
}

#endif //BLOBENGINE_HIT_HPP
