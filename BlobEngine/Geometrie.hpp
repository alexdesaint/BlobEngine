#pragma once

#include <cmath>

#define PI 3.14159265f

namespace  BlobEngine {

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

		float length2() {
			return x * x + y * y;
		}

		float length() {
			return std::sqrt(length2());
		}

		float scalaire(Mat2 B) {
			return x * B.x + y * B.y;
		}

		Mat2 normalize() {
			float l = length();
			x = x / l;
			y = y / l;

			return *this;
		}

		Mat2 setLength(float newLength)  {
			float oldLength = length();
			float Rapport;

			if (oldLength != 0) {
				Rapport = newLength / oldLength;
				x *= Rapport;
				y *= Rapport;
			}
			return *this;
		}

		Mat2 rotate() {
			return {-y, x};
		}

		float getOrientationRad() {
			return std::atan2(y, x);
		}

		float getOrientationDeg() {
			return std::atan2(y, x) * 180 / PI;
		}

		void reset(){
			x = 0;
			y = 0;
		}
	};

	typedef Mat2<int> Point2i;
	typedef Mat2<float> Point2f;
	typedef Mat2<int> Vec21;
	typedef Mat2<float> Vec2f;

	class Circle {
	public:
		float rayon = 0;
		Point2f position;

		Circle() : rayon(0) {}
		Circle(Point2f position, float rayon) : rayon(rayon), position(position) {}
	};

	class Line	{
	public:
		Point2f pointA;
		Point2f pointB;

		Line() : pointA(), pointB() {}
		Line(Point2f a, Point2f b) : pointA(a), pointB(b) {}

		Vec2f getVector()  {
			return {pointB.x - pointA.x, pointB.y - pointA.y};
		}

		float Length2() {
			return (pointB.x - pointA.x) * (pointB.x - pointA.x) + (pointB.y - pointA.y) * (pointB.y - pointA.y);
		}

		float Length() {
			return std::sqrt(Length2());
		}

		float getOrientation() {
			return std::atan2(pointB.y - pointA.y, pointB.x - pointA.x);
		}

		Point2f closestPointTo(Point2f point) {

			float A1 = pointB.y - pointA.y;
			float B1 = pointA.x - pointB.x;;
			float C1 = A1*pointA.x + B1*pointA.y;
			float C2 = -B1*point.x + A1*point.y;

			float det = A1*A1 - -B1*B1;

			if (det != 0) {
				return {((A1*C1 - B1*C2) / det), ((A1*C2 - -B1*C1) / det)};
			}
			else {
				return point;
			}
		}

		Point2f getIntersectionPoint(Line B) {

			float A1 = pointA.x - pointB.x;

			float B1 = B.pointA.x - B.pointB.x;

			float A2 = pointA.y - pointB.y;

			float B2 = B.pointA.y - B.pointB.y;

			float det = A1*B2 - A2*B1;

			if (det == 0)
				return {};

			float C1 = pointB.y * pointA.x - pointB.x * pointA.y;

			float C2 = B.pointB.y * B.pointA.x - B.pointB.x * B.pointA.y;

			return {(C1*B1 - A1*C2) / det, (C1*B2 - A2*C2) / det};
		}
	};
};