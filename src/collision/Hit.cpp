#include <BlobEngine/Hit.hpp>

#include <cmath>
#include <iostream>

namespace BlobEngine {
	
	float Hit::sng(float x) {
		if (x < 0)
			return -1;
		return 1;
	}
	
	Point2f Hit::getH() {
		//a = (-xb + xf) / (yb - yf)
		//b = -xf (-xb + xf) / (yb - yf) + yf
		
		float a = (-B.x + F.x) / (B.y - F.y);
		float b = F.y - F.x * a;
		float delta = a * a + 1;
		
		//rx = (-a² xa - 2a b + 2a ya + xa) / (a² + 1)
		//ry = (a² ya + 2a xa + 2b - ya) / (a² + 1)
		
		return {
				(-a * a * D.x - 2 * a * b + 2 * a * D.y + D.x) / delta,
				(a * a * D.y + 2 * a * D.x + 2 * b - D.y) / delta
		};
	}
	
	Point2f Hit::getH_line() {
		//a = (-xb + xf) / (yb - yf)
		//b = -xf (-xb + xf) / (yb - yf) + yf
		
		float a = (B.x - C.x) / (B.y - C.y);
		float b = F.y - F.x * a;
		float delta = a * a + 1;
		
		//rx = (-a² xa - 2a b + 2a ya + xa) / (a² + 1)
		//ry = (a² ya + 2a xa + 2b - ya) / (a² + 1)
		
		return {
				(-a * a * D.x - 2 * a * b + 2 * a * D.y + D.x) / delta,
				(a * a * D.y + 2 * a * D.x + 2 * b - D.y) / delta
		};
	}
	
	void Hit::load() {

		float rayonAB = rayonA + rayonB;

		Vec2f vecAB(A, B);
		Vec2f vecAD(A, D);
		
		// si il sont de dirrection opposé
		if (vecAD.scalaire(vecAB) <= 0)
			return;
		
		//si la distance qui les sépare est plus longue que le vecteur vitesse
		if (vecAD.length() <= vecAB.length() - rayonAB)
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
		
		double dr = vecAD.x * vecAD.x + vecAD.y * vecAD.y;

		Point2f p1 = A - B;
		Point2f p2 = D - B;
		double determinant = p1.x * p2.y - p2.x * p1.y;

		//callcul de l'éxisance des point d'intersections
		double delta = rayonAB * rayonAB * dr - determinant * determinant;
		
		if (delta > 0) {
			Point2f i1, i2;
			
			i1.x = static_cast<float>(
					(determinant * vecAD.y + sng(vecAD.y) * vecAD.x * std::sqrt(delta)) / dr);
			i2.x = static_cast<float>(
					(determinant * vecAD.y - sng(vecAD.y) * vecAD.x * std::sqrt(delta)) / dr);
			
			i1.y = static_cast<float>(
					(-determinant * vecAD.x + std::abs(vecAD.y) * std::sqrt(delta)) / dr);
			i2.y = static_cast<float>(
					(-determinant * vecAD.x - std::abs(vecAD.y) * std::sqrt(delta)) / dr);
			
			i1 = i1 + B;
			i2 = i2 + B;
			
			if (Vec2f(A, i1).length2() < Vec2f(A, i2).length2()) {
				if (vecAD.scalaire(Vec2f(A, i1)) > 0) {
					hit = true;
					F = i1;
					
					H = getH();
					G = (H + D) / 2;
				}
			} else {
				if (vecAD.scalaire(Vec2f(A, i2)) > 0) {
					hit = true;
					F = i2;
					
					H = getH();
					G = (H + D) / 2;
				}
			}
		}
	}

	void Hit::load(Line target) {

		Point2f E = target.closestPointTo(A);
		Vec2f vecEA(E, A);
		Vec2f vecAD(A, D);

		double vecEALength = vecEA.length();
		
		if (rayonA + vecAD.length() >= vecEALength) {

			//if (vecEALength >= object.rayon) {
				
				if (vecEA.scalaire(vecAD) < 0) {

					n = vecEA.getNormal();

					Point2f K = vecEA.setLength(rayonA);
					
					Point2f I = target.getIntersectionPoint(Line(K, K + vecAD));

					F = I + n * rayonA;

					Vec2f vecAF(A, F);
					
					if (vecAF.scalaire(vecAD) >= 0) {

						Point2f M = (B + C) / 2;

						if (Vec2f(M, I).length() <= (target.Length() / 2)) {
							
							if (vecAF.length2() < vecAD.length2()) {//ils se touchent forcément

								hit = true;
							}
						}
					}
				}
				/*} else {
					Point2f M = (target.pointA + target.pointB) / 2;
	
					if (Vec2f(M, C).length() <= (target.Length() / 2)) {
						n = vecEA.getNormal();
	
						Point2f G = object.position - n * object.rayon;
	
						rectificationPosition = object.position + Vec2f(G, C);
						
						superposition = true;
						
						hit = true;
					}
				}*/
		}
	}
	
	Point2f Hit::getReactionVec(Reaction reaction, Vec2f &speed) {
		Point2f destination{};
		double speedLenght;

		switch (reaction) {
			case BOUNCE:
				destination = H;

				speedLenght = speed.length();
				
				speed = destination;

				//speed.setLength(speedLenght);
				break;
			case STOP:
				speed.reset();
				break;
			case ROLL:
				destination = G;
				
				speedLenght = speed.length();
				
				speed = destination;
				
				//speed.setLength(speedLenght);
				break;
			case IGNORE:
				destination = D;
				break;
		}
		
		return destination;
	}
	
	const Vec2f &Hit::getRectificationPosition() const {
		return rectificationPosition;
	}
}