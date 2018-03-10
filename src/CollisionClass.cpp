#include <list>
#include <iostream>
#include <cmath>

#include "Geometrie.hpp"
#include "CollisionClass.hpp"

using namespace Physics;
using namespace Geometrie;

//CircleStatic

void CircleStatic::enableCollision() {
	collisionDetector->CircleStaticElements.push_back(this);
}

void CircleStatic::disableCollision() {
	collisionDetector->CircleStaticElements.remove(this);
}

//CircleDynamic

CircleDynamic::~CircleDynamic() {
	disableCollision();
}

void CircleDynamic::enableCollision() {
	collisionDetector->CircleDynamicElements.push_back(this);
}

void CircleDynamic::disableCollision() {
	collisionDetector->CircleDynamicElements.remove(this);
}

bool CircleDynamic::CheckCollision() {
	return collisionDetector->checkCollision(this);
}

bool CircleDynamic::HitCircle(CircleStatic *circleStatic) {

}

//LineStatic
void LineStatic::enableCollision() {
	collisionDetector->LineStaticElements.push_back(this);
}

void LineStatic::disableCollision() {
	collisionDetector->LineStaticElements.remove(this);
}

//CollisionDetector

float CollisionDetector::getElapsedTime() {
	static std::chrono::high_resolution_clock::time_point lastFrameTime;

	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> diff = now - lastFrameTime;

	lastFrameTime = now;

	return diff.count();
}

bool CollisionDetector::collision(CircleStatic circle1, CircleStatic circle2) {
	return Line(circle1.mainCircle.position, circle2.mainCircle.position).Length() <= (circle1.mainCircle.rayon + circle2.mainCircle.rayon);
}

bool CollisionDetector::checkCollision(CircleDynamic *Object) {

	Vec2f frameMove = Object->speed * timeFlow;

	bool hit = false;
	for (CircleDynamic *target : CircleDynamicElements) {
		if (target != Object) {
			if(computeCollision(Object, target->mainCircle, &frameMove)) {
				hit = true;
				target->hit(*Object);
			}
		}
	}

	for (CircleStatic *target : CircleStaticElements) {
		if(computeCollision(Object, target->mainCircle, &frameMove)){
			hit = true;
			target->hit(*Object);
		}
	}

	for (LineStatic *target : LineStaticElements) {
		if(computeCollision(Object, target, &frameMove)){
			hit = true;
			target->hit(*Object);
		}
	}

	Object->mainCircle.position = Object->mainCircle.position + frameMove;

	return hit;
}

bool CollisionDetector::computeCollision(CircleDynamic *object, Circle target, Vec2f *frameMove) {
	float RayonAB = object->mainCircle.rayon + target.rayon;

	if (frameMove->Length() > Distance(object->mainCircle.position, target.position) - RayonAB) {//si la distance qui les sépare est plus courte que le vecteur vitesse
		Vec2f vecAC = *frameMove;
		Vec2f vecAB(object->mainCircle.position, target.position);

		if (ProduitScalaire(vecAC, vecAB) > 0) {// si il ne sont pas de dirrection opposé

			float AE = ProduitScalaire(Vec2f(vecAC).Normalize(), vecAB);//distance avant le point le plus proche

			float BE = vecAB.Length() - AE;

			if (BE < RayonAB) {

				float EF = RayonAB - BE;
				float AF = AE - EF;

				if (AF < vecAC.Length()) {
					//ils se touche forcément
					//maintenant on calcul le vecteur tangente

					//Calcul de F

					Point2f A = object->mainCircle.position;

					Vec2f vecAF = Vec2f(vecAC).setLength(AF);

					Point2f F = A + vecAF;

					Vec2f vecFB(F, target.position);

					Vec2f u = Vec2f(-vecFB.y, vecFB.x).Normalize();

					Vec2f vecFH = u * ProduitScalaire(u, Vec2f(F, A + vecAC));

					frameMove->x = vecAF.x + vecFH.x;
					frameMove->y = vecAF.y + vecFH.y;

					Vec2f vecGI = u * ProduitScalaire(u, object->speed);

					object->speed.x = vecGI.x;
					object->speed.y = vecGI.y;

					//std::cout <<
					//	"A = (" << A.x << ", " << A.y << ") => " <<
					//	"C = (" << vecAC.x + A.x << ", " << vecAC.y + A.y << ") --> " <<
					//	"vecAH = (" << speed->x << ", " << speed->y << ")" << std::endl;

					return true;
				}
			}
		}
	} else
		return false;
}

bool CollisionDetector::computeCollision(CircleDynamic *object, LineStatic *lines, Vec2f *frameMove) {

	bool hit = false;
	for (Line target : lines->lines) {
		Point2f F = ClosestPointOnLine(target, object->mainCircle.position);
		Vec2f vecFA(F, object->mainCircle.position);

		if (object->mainCircle.rayon + frameMove->Length() > vecFA.Length()) {
			if (ProduitScalaire(vecFA, *frameMove) < 0) {

				Point2f E, I;
				Vec2f vecAD = *frameMove;
				Point2f D = object->mainCircle.position + vecAD;

				//std::cout <<
				//	"A = (" << object.Position.x << ", " << object.Position.y << ") => " <<
				//	"B = (" << target.PointA.x << ", " << target.PointA.y  << ") --> " <<
				//	"C = (" << target.PointB.x << ", " << target.PointB.y << ") --> " <<
				//	"D = (" << D.x << ", " << D.y << ")" << std::endl;

				if (Intersection(target, Line(D, object->mainCircle.position +
												 Vec2f(object->mainCircle.position, F).setLength(
														 object->mainCircle.rayon)), &I)) {

					Intersection(target, Line(D, object->mainCircle.position), &E);
					//cercle de milieu de du segment à demi seg + rayon cercle

					Point2f M = (target.pointA + target.pointB) / 2;

					if (Vec2f(M, I).Length() <= (target.Length() / 2)) {

						Point2f G = E - (vecAD * object->mainCircle.rayon *
										 Vec2f(E, object->mainCircle.position).Length()) /
										(vecFA.Length() * vecAD.Length());

						Vec2f vecAG(object->mainCircle.position, G);

						Vec2f vecEA(E, object->mainCircle.position);

						if (vecAG.Length2() < vecAD.Length2() ||
							vecEA.Length2() < object->mainCircle.rayon * object->mainCircle.rayon) {

							//Rebond : vecGK

							//point2f J = object.Position - (F - ClosestPointOnLine(target, G)) * 2;
							//Vec2f vecGK(G, J);
							//vecGK.setLength(Vec2f(G, D).Length());

							Vec2f vecGI = target.getVector().Normalize() *
										  ProduitScalaire(target.getVector().Normalize(), Vec2f(G, D));

							frameMove->x = vecAG.x + vecGI.x;
							frameMove->y = vecAG.y + vecGI.y;

							Vec2f vecGJ = target.getVector().Normalize() *
										  ProduitScalaire(target.getVector().Normalize(), object->speed);

							object->speed.x = vecGJ.x;
							object->speed.y = vecGJ.y;

							hit = true;
						}
					} else if (Vec2f(M, I).Length() <= (target.Length() / 2 + object->mainCircle.rayon)) {
						Point2f B;

						if (Vec2f(target.pointA, E).Length2() < Vec2f(target.pointB, E).Length2()) {
							B = target.pointA;
						} else {
							B = target.pointB;
						}
/*
						float RayonAB = object->mainCircle.rayon;
						Vec2f vecAB(object->mainCircle.position, B);
						Vec2f vecAC = *frameMove;
						float AE = ProduitScalaire(Vec2f(vecAC).Normalize(), vecAB);
						float BE = vecAB.Length() - AE;
						float EF = RayonAB - BE;
						float AF = AE - EF;

						Point2f A = object->mainCircle.position;

						Vec2f vecAF = Vec2f(vecAC).setLength(AF);

						Point2f F = A + vecAF;

						Vec2f vecFB(F, B);

						Vec2f u = Vec2f(-vecFB.y, vecFB.x).Normalize();

						Vec2f vecFH = u * ProduitScalaire(u, Vec2f(F, A + *frameMove));

						frameMove->x = vecAF.x + vecFH.x;
						frameMove->y = vecAF.y + vecFH.y;

						Vec2f vecGI = u * ProduitScalaire(u, object->speed);

						object->speed.x = vecGI.x;
						object->speed.y = vecGI.y;

						hit = true;
						*/
						hit = computeCollision(object, Circle(B, 0), frameMove);
					}
				}
			}
		}
	}

	return hit;
}