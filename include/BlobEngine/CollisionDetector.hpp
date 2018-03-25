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

	public:

		virtual Reaction hit(const PhysicalObject& from) {
			return IGNORE;
		}
	};

	class CircleStatic : PhysicalObject {
		friend CollisionDetector;
	private:
		std::deque<CircleStatic*>::iterator elementIt{};
	protected:
		Circle mainCircle{};
		//std::list<Circle> circles{};

		void enableCollision();

		void disableCollision();

	public:
		explicit CircleStatic(unsigned int objectType) : PhysicalObject(objectType) {
			enableCollision();
		}

		~CircleStatic() {
			disableCollision();
		}
	};

	class CircleDynamic : PhysicalObject {
		friend CollisionDetector;
	private:
		std::deque<CircleDynamic*>::iterator elementIt{};
	protected:
		Vec2f speed{};
		Circle mainCircle{};

		void enableCollision();

		void disableCollision();

	public:
		explicit CircleDynamic(unsigned int objectType) : PhysicalObject(objectType) {
			enableCollision();
		}

		~CircleDynamic() {
			disableCollision();
		}
	};

	class LineStatic  : PhysicalObject {
		friend CollisionDetector;
	private:
		std::deque<LineStatic*>::iterator elementIt{};
	protected:
		std::deque<Line> lines{};

		void enableCollision();

		void disableCollision();

	public:
		explicit LineStatic(unsigned int objectType) : PhysicalObject(objectType) {
			enableCollision();
		}

		~LineStatic() {
			disableCollision();
		}
	};

	class CollisionDetector {
		friend CircleStatic;
		friend CircleDynamic;
		friend LineStatic;
	private:
		float timeFlow;
		unsigned int frameCount = 0;
		float frameCountTimer = 0;

		thread_local static std::deque<CircleStatic*> circleStaticList;
		thread_local static std::deque<CircleDynamic*> circleDynamicList;
		thread_local static std::deque<LineStatic*> lineStaticList;

		float getElapsedTime();

		void checkCollision(CircleDynamic *object);

	public:
		CollisionDetector() : timeFlow(getElapsedTime()) {}

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