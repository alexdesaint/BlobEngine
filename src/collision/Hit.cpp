#include <BlobEngine/Hit.hpp>

#include <cmath>


namespace BlobEngine {

	double round(double v) {
		return std::round(v * 1000) / 1000;
	}

	void Hit::load(Circle object, Point2f target) {

		Vec2f vecAB(object.position, target);

		if (frameMove.length() >
			vecAB.length() - object.rayon) {//si la distance qui les sépare est plus courte que le vecteur vitesse

			if (frameMove.scalaire(vecAB) > 0) {// si il ne sont pas de dirrection opposé

				double AE = Vec2f(frameMove).getNormal().scalaire(vecAB);//distance avant le point le plus proche

				double BE2 = round(vecAB.length2() - AE * AE);

				double RayonAB2 = object.rayon * object.rayon;

				if (BE2 < RayonAB2) {

					double AF = AE - std::sqrt(RayonAB2 - BE2);

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

	void Hit::load(Circle object, Circle target) {

		double RayonAB = object.rayon + target.rayon;

		Vec2f vecAB(object.position, target.position);

		if (frameMove.length() >
			vecAB.length() - RayonAB) {//si la distance qui les sépare est plus courte que le vecteur vitesse

			if (frameMove.scalaire(vecAB) > 0) {// si il ne sont pas de dirrection opposé

				double AE = Vec2f(frameMove).getNormal().scalaire(vecAB);//distance avant le point le plus proche

				double BE2 = round(vecAB.length2() - AE * AE);

				double RayonAB2 = RayonAB * RayonAB;

				if (BE2 < RayonAB2) {

					double AF = AE - std::sqrt(RayonAB2 - BE2);

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

				if (Vec2f(I, G).scalaire(frameMove) < 0) {

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
	}

	Vec2f Hit::getReactionVec(Reaction reaction, Vec2f &speed) {
		Vec2f framemove{};
		double speedLenght;
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
		framemove.round(2);
		speed.round(2);


		return framemove;
	}
}