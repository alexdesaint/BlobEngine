#pragma once

#include <list>
#include <chrono>
#include "Geometrie.hpp"

namespace BlobEngine {

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

		explicit PhysicalObject(unsigned int objectType) : objectType(objectType) { }

		virtual Reaction hit(const PhysicalObject& from) {
			return IGNORE;
		}
	};

	class CircleStatic : PhysicalObject {
		friend class CollisionDetector;
		friend class CircleDynamic;
	private:
		CollisionDetector* collisionDetector;

		static std::list<CircleStatic*> elements;
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
		std::list<Line> lines{};

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
	public:
		/*
		 * Points :
		 * A : centre du cercle en mouvement (object.position)
		 * B : centre du cercle cible (target.position)
		 * F : position du cercle en collision
		 * E : Point sur la trajectoire le plus proche de la cible
		 *
		 * u : vecteur unitaire de la dirrection du glissement
		 * */
		bool hit =  false;

		Vec2f vecAF{};
		Vec2f u{};

		Circle object{};
		Vec2f frameMove{};

	public:
		void load(Circle object, Circle target, Vec2f frameMove) {
			this->object = object;
			this->frameMove = frameMove;

			float RayonAB = object.rayon + target.rayon;

			Vec2f vecAB(object.position, target.position);

			if (frameMove.length() > vecAB.length() - RayonAB) {//si la distance qui les sépare est plus courte que le vecteur vitesse

				if (frameMove.scalaire(vecAB) > 0) {// si il ne sont pas de dirrection opposé

					float AE = Vec2f(frameMove).normalize().scalaire(vecAB);//distance avant le point le plus proche

					float BE2 = vecAB.length2() - AE * AE;

					float RayonAB2 = RayonAB * RayonAB;

					if (BE2 < RayonAB2) {

						float AF = AE - std::sqrt(RayonAB2 - BE2);

						if (AF < frameMove.length()) {
							//ils se touche forcément
							vecAF = Vec2f(frameMove).setLength(AF);

							Vec2f vecFB = vecAB - vecAF;

							u = vecFB.rotate().normalize();

							hit = true;
						}
					}
				}
			}
		}

		void load(Circle object, Line target, Vec2f frameMove) {

			Point2f F = target.closestPointTo(object.position);
			Vec2f vecFA(F, object.position);

			if (object.rayon + frameMove.length() > vecFA.length()) {
				if (vecFA.scalaire(frameMove) < 0) {

					Point2f D = object.position + frameMove;

					Point2f I = target.getIntersectionPoint(Line(D, object.position + Vec2f(object.position, F).setLength(object.rayon)));

					Point2f E = target.getIntersectionPoint(Line(D, object.position));

					Point2f M = (target.pointA + target.pointB) / 2;

					if (Vec2f(M, I).length() <= (target.Length() / 2)) {

						Point2f F = E - (frameMove * object.rayon * Vec2f(E, object.position).length()) /
										(vecFA.length() * frameMove.length());

						vecAF = Vec2f(object.position, F);

						Vec2f vecEA(E, object.position);

						if (vecAF.length2() < frameMove.length2() || vecEA.length2() < object.rayon * object.rayon) {

							//ils se touchent forcément

							hit = true;

							u = target.getVector().normalize();
						}
					} else if (Vec2f(M, I).length() <= (target.Length() / 2 + object.rayon)) {
						Point2f B;

						if (Vec2f(target.pointA, E).length2() < Vec2f(target.pointB, E).length2()) {
							B = target.pointA;
						} else {
							B = target.pointB;
						}

						load(object, Circle(B, 0), frameMove);
					}
				}
			}
		}

		Collision(Circle object, Circle target, Vec2f frameMove) : object(object), frameMove(frameMove) {
			load(object, target, frameMove);
		}

		Collision(Circle object, Line target, Vec2f frameMove) : object(object), frameMove(frameMove) {
			load(object, target, frameMove);
		}

		bool hitTarget() {
			return hit;
		}

		Vec2f getRoll(Vec2f *speed) {

			*speed = u * u.scalaire(*speed);

			Vec2f vecFH = u * u.scalaire(frameMove - vecAF);

			return vecAF + vecFH;
		}
	};

	class CollisionDetector {
		friend class CircleStatic;
		friend class CircleDynamic;
		friend class LineStatic;
		friend class LineDynamic;

	private:

		std::list<CircleDynamic*>	CircleDynamicElements{};
		std::list<LineStatic*>		LineStaticElements{};

		float timeFlow{};

		float getElapsedTime();

		static bool collision(CircleStatic circle1, CircleStatic circle2);

		bool checkCollision(CircleDynamic *object);

	public:
		CollisionDetector() {
			timeFlow = getElapsedTime();
		}

		void update() {
			timeFlow = getElapsedTime();
		}
	};
}