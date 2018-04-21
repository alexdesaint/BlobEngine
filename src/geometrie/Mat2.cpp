#include <BlobEngine/Geometrie.hpp>

#include <cmath>
#include <iostream>
#include <limits>

namespace BlobEngine {

	template<typename T>
	double Mat2<T>::length() {
		return std::nextafter(std::sqrt(length2()), std::numeric_limits<double>::infinity());
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
		double oldLength = length2();
		double Rapport;
		newLength = newLength * newLength;
		
		if (oldLength != 0) {
			Rapport = sqrt(newLength / oldLength);
			
			if (x > 0)
				x = (x * Rapport) + 1;
			else
				x = (x * Rapport) - 1;
			
			if (y > 0)
				y = (y * Rapport) + 1;
			else
				y = (y * Rapport) - 1;
		}
		
		if (length2() < newLength)
			std::cout << "Error on setLength" << std::endl;
		
		return *this;
	}

	/*template<typename T>
	void Mat2<T>::round(int v) {
		v = (int) pow(10, v);
		x = std::round(x * v) / v;
		y = std::round(y * v) / v;
	}*/
}