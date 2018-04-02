#include <BlobEngine/Geometrie.hpp>

#include <cmath>

namespace BlobEngine {

	template<typename T>
	double Mat2<T>::length() {
		return std::sqrt(length2());
	}

	template<typename T>
	double Mat2<T>::getOrientationRad() {
		return std::atan2(y, x);
	}

	template<typename T>
	double Mat2<T>::getOrientationDeg() {
		return std::atan2(y, x) * 180 / PI;
	}

	template<typename T>
	Mat2<T> Mat2<T>::setLength(double newLength) {
		double oldLength = length();
		double Rapport;

		if (oldLength != 0) {
			Rapport = newLength / oldLength;
			x *= Rapport;
			y *= Rapport;
		}
		return *this;
	}

	template<typename T>
	void Mat2<T>::round(int v) {
		v = (int) pow(10, v);
		x = std::round(x * v) / v;
	}
}