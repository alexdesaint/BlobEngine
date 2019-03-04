#pragma once

#include <Blob/Geometrie.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Collision/Reaction.hpp>

#include <deque>
#include <list>
#include <unordered_map>

namespace Blob::Collision {

	class CollisionDetector;

	class Object {
		friend CollisionDetector;
	private:
		int objectType;

	protected:
		void setObjectType(int objectType) {
			Object::objectType = objectType;
		}

		Object(int objectType) : objectType(objectType) {}
	};

	class StaticObject : public Object {
		friend CollisionDetector;
	protected:
		explicit StaticObject(int objectType) : Object(objectType) {}

		virtual void hit(int objectType, Object &object) {}
	};

	class DynamicObject : public Object {
		friend CollisionDetector;
	protected:
		Vec2f speed{};

		explicit DynamicObject(int objectType) : Object(objectType) {}

		virtual Reaction hit(int objectType, Object &object) {
			return STOP;
		}

		virtual void preCollisionUpdate() {}

		virtual void postCollisionUpdate() {}

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

		explicit CircleStatic(const int objectType) : StaticObject(objectType) {
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

		explicit CircleDynamic(const int objectType) : DynamicObject(objectType) {
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

		explicit RectStatic(const int objectType) : StaticObject(objectType) {
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

		explicit RectDynamic(const int objectType) : DynamicObject(objectType) {
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

		explicit LineStatic(const int objectType) : StaticObject(objectType) {
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

		static std::unordered_map<int64_t, std::list<Object *>> spacialHash;

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