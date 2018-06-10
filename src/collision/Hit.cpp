#include <BlobEngine/Hit.hpp>

#include <cmath>

namespace BlobEngine {
	
	bool Hit::load2() {
		float rayonAB = rayonA + rayonB;
		
		Vec2f vecAB(A, B);
		Vec2f vecAD(A, D);
		
		// si il sont de dirrection opposé
		if (vecAD.scalaire(vecAB) <= 0)
			return false;
		
		//si la distance qui les sépare est plus longue que le vecteur vitesse
		if (vecAD.length() <= vecAB.length() - rayonAB)
			return false;
		
		float dr = vecAD.x * vecAD.x + vecAD.y * vecAD.y;
		
		Point2f p1 = A - B;
		Point2f p2 = D - B;
		float determinant = p1.x * p2.y - p2.x * p1.y;
		
		//callcul de l'éxisance des point d'intersections
		float delta = rayonAB * rayonAB * dr - determinant * determinant;
		
		if (delta > 0) {
			Point2f i1, i2;
			
			i1.x = (determinant * vecAD.y + sng(vecAD.y) * vecAD.x * std::sqrt(delta)) / dr;
			i2.x = (determinant * vecAD.y - sng(vecAD.y) * vecAD.x * std::sqrt(delta)) / dr;
			
			i1.y = (-determinant * vecAD.x + std::abs(vecAD.y) * std::sqrt(delta)) / dr;
			i2.y = (-determinant * vecAD.x - std::abs(vecAD.y) * std::sqrt(delta)) / dr;
			
			i1 = i1 + B;
			i2 = i2 + B;
			
			if (Vec2f(A, i1).length2() < Vec2f(A, i2).length2()) {
				if (vecAD.scalaire(Vec2f(A, i1)) > 0) {
					F = i1;
					
					vecAF = Vec2f(A, F);
					
					n = Vec2f(F, B).getNormal();
					
					return true;
				}
			} else {
				if (vecAD.scalaire(Vec2f(A, i2)) > 0) {
					F = i2;
					
					vecAF = Vec2f(A, F);
					
					n = Vec2f(F, B).getNormal();
					
					return true;
				}
			}
		}
		
		return false;
	}
	
	void Hit::load(Circle object, Circle target) {

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

	void Hit::load(Circle object, Line target) {

		Point2f C = target.closestPointTo(object.position);
		Vec2f vecCA(C, object.position);

		if (object.rayon + frameMove.length() >= vecCA.length() && vecCA.length() >= 3 * object.rayon / 4) {

			if (vecCA.scalaire(frameMove) < 0) {

				n = vecCA.getNormal();

				Point2f G = object.position - n * object.rayon;
				
				Point2f I = target.getIntersectionPoint(Line(G, G + frameMove));
				
				Point2f M = (target.pointA + target.pointB) / 2;

				if (Vec2f(M, I).length() <= (target.Length() / 2)) {

					Point2f F = I + n * object.rayon;

					vecAF = Vec2f(object.position, F);

					if (vecAF.length2() < frameMove.length2()) {

						//ils se touchent forcément

						hit = true;
					}
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