#include <Blob/Geometrie.hpp>

#include <cmath>
#include <iostream>

namespace Blob {

	template<typename T>
    float Vec2<T>::length() {
		return std::sqrt(x * x + y * y);
	}

	template<typename T>
    float Vec2<T>::getOrientation() {
		return std::atan2(y, x);
	}

	template<typename T>
    float Vec2<T>::getOrientationDeg() {
		return std::atan2(y, x) * 180 / PI;
	}

	template<typename T>
    Vec2<T> Vec2<T>::setLength(float newLength) {
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
