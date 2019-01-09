#ifndef BLOBENGINE_TIME_HPP
#define BLOBENGINE_TIME_HPP

#include <chrono>

namespace BlobEngine::Time {

	typedef std::chrono::high_resolution_clock::time_point TimePoint;
	typedef std::chrono::duration<float> Duration;

	typedef std::chrono::high_resolution_clock::time_point (*FunctionNow) ();
	extern FunctionNow now;

	/*
	float getElapsedTime() {
		static TimePoint lastFrameTime;

		TimePoint now = std::chrono::high_resolution_clock::now();

		Duration diff = now - lastFrameTime;

		lastFrameTime = now;

		return diff.count();
	}

	float getTime() {
		static auto start_time = std::chrono::high_resolution_clock::now();

		auto now = std::chrono::high_resolution_clock::now();

		Duration diff = now - start_time;

		return diff.count();
	}
	 */
}
#endif //BLOBENGINE_TIME_HPP
