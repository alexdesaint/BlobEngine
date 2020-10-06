#pragma once

#include <Blob/Geometrie.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Collision/Reaction.hpp>

#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>

namespace Blob::Collision {

    class CollisionDetector;

    /**
     * Object is a virtual class
     * An object have a type to define him and can be hit
     */
    class Object : virtual public Maths::Form {
        friend CollisionDetector;

    private:
        int objectType;

    protected:
        bool enable = false;

        /**
         * To set the type of the object
         * The type is used to define the child class of this Object.
         * Typic
         * @param objectType
         */
        void setObjectType(int objectType) {
            Object::objectType = objectType;
        }

        explicit Object(int objectType) : objectType(objectType) {}

        virtual void hit(int objectType, Object &object) {}

        std::list<Object *> getImtemsHere(Maths::Vec2f pos);

    public:
        int getObjectType() const;
    };

    class DynamicObject : public Object {
        friend CollisionDetector;
    private:
        Reaction reaction = STOP;

    protected:
        Maths::Vec2f speed{};

        explicit DynamicObject(int objectType) : Object(objectType) {}

        /**
         * Set the reaction when you hit an object.
         * Can bet set in 'hit' to set the reaction of the current collision or in the constructor if you know you will
         * only use one reaction type.
         *
         * The default value is 'STOP'
         *
         * @param reaction
         */
        void setReaction(Reaction reaction) {
            this->reaction = reaction;
        }

        /**
         * This method is used to stop the dynamic object from moving.
         * it will be called each time the collision detector move the target.
         * For example, you can implement this method to return false when the object have reach the destination.
         *
         * @return return true to keep moving or false to stop
         */
        virtual bool keepMoving() {
            return true;
        };

        /**
         * This method is called right before the collision is computed.
         * It's the perfect moment to set the final speed
         */
        virtual void preCollisionUpdate() {}

        /**
         * This method is called right after the collision is computed
         * It can be used to check is you had a collision during this move.
         * For example if 'hit' has not been called between 'preCollisionUpdate' and 'postCollisionUpdate'.
         */
        virtual void postCollisionUpdate() {}
    };

    class CircleStatic : public Object {
        friend CollisionDetector;
    private:
        std::list<CircleStatic *>::iterator elementIt{};
    protected:
        Maths::Circle mainCircle{};

        void enableCollision();

        void disableCollision();

        explicit CircleStatic(const int objectType) : Object(objectType) {
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
        Maths::Circle mainCircle{};

        void enableCollision();

        void disableCollision();

        explicit CircleDynamic(const int objectType) : DynamicObject(objectType) {
            enableCollision();
        }

        ~CircleDynamic() {
            disableCollision();
        }
    };

    class RectStatic : public Object, public Maths::Rectangle {
        friend CollisionDetector;

    private:
        std::list<RectStatic *>::iterator elementIt{};

    protected:
        void enableCollision();

        void disableCollision();

    public:
        explicit RectStatic(Maths::Vec2f position, Maths::Vec2f size, const int objectType) : Rectangle(position, size), Object(objectType) {
            enableCollision();
        }

        ~RectStatic() {
            disableCollision();
        }
    };

    class RectDynamic : public DynamicObject, public Maths::Rectangle {
        friend CollisionDetector;

    private:
        std::list<RectDynamic *>::iterator elementIt{};

    protected:
        void enableCollision();

        void disableCollision();

    public:
        explicit RectDynamic(Maths::Vec2f position, Maths::Vec2f size, const int objectType) : Rectangle(position, size), DynamicObject(objectType) {
            enableCollision();
        }

        ~RectDynamic() {
            disableCollision();
        }
    };

    class LineStatic : public Object {
        friend CollisionDetector;
    private:
        std::list<LineStatic *>::iterator elementIt{};
    protected:
        std::deque<Maths::Point2f> lines{};

        void enableCollision();

        void disableCollision();

        explicit LineStatic(const int objectType) : Object(objectType) {
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
        friend Object;
#ifdef TEST
        friend test_class;
#endif
    private:

        static std::unordered_map<int64_t, std::unordered_set<Object *>> spacialHash;

        static std::list<CircleDynamic *> circleDynamicList;
        static std::list<RectDynamic *> rectDynamicList;

        bool timeStoped = false;

        static uint64_t hashCoor(Maths::Vec2f pos);

        static Maths::Vec2i unhashCoor(uint64_t pos);

        static uint64_t hashCoor(Maths::Vec2i pos);

        static void addToSpacialHash(std::list<Maths::Vec2i> pos, Object *o);

        static void removeFromSpacialHash(std::list<Maths::Vec2i> pos, Object *o);

        static bool targetOverlap(RectDynamic &object, Maths::Rectangle &r, const std::unordered_set<Object *> &targets,
                                  std::unordered_map<Object *, Reaction> &hittedObjects);

        static void computeLocalCollision(RectDynamic &object, const std::unordered_set<Object *> &targets, Maths::Vec2f frameMove);

        static std::list<int64_t> getPath(Maths::Vec2i pos, Maths::Vec2i dest);

    public:

        //StaticObject *getClosetObject(Circle &object, Vec2f frameMove, Hit &hit);

        //void checkCollision(CircleDynamic &object);

        void checkCollision(RectDynamic &object);

        void update();

        void pause();

        void unpause();
    };
}