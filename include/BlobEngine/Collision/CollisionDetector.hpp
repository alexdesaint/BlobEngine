#pragma once

#include <deque>
#include <BlobEngine/Geometrie.hpp>
#include <BlobEngine/Collision/Hit.hpp>
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/Collision/Reaction.hpp>

namespace BlobEngine {

	class CollisionDetector;

	class PhysicalObject{
		friend CollisionDetector;
	private:
		unsigned int objectType;
		
	protected:
		explicit PhysicalObject(unsigned int objectType) : objectType(objectType) { }

		virtual Reaction hit(const PhysicalObject& from) {
			return IGNORE;
		}

		virtual void preCollisionUpdate() {}

		virtual void postCollisionUpdate() {}
	};

	class CircleStatic : public PhysicalObject {
		friend CollisionDetector;
	private:
		std::deque<CircleStatic*>::iterator elementIt{};
	protected:
		Circle mainCircle{};

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

	class RectStatic : public PhysicalObject, public Rectangle {
		friend CollisionDetector;
	private:
		std::deque<RectStatic*>::iterator elementIt{};
	protected:

		void enableCollision();

		void disableCollision();

	public:
		explicit RectStatic(unsigned int objectType) : PhysicalObject(objectType) {
			enableCollision();
		}

		~RectStatic() {
			disableCollision();
		}
	};

	class RectDynamic : public PhysicalObject, public Rectangle {
		friend CollisionDetector;
	private:
		std::deque<RectDynamic*>::iterator elementIt{};
	protected:
		Vec2f speed{};

		void enableCollision();

		void disableCollision();

	public:
		explicit RectDynamic(unsigned int objectType) : PhysicalObject(objectType) {
			enableCollision();
		}

		~RectDynamic() {
			disableCollision();
		}
	};

	class LineStatic : public PhysicalObject {
		friend CollisionDetector;
	private:
		std::deque<LineStatic*>::iterator elementIt{};
	protected:
		std::deque<Point2f> lines{};

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
		friend RectStatic;
		friend RectDynamic;
		friend LineStatic;
	private:

		static std::deque<CircleStatic *> circleStaticList;
		static std::deque<CircleDynamic *> circleDynamicList;
		static std::deque<RectStatic *> rectStaticList;
		static std::deque<RectDynamic *> rectDynamicList;
		static std::deque<LineStatic *> lineStaticList;

		float timeFlow;

	public:
		
		//PhysicalObject *getClosetObject(Circle &object, Vec2f frameMove, Hit &hit);

		//void checkCollision(CircleDynamic &object);

		void checkCollision(RectDynamic &object);

		void update();
	};
}