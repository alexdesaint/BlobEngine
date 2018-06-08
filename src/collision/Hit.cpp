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
	
	bool Hit::load() {

		float rayonAB = rayonA + rayonB;

		Vec2f vecAB(A, B);
		Vec2f vecAD(A, D);
		
		// si il sont de dirrection opposé
		if (vecAD.scalaire(vecAB) <= 0)
			return false;
		
		//si la distance qui les sépare est plus longue que le vecteur vitesse
		if (vecAD.length() <= vecAB.length() - rayonAB)
			return false;

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
		
		return true;
	}
	
	bool Hit::load(Line target) {

		Point2f E = target.closestPointTo(A);
		Vec2f vecEA(E, A);
		Vec2f vecAD(A, D);

		double vecEALength = vecEA.length();
		
		if (rayonA + vecAD.length() < vecEALength)
			return false;
				
		if (vecEA.scalaire(vecAD) >= 0)
			return false;

		float a = (B.x - C.x) / (B.y - C.y);
		float b = B.y - B.x * a;

		if(a * A.x + b < A.y){
			b += rayonA * std::sqrt(1 + a * a);
		} else {
			b -= rayonA * std::sqrt(1 + a * a);
		}

		float c = (A.x - D.x) / (A.y - D.y);
		float d = A.y - A.x * c;

		float det = (d - c)/(a - b);

		F = {det, a * det + c};

		G = F;
		H = F;

		Point2f M = (B + C) / 2;

		if(Vec2f(M, F).length2() - rayonA * rayonA > (target.Length() / 2) * (target.Length() / 2))
			return false;

		hit = true;
		
		return true;
	}
	
	bool Hit::load2(Line target) {
		
		Vec2f vecEA(E, A);
		Vec2f vecAD(A, D);
		
		Vec2f position =
				vecAD + A; //Vec2f(transform.c * p.x - transform.s * p.y, transform.s * p.x + transform.c * p.y);
		Vec2f s = B - position;
		float b = s.scalaire(s) - rayonA * rayonA;
		
		// Solve quadratic equation.
		Vec2f r = C - B;
		float c = s.scalaire(r);
		float rr = r.scalaire(r);
		float sigma = c * c - rr * b;
		
		// Check for negative discriminant and short segment.
		if (sigma < 0.0f || rr < FLT_EPSILON) {
			return false;
		}
		
		// Find the point of intersection of the line with the circle.
		float a = -(c + sqrt(sigma));
		
		// Is the intersection point on the segment?
		if (0.0f <= a && a <= /*input.maxFraction*/1 * rr) {
			a /= rr;
			//output->fraction = a;
			F = B + (r) * a;
			//output->normal = (s + r * a).getNormal();
			return true;
		}
		
		return false;
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