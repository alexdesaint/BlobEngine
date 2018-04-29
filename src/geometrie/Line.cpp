#include <BlobEngine/Geometrie.hpp>

#include <cmath>

namespace BlobEngine {
	
	template <typename T>
	Mat2<T> Line<T>::closestPointTo(Mat2<T> point) {
		
		double A1 = pointB.y - pointA.y;
		double B1 = pointA.x - pointB.x;;
		double C1 = A1 * pointA.x + B1 * pointA.y;
		double C2 = -B1 * point.x + A1 * point.y;
		
		double det = A1 * A1 - -B1 * B1;

		if (det != 0) {
			return {(T) ((A1 * C1 - B1 * C2) / det), (T) ((A1 * C2 - -B1 * C1) / det)};
		} else {
			return point;
		}
	}
	
	template <typename T>
	Mat2<T> Line<T>::getIntersectionPoint(Line B) {
		
		double A1 = pointA.x - pointB.x;
		
		double B1 = B.pointA.x - B.pointB.x;
		
		double A2 = pointA.y - pointB.y;
		
		double B2 = B.pointA.y - B.pointB.y;
		
		double det = A1 * B2 - A2 * B1;

		if (det == 0)
			return {};
		
		double C1 = pointB.y * pointA.x - pointB.x * pointA.y;
		
		double C2 = B.pointB.y * B.pointA.x - B.pointB.x * B.pointA.y;
		
		return {(T) ((C1 * B1 - A1 * C2) / det), (T) ((C1 * B2 - A2 * C2) / det)};
	}
	
	template <typename T>
	double Line<T>::Length() {
		return std::sqrt(Length2());
	}
	
	template <typename T>
	double Line<T>::getOrientation() {
		return std::atan2(pointB.y - pointA.y, pointB.x - pointA.x);
	}
}