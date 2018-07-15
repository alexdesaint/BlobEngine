//
// Created by Muta on 05/07/2018.
//

#ifndef BLOBENGINE_COLOR_HPP
#define BLOBENGINE_COLOR_HPP

#include <cstdint>

namespace BlobEngine {
	class Color {
	private:
		uint8_t R, G, B;
	public:
		Color(uint8_t R, uint8_t G, uint8_t B) :
				R(R),
				G(G),
				B(B) {

		}
	};
}

#endif //BLOBENGINE_COLOR_HPP
