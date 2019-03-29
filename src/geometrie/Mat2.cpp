#include <Blob/Geometrie.hpp>

#include <cmath>
#include <iostream>

namespace Blob {

    template
    class Vec2<float>;

    template
    class Vec2<int>;

	template<typename T>
    float Vec2<T>::length() {
		return std::sqrt(x * x + y * y);
	}

    template float Vec2<float>::length();

    template float Vec2<int>::length();

	template<typename T>
    float Vec2<T>::getOrientation() {
		return std::atan2(y, x);
	}

    template float Vec2<float>::getOrientation();

    template float Vec2<int>::getOrientation();

	template<typename T>
    float Vec2<T>::getOrientationDeg() {
		return std::atan2(y, x) * 180 / PI;
	}

    template float Vec2<float>::getOrientationDeg();

    template float Vec2<int>::getOrientationDeg();

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

    template Vec2<float> Vec2<float>::setLength(float newLength);
}
