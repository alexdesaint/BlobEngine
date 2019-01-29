#include <BlobEngine/Time.hpp>

namespace Blob::Time {

	FunctionNow now = &std::chrono::high_resolution_clock::now;

}
