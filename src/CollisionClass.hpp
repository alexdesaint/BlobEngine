#pragma once

#include <list>
#include <chrono>
#include "Geometrie.hpp"

namespace Physics {
	using namespace Geometrie;

	enum Reaction{
		BOUNCE,
		STOP,
		ROLL,
		IGNORE
	};

	class CollisionDetector;

	class CircleDynamic;

	class PhysicalObject{
	public:
		unsigned int objectType;

		explicit PhysicalObject(unsigned int objectType) : objectType(objectType) { };

		virtual Reaction hit(const PhysicalObject& from) { }
	};

	class CircleStatic : PhysicalObject {
		friend class CollisionDetector;
		friend class CircleDynamic;
	private:
		CollisionDetector* collisionDetector;

	protected:
		Circle mainCircle{};
		std::list<Circle> circles{};

		virtual void enableCollision();

		virtual void disableCollision();

	public:
		explicit CircleStatic(CollisionDetector* c, unsigned int objectType) : PhysicalObject(objectType), collisionDetector(c) {
			enableCollision();
		}

		virtual ~CircleStatic() {
			disableCollision();
		}
	};

	class CircleDynamic : CircleStatic{
		friend class CollisionDetector;

	protected:
		Vec2f speed{};
		Circle mainCircle{};

		bool CheckCollision();
		bool HitCircle(CircleStatic *circleStatic);

		void enableCollision() override;
		void disableCollision() override;

	public:
		explicit CircleDynamic(CollisionDetector* c, unsigned int objectType) : CircleStatic(c, objectType){
			enableCollision();
		}
		~CircleDynamic() override;
	};

	class LineStatic  : PhysicalObject {
		friend class CollisionDetector;
	private:
		CollisionDetector* collisionDetector;

	protected:
		std::list<Geometrie::Line> lines{};

		virtual void enableCollision();

		virtual void disableCollision();

	public:
		explicit LineStatic(CollisionDetector* c, unsigned int objectType) : PhysicalObject(objectType), collisionDetector(c) {
			enableCollision();
		}

		~LineStatic() {
			disableCollision();
		}
	};

	class Collision {
	private:
		/*
		 * Points :
		 * A : centre du cercle en mouvement (object.position)
		 * B : centre du cercle cible (target.position)
		 * F : position du cercle en collision
		 * E : Point sur la trajectoire le plus proche de la cible
		 *
		 * */
		bool hit =  false;

		Vec2f vecAF{};

		Circle object{};
		Vec2f frameMove{};

		Circle target{};

	public:
		void load(Circle object, Circle target, Vec2f frameMove) {
			this->object = object;
			this->target = target;
			this->frameMove = frameMove;

			float RayonAB = object.rayon + target.rayon;

			if (frameMove.Length() > Distance(object.position, target.position) - RayonAB) {//si la distance qui les sépare est plus courte que le vecteur vitesse

				Vec2f vecAB(object.position, target.position);

				if (ProduitScalaire(frameMove, vecAB) > 0) {// si il ne sont pas de dirrection opposé

					float AE = ProduitScalaire(Vec2f(frameMove).Normalize(), vecAB);//distance avant le point le plus proche

					float BE = vecAB.Length() - AE;

					if (BE < RayonAB) {

						float AF = AE - RayonAB - BE;

						if (AF < frameMove.Length()) {
							//ils se touche forcément
							vecAF = Vec2f(frameMove).setLength(AF);

							hit = true;
						}
					}
				}
			}

			hit = false;
		}

		void load(Circle object, Line target, Vec2f frameMove) {
			bool hit = false;

			Point2f F = ClosestPointOnLine(target, object.position);
			Vec2f vecFA(F, object.position);

			if (object.rayon + frameMove.Length() > vecFA.Length()) {
				if (ProduitScalaire(vecFA, frameMove) < 0) {

					Point2f E, I;
					Point2f D = object.position + frameMove;

					if (Intersection(target, Line(D, object.position + Vec2f(object.position, F).setLength(object.rayon)), &I)) {

						Intersection(target, Line(D, object.position), &E);
						//cercle de milieu de du segment à demi seg + rayon cercle

						Point2f M = (target.pointA + target.pointB) / 2;

						if (Vec2f(M, I).Length() <= (target.Length() / 2)) {

							Point2f G = E - (frameMove * object.rayon * Vec2f(E, object.position).Length()) /
											(vecFA.Length() * frameMove.Length());

							Vec2f vecAG(object.position, G);

							Vec2f vecEA(E, object.position);

							if (vecAG.Length2() < frameMove.Length2() || vecEA.Length2() < object.rayon * object.rayon) {

								//ils se touchent forcément

								hit = true;
							}
						} else if (Vec2f(M, I).Length() <= (target.Length() / 2 + object.rayon)) {
							Point2f B;

							if (Vec2f(target.pointA, E).Length2() < Vec2f(target.pointB, E).Length2()) {
								B = target.pointA;
							} else {
								B = target.pointB;
							}

							//hit = load(object, Circle(B, 0), frameMove);
						}
					}
				}
			}


			hit = false;
		}

		Collision(Circle object, Circle target, Vec2f frameMove) : object(object), target(target), frameMove(frameMove) {
			load(object, target, frameMove);
		}

		bool hitTarget() {
			return hit;
		}

		Vec2f getFrameMove() {
			return frameMove;
		}

		Vec2f getBounce(Vec2f speed) {

			Point2f F = object.position + vecAF;

			Vec2f vecFB(F, target.position);

			Vec2f u = Vec2f(-vecFB.y, vecFB.x).Normalize();

			Vec2f vecFH = u * ProduitScalaire(u, Vec2f(F, object.position + frameMove));

			frameMove.x = vecAF.x + vecFH.x;
			frameMove.y = vecAF.y + vecFH.y;

			return u * ProduitScalaire(u, speed);
		}

		/*Vec2f getRoll() {

			Vec2f vecGI = target.getVector().Normalize() * ProduitScalaire(target.getVector().Normalize(), Vec2f(G, D));

			frameMove->x = vecAG.x + vecGI.x;
			frameMove->y = vecAG.y + vecGI.y;

			Vec2f vecGJ = target.getVector().Normalize() *
						  ProduitScalaire(target.getVector().Normalize(), object->speed);

			object->speed.x = vecGJ.x;
			object->speed.y = vecGJ.y;
		}*/
	};

	class CollisionDetector {
		friend class CircleStatic;
		friend class CircleDynamic;
		friend class LineStatic;
		friend class LineDynamic;

	private:
		std::list<CircleStatic*>	CircleStaticElements{};
		std::list<CircleDynamic*>	CircleDynamicElements{};
		std::list<LineStatic*>		LineStaticElements{};

		float timeFlow{};

		float getElapsedTime();

		static bool collision(CircleStatic circle1, CircleStatic circle2);

		bool checkCollision(CircleDynamic *Object);

		bool computeCollision(CircleDynamic *object, Circle target, Vec2f *frameMove);

		bool computeCollision(CircleDynamic *object, LineStatic *lines, Vec2f *frameMove);

	public:
		CollisionDetector() {
			timeFlow = getElapsedTime();
		}

		void update() {
			timeFlow = getElapsedTime();
		}
	};
}