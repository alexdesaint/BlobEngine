#include "Geometrie.hpp"

#include <cmath>

using namespace Geometrie;

//Line

float Line::Length() {
	return std::sqrt((pointB.x - pointA.x) * (pointB.x - pointA.x) + (pointB.y - pointA.y) * (pointB.y - pointA.y));
}

float Line::Length2() {
	return (pointB.x - pointA.x) * (pointB.x - pointA.x) + (pointB.y - pointA.y) * (pointB.y - pointA.y);
}

//Fonctions
float Geometrie::ProduitScalaire(Vec2f A, Vec2f B) {
	return A.x * B.x + A.y * B.y;
}

float Geometrie::Distance(Point2f PointA, Point2f PointB)
{
	return std::sqrt((PointB.x - PointA.x) * (PointB.x - PointA.x) + (PointB.y - PointA.y) * (PointB.y - PointA.y));
}

float Geometrie::Distance2(Point2f PointA, Point2f PointB)
{
	return (PointB.x - PointA.x) * (PointB.x - PointA.x) + (PointB.y - PointA.y) * (PointB.y - PointA.y);
}

bool Geometrie::Intersection(Line A, Line B, Point2f *inter)
{
	//1 : A, A --> A.pointA
	//2 : A, B --> A.pointB
	//3 : B, A --> B.pointA
	//4 : B, B --> B.pointB
	
	float A1 = A.pointA.x - A.pointB.x;

	float B1 = B.pointA.x - B.pointB.x;

	float A2 = A.pointA.y - A.pointB.y;

	float B2 = B.pointA.y - B.pointB.y;

	float det = A1*B2 - A2*B1;

	if (det == 0)
		return false;

	float C1 = A.pointB.y * A.pointA.x - A.pointB.x * A.pointA.y;

	float C2 = B.pointB.y * B.pointA.x - B.pointB.x * B.pointA.y;

	inter->x = (C1*B1 - A1*C2) / det;
	inter->y = (C1*B2 - A2*C2) / det;

	return true;
}

Geometrie::Point2f Geometrie::ClosestPointOnLine(Line line, Point2f point) {

	float A1 = line.pointB.y - line.pointA.y;
	float B1 = line.pointA.x - line.pointB.x;;
	float C1 = A1*line.pointA.x + B1*line.pointA.y;
	float C2 = -B1*point.x + A1*point.y;

	float det = A1*A1 - -B1*B1;

	if (det != 0) {
		return {((A1*C1 - B1*C2) / det), ((A1*C2 - -B1*C1) / det)};
	}
	else {
		return point;
	}
}