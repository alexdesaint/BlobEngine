#pragma once

#include <cfloat>
#include <ostream>
#include <array>
#include <list>

#define PI 3.14159265f

namespace Blob {

	template<typename T>
	class Vec2 {
	public:
		T x = 0, y = 0;

		//Constructors
		Vec2() = default;

		Vec2(T x, T y) : x(x), y(y) {}

		Vec2(const Vec2 &point1, const Vec2 &point2) {
			x = point2.x - point1.x;
			y = point2.y - point1.y;
		}

		//operator with Vec2
        bool operator==(const Vec2 &v) const {
            return x == v.x && y == v.y;
        }

        bool operator!=(const Vec2 &v) const {
            return x != v.x || y != v.y;
        }

		Vec2 operator-(const Vec2 &v) const {
			return {x - v.x, y - v.y};
		}

		Vec2 operator+(const Vec2 &v) const {
			return {x + v.x, y + v.y};
		}

		Vec2 operator*(const Vec2 &v) const {
			return {x * v.x, y * v.y};
		}

		Vec2 operator/(const Vec2 &v) const {
			return {x / v.x, y / v.y};
		}

        void operator+=(const Vec2 &v) {
            x += v.x;
            y += v.y;
        }

        void operator-=(const Vec2 &v) {
            x -= v.x;
            y -= v.y;
        }

        void operator*=(const Vec2 &v) {
            x *= v.x;
            y *= v.y;
        }

        void operator/=(const Vec2 &v) {
            x /= v.x;
            y /= v.y;
        }

        Vec2 &operator=(const Vec2 &v) {
            x = v.x;
            y = v.y;
			return *this;
		}

		//operator with T
		Vec2 operator+(T a) const {
			return {a + x, a + y};
		}

		Vec2 operator-(T a) const {
			return {x - a, y - a};
		}

		Vec2 operator*(T a) const {
			return {a * x, a * y};
		}

		Vec2 operator/(T a) const {
			return {x / a, y / a};
		}

		void operator+=(T a) {
			x += a;
			y += a;
		}

		void operator-=(T a) {
			x -= a;
			y -= a;
		}

		void operator*=(T a) {
			x *= a;
			y *= a;
		}

		void operator/=(T a) {
			x /= a;
			y /= a;
		}

        Vec2 &operator=(const T a) {
            x = a;
            y = a;
            return *this;
        }

        //Functions
		[[nodiscard]] T length2() const {
			return x * x + y * y;
		}

		[[nodiscard]] float length() const;

		[[nodiscard]] T scalaire(Vec2 B) const {
			return x * B.x + y * B.y;
		}

		[[nodiscard]] Vec2<float> getNormal() const {
			float l = length();

			float invLength = 1.f / l;

			return {x * invLength, y * invLength};
		}

        Vec2<T> setLength(float newLength);

		[[nodiscard]] Vec2 rotate() const {
			return {-y, x};
		}

		[[nodiscard]] float getOrientation() const;

		[[nodiscard]] float getOrientationDeg() const;

		void reset() {
			x = 0;
			y = 0;
		}

		[[nodiscard]] bool isNull() const {
			return ((x == 0) && (y == 0));
		}

		template<typename U>
		Vec2<U> cast() const {
			return {(U) x, (U) y};
		}

		//Print operator
		friend std::ostream &operator<<(std::ostream &os, const Vec2 &dt) {
			os << dt.x << ", " << dt.y;
			return os;
		}
	};

    typedef Vec2<int> Point2i;
	typedef Vec2<float> Point2f;
	//typedef Vec2<double> Point2d;
	typedef Vec2<int> Vec2i;
    //typedef Vec2<unsigned int> Vec2ui;
	typedef Vec2<float> Vec2f;
	//typedef Vec2<double> Vec2d;

	class Rectangle;
	//class Circle;
	//class Line;

	class Form {
	protected:
		virtual bool overlap(const Rectangle &rect) = 0;
		//virtual bool overlap(const Circle &rect) = 0;
		//virtual bool overlap(const Line &rect) = 0;
	};

	class Circle {
	public:
		float rayon = 0;
		Point2f position;

		Circle() : rayon(0) {}

		Circle(Point2f position, float rayon) : rayon(rayon), position(position) {}
	};

	class Line {
	public:
		Point2f pointA;
		Point2f pointB;

		Line() : pointA(), pointB() {}

		Line(Point2f a, Point2f b) : pointA(a), pointB(b) {}

		Vec2f getVector() {
			return {pointB.x - pointA.x, pointB.y - pointA.y};
		}

		double Length2() {
			return (pointB.x - pointA.x) * (pointB.x - pointA.x) + (pointB.y - pointA.y) * (pointB.y - pointA.y);
		}

		double Length();

		double getOrientation();

		Point2f closestPointTo(Point2f point);

		Point2f getIntersectionPoint(Line B);

		float getGradient() {
			//(yb - ya)/(xb - xa)
			return (pointB.y - pointA.y) / (pointB.x - pointA.x);
		}

		float getConstant() {
			return pointA.y - getGradient() * pointA.x;
		}
	};

	class Rectangle : virtual public Form {
    public:

        ///The center of the rectangle
        Point2f position;

        ///full size of the sides
        Vec2f size;

		Rectangle() : position(), size() {}

		Rectangle(Point2f position, Vec2f size) : position(position), size(size) {}

		std::array<Vec2f, 4> getPoints();

		[[nodiscard]] bool overlapBigger(const Rectangle &r) const;

		bool overlap(const Rectangle &r) final;

		std::list<Vec2i> rasterize();

        /*const Point2f &getPosition() const;

        const Vec2f &getSize() const;

        void setPosition(const Point2f &position);

        void setSize(const Vec2f &size);*/
    };
};