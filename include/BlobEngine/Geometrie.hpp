#pragma once

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

		T length2() {
			return x * x + y * y;
		}

		double length();

		T scalaire(Mat2 B) {
			return x * B.x + y * B.y;
		}
		
		Mat2<float> getNormal() {
			double l = length();
			
			return {(float) ((x) / l), (float) ((y) / l)};
		}

		Mat2 setLength(double newLength);

		Mat2 rotate() {
			return {-y, x};
		}

		double getOrientationRad();

		double getOrientationDeg();

		void reset(){
			x = 0;
			y = 0;
		}

		bool isNull() {
			return ((x == 0) && (y == 0));
		}

		//void round(int v);
	};

	template
	class Mat2<int>;
	
	template
	class Mat2<float>;
	
	template
	class Mat2<double>;
	
	typedef Mat2<int> Point2i;
	typedef Mat2<float> Point2f;
	typedef Mat2<double> Point2d;
	typedef Mat2<int> Vec2i;
	typedef Mat2<float> Vec2f;
	typedef Mat2<double> Vec2d;

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

		double Length2() {
			return (pointB.x - pointA.x) * (pointB.x - pointA.x) + (pointB.y - pointA.y) * (pointB.y - pointA.y);
		}

		double Length();

		double getOrientation();

		Point2f closestPointTo(Point2f point);

		Point2f getIntersectionPoint(Line B);
	};
};