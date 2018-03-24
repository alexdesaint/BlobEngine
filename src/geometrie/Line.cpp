#include <BlobEngine/Geometrie.hpp>

#include <cmath>

namespace BlobEngine {

	Mat2<float> Line::closestPointTo(Point2f point) {

		float A1 = pointB.y - pointA.y;
		float B1 = pointA.x - pointB.x;;
		float C1 = A1 * pointA.x + B1 * pointA.y;
		float C2 = -B1 * point.x + A1 * point.y;

		float det = A1 * A1 - -B1 * B1;

		if (det != 0) {
			return {((A1 * C1 - B1 * C2) / det), ((A1 * C2 - -B1 * C1) / det)};
		} else {
			return point;
		}
	}

	Mat2<float> Line::getIntersectionPoint(Line B) {

		float A1 = pointA.x - pointB.x;

		float B1 = B.pointA.x - B.pointB.x;

		float A2 = pointA.y - pointB.y;

		float B2 = B.pointA.y - B.pointB.y;

		float det = A1 * B2 - A2 * B1;

		if (det == 0)
			return {};

		float C1 = pointB.y * pointA.x - pointB.x * pointA.y;

		float C2 = B.pointB.y * B.pointA.x - B.pointB.x * B.pointA.y;

		return {(C1 * B1 - A1 * C2) / det, (C1 * B2 - A2 * C2) / det};
	}

	float Line::Length() {
		return std::sqrt(Length2());
	}

	float Line::getOrientation() {
		return std::atan2(pointB.y - pointA.y, pointB.x - pointA.x);
	}
}