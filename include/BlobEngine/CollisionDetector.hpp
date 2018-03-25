#pragma once

#include <chrono>
#include <iostream>
#include <deque>
#include "Geometrie.hpp"
#include "BlobException.hpp"

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
	public:
		unsigned int objectType;
		
	protected:
		explicit PhysicalObject(unsigned int objectType) : objectType(objectType) { }

		std::deque<PhysicalObject*>::iterator elementIt;
		std::deque<PhysicalObject*> *elements = nullptr;

		void enableCollision() {
			if(elements == nullptr)
				throw BlobException("add collision detector before enable collision");
			elements->push_front(this);
			elementIt = elements->begin();
		}

		void disableCollision() {
			if(elements == nullptr)
				throw BlobException("add collision detector before disable collision");
			elements->erase(elementIt);
		}

	private:
		void setCollisionDetector(std::deque<PhysicalObject*> *elements) {
			this->elements = elements;
			enableCollision();
		}

		void removeCollisionDetector() {
			disableCollision();
			elements = nullptr;
		}
	public:

		virtual Reaction hit(const PhysicalObject& from) {
			return IGNORE;
		}

		~PhysicalObject() {
			if(elements != nullptr)
				disableCollision();
		}
	};

	class CircleStatic : PhysicalObject {
		friend CollisionDetector;
	protected:
		Circle mainCircle{};
		//std::list<Circle> circles{};

	public:
		explicit CircleStatic(unsigned int objectType) : PhysicalObject(objectType) {}

		const Circle &getMainCircle() const {
			return mainCircle;
		}
	};

	class CircleDynamic : PhysicalObject {
		friend CollisionDetector;
	protected:
		Vec2f speed{};
		Circle mainCircle{};

	public:
		explicit CircleDynamic(unsigned int objectType) : PhysicalObject(objectType){}

		const Vec2f &getSpeed() const {
			return speed;
		}

		const Circle &getMainCircle() const {
			return mainCircle;
		}
	};

	class LineStatic  : PhysicalObject {
		friend CollisionDetector;
	protected:
		std::deque<Line> lines{};

	public:
		explicit LineStatic(unsigned int objectType) : PhysicalObject(objectType) {}

		const std::deque<Line> &getLines() const {
			return lines;
		}
	};

	class CollisionDetector {
	private:
		float timeFlow;
		unsigned int frameCount = 0;
		float frameCountTimer = 0;

		std::deque<CircleStatic*> circleStaticList{};
		std::deque<CircleDynamic*> circleDynamicList{};
		std::deque<LineStatic*> lineStaticList{};

		float getElapsedTime();

		void checkCollision(CircleDynamic *object);

	public:
		CollisionDetector() : timeFlow(getElapsedTime()) {}

		void addObject(CircleStatic* obj) {
			obj->setCollisionDetector((std::deque<PhysicalObject*>*)(&circleStaticList));
		}

		void addObject(CircleDynamic* obj) {
			obj->setCollisionDetector((std::deque<PhysicalObject*>*)(&circleDynamicList));
		}

		void addObject(LineStatic* obj) {
			obj->setCollisionDetector((std::deque<PhysicalObject*>*)(&lineStaticList));
		}

		void removeObject(PhysicalObject* obj){
			obj->disableCollision();
		}

		void update() {
			timeFlow = getElapsedTime();

			if(timeFlow > 0.2f)
				timeFlow = 0.2f;

			for (CircleDynamic *object : circleDynamicList){
				if(!object->speed.isNull())
					checkCollision(object);
			}

			frameCountTimer += timeFlow;
			frameCount++;
		}

		float getFPS() {
			float fps =  frameCount / frameCountTimer;
			frameCountTimer = 0;
			frameCount = 0;
			return fps;
		}
	};
}