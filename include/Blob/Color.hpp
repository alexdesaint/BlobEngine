#ifndef BLOBENGINE_COLOR_HPP
#define BLOBENGINE_COLOR_HPP

#include <cstdint>

namespace BlobEngine {
	class Color {
	private:
		uint8_t R, G, B, A;
	public:
		Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A) :
				R(R),
				G(G),
				B(B),
				A(A) {}
	};
}

#endif //BLOBENGINE_COLOR_HPP
