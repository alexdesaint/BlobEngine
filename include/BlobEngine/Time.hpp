//
// Created by Muta on 05/07/2018.
//

#ifndef BLOBENGINE_TIME_HPP
#define BLOBENGINE_TIME_HPP

#include <chrono>

namespace BlobEngine {

	float getElapsedTime() {
		static std::chrono::high_resolution_clock::time_point lastFrameTime;

		auto now = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> diff = now - lastFrameTime;

		lastFrameTime = now;

		return diff.count();
	}

	float getTime() {
		static auto start_time = std::chrono::high_resolution_clock::now();

		auto now = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> diff = now - start_time;

		return diff.count();
	}
}
#endif //BLOBENGINE_TIME_HPP
