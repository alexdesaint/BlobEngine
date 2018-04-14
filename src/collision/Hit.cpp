#include <BlobEngine/Hit.hpp>

#include <cmath>
#include <iostream>


namespace BlobEngine {

	double round(double v) {
		return std::round(v * 1000) / 1000;
	}

	void Hit::load(Circle object, Point2f target) {

		Vec2f vecAB(object.position, target);

		if (frameMove.length() >
			vecAB.length() - object.rayon) {//si la distance qui les sépare est plus courte que le vecteur vitesse

			if (frameMove.scalaire(vecAB) > 0) {// si il ne sont pas de dirrection opposé

				Point2f E = Line(object.position, object.position + frameMove).closestPointTo(target);

				double BE2 = Vec2f(target, E).length2();

				double RayonAB2 = object.rayon * object.rayon;

				if (BE2 < RayonAB2) {

					double AE = Vec2f(object.position, E).length();

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

				double BE2 = vecAB.length2() - AE * AE;

				double RayonAB2 = RayonAB * RayonAB;

				if (BE2 < RayonAB2) {

					double AF = AE - std::sqrt(RayonAB2 - BE2);

					if (AF > 0.01f) {
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
	}

	void Hit::load(Circle object, Line target) {

		Point2f C = target.closestPointTo(object.position);
		Vec2f vecCA(C, object.position);

		double vecCALength = vecCA.length();

		if (object.rayon + frameMove.length() >= vecCALength) {

			if (vecCALength >= object.rayon) {

				if (vecCA.scalaire(frameMove) < 0) {

					n = vecCA.getNormal();

					Point2f G = object.position - n * object.rayon;

					Point2f I = target.getIntersectionPoint(Line(G, G + frameMove));

					Point2f F = I + n * object.rayon;

					vecAF = Vec2f(object.position, F);

					if (vecAF.scalaire(frameMove) > 0) {

						Point2f M = (target.pointA + target.pointB) / 2;

						if (Vec2f(M, I).length() <= (target.Length() / 2)) {

							if (vecAF.length2() < frameMove.length2()) {//ils se touchent forcément

								hit = true;
							}
						}
					}
				}
			} else {
				Point2f M = (target.pointA + target.pointB) / 2;

				if (Vec2f(M, C).length() <= (target.Length() / 2)) {
					//std::cout << "superposition detected" << std::endl;
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

		if (framemove.x < 0.1f)
			framemove.x = 0.0f;

		if (framemove.y < 0.1f)
			framemove.y = 0.0f;

		return framemove;
	}
}