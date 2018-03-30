#include <BlobEngine/Hit.hpp>

#include <cmath>

namespace BlobEngine {

	void Hit::load(Circle object, Circle target, Vec2f frameMove) {
		this->frameMove = frameMove;

		float RayonAB = object.rayon + target.rayon;

		Vec2f vecAB(object.position, target.position);

		if (frameMove.length() >
			vecAB.length() - RayonAB) {//si la distance qui les sépare est plus courte que le vecteur vitesse

			if (frameMove.scalaire(vecAB) > 0) {// si il ne sont pas de dirrection opposé

				float AE = Vec2f(frameMove).getNormal().scalaire(vecAB);//distance avant le point le plus proche

				float BE2 = vecAB.length2() - AE * AE;

				float RayonAB2 = RayonAB * RayonAB;

				if (BE2 < RayonAB2) {

					float AF = AE - std::sqrt(RayonAB2 - BE2);

					if (AF < frameMove.length()) {
						//ils se touche forcément
						vecAF = Vec2f(frameMove).setLength(AF);

						Vec2f vecFB = (vecAB * -1.0f) + vecAF;

						n = vecFB.getNormal();

						hit = true;
					}
				}
			}
		}
	}

	void Hit::load(Circle object, Line target, Vec2f frameMove) {

		Point2f C = target.closestPointTo(object.position);
		Vec2f vecCA(C, object.position);
		n = vecCA.getNormal();

		if (object.rayon + frameMove.length() > vecCA.length()) {
			float a = vecCA.scalaire(frameMove);

			if (a < 0) {

				Point2f G = object.position - n * object.rayon;
				
				Point2f I = target.getIntersectionPoint(Line(G, G + frameMove));
				
				Point2f M = (target.pointA + target.pointB) / 2;
				
				if (Vec2f(M, I).length() <= (target.Length() / 2)) {
					
					//if (Vec2f(G, I).scalaire(frameMove) > 0) {// si il ne sont pas de dirrection opposé
						
						Point2f F = I + n * object.rayon;
						
						vecAF = Vec2f(object.position, F);
						
						if (vecAF.length2() < frameMove.length2()) {
							
							//ils se touchent forcément
							
							hit = true;
						}
					//}
				} else if (Vec2f(M, I).length() <= (target.Length() / 2 + object.rayon)) {
					Point2f B;
					
					if (Vec2f(target.pointA, I).length2() < Vec2f(target.pointB, I).length2()) {
						B = target.pointA;
					} else {
						B = target.pointB;
					}
					
					load(object, Circle(B, 0), frameMove);
				}
				
			}
		}
	}

	Vec2f Hit::getReactionVec(Reaction reaction, Vec2f &speed) {
		Vec2f framemove{};
		float speedLenght;
		Vec2f u;

		switch (reaction) {
			case BOUNCE:
				framemove = (n * (2 * n.scalaire(frameMove - vecAF)) - (frameMove - vecAF)) * -1.0f;// * frameMove;

				speedLenght = speed.length();

				speed = framemove;

				speed.setLength(speedLenght);

				break;
			case STOP:
				speed.reset();
				break;
			case ROLL:
				u = n.rotate();

				speed = u * u.scalaire(speed);

				framemove = u * u.scalaire(frameMove - vecAF);
				break;
			case IGNORE:
				framemove = frameMove - getVecToTarget();
				break;
		}

		return framemove;
	}
}