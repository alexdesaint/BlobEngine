#include <BlobEngine/Hit.hpp>

#include <cmath>
#include <iostream>


namespace BlobEngine {

	double round(double v) {
		return std::round(v * 1000) / 1000;
	}

	void Hit::load(Circle object, Circle target) {

		double RayonAB = object.rayon + target.rayon;
		
		Vec2i vecAB(A, B);
		
		double moveLength = frameMove.length();
		
		if (frameMove.length() >
			vecAB.length() - RayonAB) {//si la distance qui les sépare est plus courte que le vecteur vitesse
			
			double length2 = vecAB.length2();
			
			if (vecAB.length2() >= RayonAB * RayonAB) {
				
				if (frameMove.scalaire(vecAB) > 0) {// si il ne sont pas de dirrection opposé
					
					Point2i E = Line(A, A + frameMove).closestPointTo(B);
					
					double BE2 = Vec2i(B, E).length2();
					
					double RayonAB2 = RayonAB * RayonAB;
					
					if (BE2 < RayonAB2) {
						
						double AE = Vec2i(A, E).length();
						
						double AF = AE - std::sqrt(RayonAB2 - BE2);
						
						if (AF < frameMove.length()) {
							//ils se touche forcément
							vecAF = Vec2i(frameMove).setLength(AF);
							
							Vec2i vecFB = (vecAB * -1.0f) + vecAF;
							
							n = vecFB.getNormal();
							
							hit = true;
						}
					}
				}
			} else {
				Vec2i newAB = Vec2i(vecAB).setLength(object.rayon + target.rayon);
				
				Vec2i coor = vecAB - newAB;
				rectificationPosition = object.position + coor;
				
				superposition = true;
				hit = true;
			}
		}
	}

	void Hit::load(Circle object, Line target) {
		
		Point2i C = target.closestPointTo(object.position);
		Vec2i vecCA(C, object.position);

		double vecCALength = vecCA.length();

		if (object.rayon + frameMove.length() >= vecCALength) {

			if (vecCALength >= object.rayon) {

				if (vecCA.scalaire(frameMove) < 0) {

					n = vecCA.getNormal();
					
					Point2i G{object.position.x - n.x * object.rayon, object.position.y - n.y * object.rayon};
					
					Point2i I = target.getIntersectionPoint(Line(G, G + frameMove));
					
					Point2i F = I + n * object.rayon;
					
					vecAF = Vec2i(object.position, F);
					
					if (vecAF.scalaire(frameMove) >= 0) {
						
						Point2i M = (target.pointA + target.pointB) / 2;
						
						if (Vec2i(M, I).length() <= (target.Length() / 2)) {

							if (vecAF.length2() < frameMove.length2()) {//ils se touchent forcément

								hit = true;
							}
						}
					}
				}
			} else {
				Point2i M = (target.pointA + target.pointB) / 2;
				
				if (Vec2i(M, C).length() <= (target.Length() / 2)) {
					n = vecCA.getNormal();
					
					Point2i G = object.position - n * object.rayon;
					
					rectificationPosition = object.position + Vec2i(G, C);
					
					superposition = true;
					
					hit = true;
				}
			}
		}
	}

	Vec2f Hit::getReactionVec(Reaction reaction, Vec2f &speed) {
		Vec2i framemove{};
		double speedLenght;
		Vec2i u;

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
	
	const Vec2f &Hit::getRectificationPosition() const {
		return rectificationPosition;
	}
}