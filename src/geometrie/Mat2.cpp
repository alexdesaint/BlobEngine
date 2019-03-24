#include <Blob/Geometrie.hpp>

#include <cmath>
#include <iostream>

namespace Blob {

	template<typename T>
<<<<<<< HEAD
	float Vec2<T>::length() {
=======
    float Vec2<T>::length() {
>>>>>>> tmp
		return std::sqrt(x * x + y * y);
	}

	template<typename T>
<<<<<<< HEAD
	float Vec2<T>::getOrientation() {
=======
    float Vec2<T>::getOrientation() {
>>>>>>> tmp
		return std::atan2(y, x);
	}

	template<typename T>
<<<<<<< HEAD
	float Vec2<T>::getOrientationDeg() {
=======
    float Vec2<T>::getOrientationDeg() {
>>>>>>> tmp
		return std::atan2(y, x) * 180 / PI;
	}

	template<typename T>
<<<<<<< HEAD
	Vec2<T> Vec2<T>::setLength(float newLength) {
=======
    Vec2<T> Vec2<T>::setLength(float newLength) {
>>>>>>> tmp
		float oldLength = length2();
		newLength = newLength * newLength;

		if (oldLength != 0) {
			float Rapport = std::sqrt(newLength / oldLength);

			x *= Rapport;
			y *= Rapport;
		}

		return *this;
	}
}
