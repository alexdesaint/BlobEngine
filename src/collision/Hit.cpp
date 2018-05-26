#include <BlobEngine/Hit.hpp>

#include <cmath>
#include <iostream>

float sng(float x) {
	if (x < 0)
		return -1;
	return 1;
}

namespace BlobEngine {

	void Hit::load() {

		float rayonAB = rayonA + rayonB;

		Vec2f vecAB(A, B);

		//si la distance qui les sépare est plus longue que le vecteur vitesse
		if (frameMove.length() <= vecAB.length() - rayonAB)
			return;

		/*
		//si ils sont en superposition
		if (vecAB.length2() < rayonAB * rayonAB) {
			Vec2f newAB = Vec2f(vecAB).setLength(rayonAB);
			
			Vec2f coor = vecAB - newAB;
			rectificationPosition = A + coor;
			
			superposition = true;
			hit = true;
		}
		*/

		// si il sont de dirrection opposé
		if (frameMove.scalaire(vecAB) <= 0)
			return;

		double dr = pow(frameMove.x, 2) + pow(frameMove.y, 2);

		Point2f p1 = A - B;
		Point2f p2 = D - B;
		double determinant = p1.x * p2.y - p2.x * p1.y;

		//callcul de l'éxisance des point d'intersections
		double delta = rayonAB * rayonAB * dr - determinant * determinant;

		if (delta == 0) {
			hit = true;

			Point2f i;

			i.x = static_cast<float>((determinant * frameMove.y) / dr);
			i.y = static_cast<float>((-determinant * frameMove.x) / dr);

			F = i + B;

			n = Vec2f((vecAB * -1.0f) + Vec2f(A, F)).getNormal();
		} else if (delta > 0) {
			Point2f i1, i2;
			
			i1.x = static_cast<float>(
					(determinant * frameMove.y + sng(frameMove.y) * frameMove.x * std::sqrt(delta)) / dr);
			i2.x = static_cast<float>(
					(determinant * frameMove.y - sng(frameMove.y) * frameMove.x * std::sqrt(delta)) / dr);
			
			i1.y = static_cast<float>(
					(-determinant * frameMove.x + std::abs(frameMove.y) * std::sqrt(delta)) / dr);
			i2.y = static_cast<float>(
					(-determinant * frameMove.x - std::abs(frameMove.y) * std::sqrt(delta)) / dr);
			
			i1 = i1 + B;
			i2 = i2 + B;
			
			if (Vec2f(A, i1).length2() < Vec2f(A, i2).length2()) {
				if (frameMove.scalaire(Vec2f(A, i1)) > 0) {
					hit = true;
					F = i1;
					
					n = Vec2f((vecAB * -1.0f) + Vec2f(A, F)).getNormal();
				}
			} else {
				if (frameMove.scalaire(Vec2f(A, i2)) > 0) {
					hit = true;
					F = i2;
					
					n = Vec2f((vecAB * -1.0f) + Vec2f(A, F)).getNormal();
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

					Point2f G{object.position.x - n.x * object.rayon, object.position.y - n.y * object.rayon};

					Point2f I = target.getIntersectionPoint(Line(G, G + frameMove));

					F = I + n * object.rayon;

					Vec2f vecAF = Vec2f(object.position, F);
					
					if (vecAF.scalaire(frameMove) >= 0) {

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
					n = vecCA.getNormal();

					Point2f G = object.position - n * object.rayon;

					rectificationPosition = object.position + Vec2f(G, C);
					
					superposition = true;
					
					hit = true;
				}
			}
		}
	}

	Vec2f Hit::getReactionVec(Reaction reaction, Vec2f &speed) {
		Vec2f framemove{};
		double speedLenght;
		Vec2f u, vecFD = Vec2f(F, D);

		switch (reaction) {
			case BOUNCE:
				framemove = (n * (2 * n.scalaire(vecFD)) - vecFD) * -1.0f;

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

				framemove = u * u.scalaire(vecFD);
				break;
			case IGNORE:
				framemove = vecFD;
				break;
		}

		return framemove;
	}
	
	const Vec2f &Hit::getRectificationPosition() const {
		return rectificationPosition;
	}
}