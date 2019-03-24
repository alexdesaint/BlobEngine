#pragma once

#include <cfloat>
#include <ostream>
#include <array>

#define PI 3.14159265f

namespace Blob {

	template<typename T>
	class Vec2 {
	public:
		T x = 0, y = 0;

		Vec2() = default;

		Vec2(T x, T y) : x(x), y(y) {}

		Vec2(const Vec2 &point1, const Vec2 &point2) {
			x = point2.x - point1.x;
			y = point2.y - point1.y;
		}

		//operator with Vec2
		Vec2 operator-(const Vec2 &v) {
			return {x - v.x, y - v.y};
		}

		Vec2 operator+(const Vec2 &v) {
			return {x + v.x, y + v.y};
		}

		Vec2 operator*(const Vec2 &v) {
			return {x * v.x, y * v.y};
		}

		Vec2 operator/(const Vec2 &v) {
			return {x / v.x, y / v.y};
		}

		/*
		Vec2& operator=(Vec2 mat2) {
			return {x * mat2.x, y * mat2.y};
		}
		*/

		/// Add a vector to this vector.
		void operator+=(const Vec2 &v) {
			x += v.x;
			y += v.y;
		}

		/// Subtract a vector from this vector.
		void operator-=(const Vec2 &v) {
			x -= v.x;
			y -= v.y;
		}

		//operator with T
		Vec2 operator+(T a) {
			return {a + x, a + y};
		}

		Vec2 operator-(T a) {
			return {x - a, y - a};
		}

		Vec2 operator*(T a) {
			return {a * x, a * y};
		}

		Vec2 operator/(T a) {
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

		void operator*=(T a) {/// Multiply this vector by a scalar.
			x *= a;
			y *= a;
		}

		void operator/=(T a) {
			x /= a;
			y /= a;
		}

		T length2() {
			return x * x + y * y;
		}

		float length();

		T scalaire(Vec2 B) {
			return x * B.x + y * B.y;
		}

		Vec2<float> getNormal() {
			float l = length();

			float invLength = 1.f / l;

			return {x * invLength, y * invLength};
		}

		Vec2 setLength(float newLength);

		Vec2 rotate() {
			return {-y, x};
		}

		float getOrientation();

		float getOrientationDeg();

		void reset() {
			x = 0;
			y = 0;
		}

		bool isNull() {
			return ((x == 0) && (y == 0));
		}

		template<typename U>
		Vec2<U> cast() {
			return {(U) x, (U) y};
		}

		friend std::ostream &operator<<(std::ostream &os, const Vec2 &dt) {
			os << dt.x << ", " << dt.y;
			return os;
		}

		std::string str() {
			return std::to_string(x) + ", " + std::to_string(y);
		}
	};

	template
	class Vec2<float>;

	//typedef Vec2<int> Point2i;
	typedef Vec2<float> Point2f;
	//typedef Vec2<double> Point2d;
	typedef Vec2<int> Vec2i;
	typedef Vec2<unsigned int> Vec2ui;
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

		bool overlap(const Rectangle &r) final;
	};
};