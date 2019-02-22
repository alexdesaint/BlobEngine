#pragma once

#include <cfloat>

#define PI 3.14159265f

namespace Blob {

	template<typename T>
	class Mat2 {
	public:
		T x = 0, y = 0;

		Mat2() = default;

		Mat2(T x, T y) : x(x), y(y) {}

		Mat2(Mat2 point1, Mat2 point2) {
			x = point2.x - point1.x;
			y = point2.y - point1.y;
		}

		//operator with Mat2
		Mat2 operator-(Mat2 mat2) {
			return {x - mat2.x, y - mat2.y};
		}

		Mat2 operator+(Mat2 mat2) {
			return {x + mat2.x, y + mat2.y};
		}

		Mat2 operator*(Mat2 mat2) {
			return {x * mat2.x, y * mat2.y};
		}

		Mat2 operator/(Mat2 mat2) {
			return {x / mat2.x, y / mat2.y};
		}

		/*
		Mat2& operator=(Mat2 mat2) {
			return {x * mat2.x, y * mat2.y};
		}
		*/

		//operator with T
		Mat2 operator+(T a) {
			return {a + x, a + y};
		}

		Mat2 operator-(T a) {
			return {x - a, y - a};
		}

		Mat2 operator*(T a) {
			return {a * x, a * y};
		}

		Mat2 operator/(T a) {
			return {x / a, y / a};
		}

		//test
		/// Add a vector to this vector.
		void operator+=(const Mat2<T> &v) {
			x += v.x;
			y += v.y;
		}

		/// Subtract a vector from this vector.
		void operator-=(const Mat2<T> &v) {
			x -= v.x;
			y -= v.y;
		}

		/// Multiply this vector by a scalar.
		void operator*=(float a) {
			x *= a;
			y *= a;
		}

		T length2() {
			return x * x + y * y;
		}

		double length();

		T scalaire(Mat2 B) {
			return x * B.x + y * B.y;
		}

		Mat2<float> getNormal() {
			double l = length();

			double invLength = 1.0f / l;

			return {(float) (x * invLength), (float) (y * invLength)};
		}

		Mat2 setLength(double newLength);

		Mat2 rotate() {
			return {-y, x};
		}

		double getOrientation();

		double getOrientationDeg();

		void reset() {
			x = 0;
			y = 0;
		}

		bool isNull() {
			return ((x == 0) && (y == 0));
		}

		//void round(int v);
	};

	template
	class Mat2<float>;

	//typedef Mat2<int> Point2i;
	typedef Mat2<float> Point2f;
	//typedef Mat2<double> Point2d;
	typedef Mat2<int> Vec2i;
	typedef Mat2<unsigned int> Vec2ui;
	typedef Mat2<float> Vec2f;
	//typedef Mat2<double> Vec2d;

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

	class Rectangle {
	public:
		Point2f position;
		Vec2f size;


		Rectangle() : position(), size() {}

		Rectangle(Point2f position, Vec2f size) : position(position), size(size) {}

		bool overlap(const Rectangle &r);
	};
};