#pragma once

#include <list>
#include <chrono>
#include <iostream>
#include "Geometrie.hpp"

namespace BlobEngine {

	enum Reaction{
		BOUNCE,
		STOP,
		ROLL,
		IGNORE
	};

	class CollisionDetector;

	class PhysicalObject{
		friend CollisionDetector;
	protected:
		static CollisionDetector* collisionDetector;
	public:
		unsigned int objectType;

		explicit PhysicalObject(unsigned int objectType) : objectType(objectType) { }

		virtual Reaction hit(const PhysicalObject& from) {
			return IGNORE;
		}
	};

	class CircleStatic : PhysicalObject {
		friend class CollisionDetector;
	private:
		static std::list<CircleStatic*> elements;
		std::list<CircleStatic*>::iterator elementIt{};
	protected:
		Circle mainCircle{};
		//std::list<Circle> circles{};

		void enableCollision() {
			elements.push_front(this);
			elementIt = elements.begin();
		}

		void disableCollision() {
			elements.erase(elementIt);
		}

	public:
		explicit CircleStatic(unsigned int objectType) : PhysicalObject(objectType) {
			enableCollision();
		}

		virtual ~CircleStatic() {
			disableCollision();
		}
	};

	class CircleDynamic : PhysicalObject {
		friend class CollisionDetector;
	private:
		static std::list<CircleDynamic*> elements;
		std::list<CircleDynamic*>::iterator elementIt{};
	protected:
		Vec2f speed{};
		Circle mainCircle{};

		void enableCollision() {
			elements.push_front(this);
			elementIt = elements.begin();
		}

		void disableCollision() {
			elements.erase(elementIt);
		}

	public:
		explicit CircleDynamic(unsigned int objectType) : PhysicalObject(objectType){
			enableCollision();
		}

		~CircleDynamic() {
			disableCollision();
		}
	};

	class LineStatic  : PhysicalObject {
		friend class CollisionDetector;
	private:
		static std::list<LineStatic*> elements;
		std::list<LineStatic*>::iterator elementIt{};
	protected:
		std::list<Line> lines{};

		void enableCollision() {
			elements.push_front(this);
			elementIt = elements.begin();
		}

		void disableCollision() {
			elements.erase(elementIt);
		}

	public:
		explicit LineStatic(unsigned int objectType) : PhysicalObject(objectType) {
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
		 *
		 * D : A + vecteur vitesse
		 * E : Point sur la trajectoire le plus proche de la cible
		 *
		 * u : normalized vector
		 * */
		bool hit =  false;

		Vec2f vecAF{};
		Vec2f n{};

		Vec2f frameMove{};

		PhysicalObject *target;

	public:
		void load(Circle object, Circle target, Vec2f frameMove) {
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

							Vec2f vecFB = (vecAB *  -1.0f) + vecAF;

							n = vecFB.normalize();

							hit = true;
						}
					}
				}
			}
		}

		void load(Circle object, Line target, Vec2f frameMove) {

			Point2f C = target.closestPointTo(object.position);
			Vec2f vecCA(C, object.position);
			n = vecCA.normalize();

			if (object.rayon + frameMove.length() > vecCA.length()) {
				if (vecCA.scalaire(frameMove) < 0) {

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
					} else if (Vec2f(M, I).length() <= (target.Length() / 2 + object.rayon)) {
						Point2f B;

						if (Vec2f(target.pointA, I).length2() < Vec2f(target.pointB, I).length2()) {
							B = target.pointA;
						} else {
							B = target.pointB;
						}

						load(object, Circle(B, 0), frameMove);
					}
				}
			}
		}

		Collision(Circle object, Circle circleTarget, Vec2f frameMove, PhysicalObject *target) : frameMove(frameMove), target(target) {
			load(object, circleTarget, frameMove);
		}

		Collision(Circle object, Line lineTarget, Vec2f frameMove, PhysicalObject *target) : frameMove(frameMove), target(target) {
			load(object, lineTarget, frameMove);
		}

		bool hitTarget() {
			return hit;
		}

		Vec2f getRoll(Vec2f *speed) {

			Vec2f u = n.rotate();

			*speed = u * u.scalaire(*speed);

			Vec2f vecFH = u * u.scalaire(frameMove - vecAF);

			return vecAF + vecFH;
		}

		Vec2f getBounce(Vec2f *speed) {
			Vec2f vecFH = (n * (2 * n.scalaire(frameMove - vecAF)) - (frameMove - vecAF)) * -1.0f;// * frameMove;

			float speedLenght = speed->length();

			*speed = vecFH;

			speed->setLength(speedLenght);

			return vecAF + vecFH;
		}

		Vec2f getStop(Vec2f *speed) {
			speed->x = 0;
			speed->y = 0;

			return vecAF;
		}

		static bool isCloserObstacle(Collision first, Collision second){
			return (first.vecAF.length2() < second.vecAF.length2());
		}

		PhysicalObject* getTarget(){
			return target;
		}
	};

	class CollisionDetector {
		friend class CircleStatic;
		friend class CircleDynamic;
		friend class LineStatic;

	private:
		float timeFlow;
		unsigned int frameCount = 0;
		float frameCountTimer = 0;
		float fps{};

		float getElapsedTime();

		static bool collision(CircleStatic circle1, CircleStatic circle2);

		bool checkCollision(CircleDynamic *object);

	public:
		CollisionDetector() : timeFlow(getElapsedTime()){
			PhysicalObject::collisionDetector = this;

			CircleStatic::elements = {};
			CircleDynamic::elements = {};
			LineStatic::elements = {};
		}

		bool update() {
			timeFlow = getElapsedTime();

			if(timeFlow > 0.2f)
				timeFlow = 0.2f;

			frameCountTimer += timeFlow;
			frameCount++;
			if(frameCountTimer > 1.0f){
				fps =  frameCount / frameCountTimer;
				frameCountTimer = 0;
				frameCount = 0;

				return true;
			}

			for (CircleDynamic *object : CircleDynamic::elements){
				if(object->speed.x != 0 || object->speed.y != 0)
					checkCollision(object);
			}

			return false;
		}

		float getFPS(){
			return fps;
		}
	};
}