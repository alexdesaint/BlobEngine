#include <BlobEngine/Geometrie.hpp>

#include <cmath>
#include <iostream>

namespace Blob {

	template<typename T>
	float Mat2<T>::length() {
		return std::sqrt(x * x + y * y);
	}

	template<typename T>
	float Mat2<T>::getOrientation() {
		return std::atan2(y, x);
	}

	template<typename T>
	float Mat2<T>::getOrientationDeg() {
		return std::atan2(y, x) * 180 / PI;
	}

	template<typename T>
	Mat2<T> Mat2<T>::setLength(float newLength) {
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
