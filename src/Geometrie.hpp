#pragma once

#include <cmath>

#define PI 3.14159265f

namespace  Geometrie {

	template <typename T>
	class Mat2{
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

		float Length() {
			return std::sqrt(x * x + y * y);
		}

		float Length2() {
			return x * x + y * y;
		}

		Mat2 Normalize() {
			float length = Length();
			x = x / length;
			y = y / length;

			return *this;
		}

		Mat2 setLength(float newLength)  {
			float oldLength = Length();
			float Rapport;
			if (oldLength != 0) {
				Rapport = newLength / oldLength;
				x *= Rapport;
				y *= Rapport;
			}
			return *this;
		}

		float getOrientation() {
			return std::atan2(y, x);
		}
	};

	typedef Mat2<int> Point2i;
	typedef Mat2<float> Point2f;
	typedef Mat2<int> Vec21;
	typedef Mat2<float> Vec2f;

	class Circle {
	public:
		Circle() : rayon(0) {}
		Circle(Point2f position, float rayon) : rayon(rayon), position(position) {}
		float rayon = 0;
		Point2f position;
	};

	struct Line	{
		Line(Point2f a, Point2f b) : pointA(a), pointB(b) {}
		Vec2f getVector()  {
			return {pointB.x - pointA.x, pointB.y - pointA.y};
		}

		Point2f pointA;
		Point2f pointB;

		float Length();
		float Length2();
		float getOrientation() {
			return std::atan2(pointB.x - pointA.x, pointB.y - pointA.y);
		}
	};

	float ProduitScalaire(Vec2f A, Vec2f B);
	float Distance(Point2f PointA, Point2f PointB);
	float Distance2(Point2f PointA, Point2f PointB);
	bool Intersection(Line A, Line B, Point2f *inter);
	Point2f ClosestPointOnLine(Line line, Point2f point);
};