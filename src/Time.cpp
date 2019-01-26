#include <BlobEngine/Time.hpp>

namespace BlobEngine::Time {

	FunctionNow now = &std::chrono::high_resolution_clock::now;

}
