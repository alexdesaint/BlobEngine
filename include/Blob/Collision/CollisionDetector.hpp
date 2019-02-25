#pragma once

#include <BlobEngine/Geometrie.hpp>
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/Collision/Reaction.hpp>

#include <deque>
#include <list>

namespace Blob::Collision {

	class CollisionDetector;

	class StaticObject {
		friend CollisionDetector;
	private:
		const void *objectData;
		int objectType;

	protected:
		explicit StaticObject(int objectType, const void *objectData) :
				objectData(objectData),
				objectType(objectType) {}

		void setObjectType(int objectType) {
			StaticObject::objectType = objectType;
		}

		virtual void hit(int objectType, const void *objectData) {}
	};

	class DynamicObject {
		friend CollisionDetector;
	private:
		const void *objectData;
		int objectType;

	protected:
		Vec2f speed{};

		explicit DynamicObject(int objectType, const void *objectData) :
				objectData(objectData),
				objectType(objectType) {}

		virtual Reaction hit(int objectType, const void *objectData) {
			return STOP;
		}

		virtual void preCollisionUpdate() {}

		virtual void postCollisionUpdate() {}

		void setObjectType(int objectType) {
			DynamicObject::objectType = objectType;
		}

		virtual bool moove() {
			return true;
		};
	};

	class CircleStatic : public StaticObject {
		friend CollisionDetector;
	private:
		std::list<CircleStatic *>::iterator elementIt{};
	protected:
		Circle mainCircle{};

		void enableCollision();

		void disableCollision();

	public:
		explicit CircleStatic(const int objectType, const void *objectData) : StaticObject(objectType, objectData) {
			enableCollision();
		}

		~CircleStatic() {
			disableCollision();
		}
	};

	class CircleDynamic : public DynamicObject {
		friend CollisionDetector;
	private:
		std::list<CircleDynamic *>::iterator elementIt{};
	protected:
		Circle mainCircle{};

		void enableCollision();

		void disableCollision();

	public:
		explicit CircleDynamic(const int objectType, const void *objectData) : DynamicObject(objectType, objectData) {
			enableCollision();
		}

		~CircleDynamic() {
			disableCollision();
		}
	};

	class RectStatic : public StaticObject, public Rectangle {
		friend CollisionDetector;
	private:
		std::list<RectStatic *>::iterator elementIt{};
	protected:

		void enableCollision();

		void disableCollision();

	public:
		explicit RectStatic(const int objectType, const void *objectData) : StaticObject(objectType, objectData) {
			enableCollision();
		}

		~RectStatic() {
			disableCollision();
		}
	};

	class RectDynamic : public DynamicObject, public Rectangle {
		friend CollisionDetector;
	private:
		std::list<RectDynamic *>::iterator elementIt{};
	protected:

		void enableCollision();

		void disableCollision();

	public:
		explicit RectDynamic(const int objectType, const void *objectData) : DynamicObject(objectType, objectData) {
			enableCollision();
		}

		~RectDynamic() {
			disableCollision();
		}
	};

	class LineStatic : public StaticObject {
		friend CollisionDetector;
	private:
		std::list<LineStatic *>::iterator elementIt{};
	protected:
		std::deque<Point2f> lines{};

		void enableCollision();

		void disableCollision();

	public:
		explicit LineStatic(const int objectType, const void *objectData) : StaticObject(objectType, objectData) {
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

		static std::list<CircleStatic *> circleStaticList;
		static std::list<CircleDynamic *> circleDynamicList;
		static std::list<RectStatic *> rectStaticList;
		static std::list<RectDynamic *> rectDynamicList;
		static std::list<LineStatic *> lineStaticList;

		float timeFlow;

		bool timeStoped = false;
	public:

		//StaticObject *getClosetObject(Circle &object, Vec2f frameMove, Hit &hit);

		//void checkCollision(CircleDynamic &object);

		void checkCollision(RectDynamic &object);

		void update();

		void pause();

		void unpause();
	};
}