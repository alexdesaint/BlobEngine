#pragma once

#include <deque>
#include <BlobEngine/Geometrie.hpp>
#include <BlobEngine/Hit.hpp>
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/Reaction.hpp>

namespace BlobEngine {

	class CollisionDetector;
	class CollisionDetectorException;

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
		friend CollisionDetectorException;
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

	class CircleDynamic : public PhysicalObject {
		friend CollisionDetector;
		friend CollisionDetectorException;
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
		friend CollisionDetectorException;
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

	public:

		PhysicalObject *getClosetObject(Circle object, Vec2f frameMove, Hit &hit);

		void checkCollision(CircleDynamic &object);

		CollisionDetector() : timeFlow(getElapsedTime()) {}

		void update() {
			timeFlow = getElapsedTime();

			if(timeFlow > 0.2f)
				timeFlow = 0.2f;

			for (auto &object : circleDynamicList) {
				if(!object->speed.isNull())
					checkCollision(*object);
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