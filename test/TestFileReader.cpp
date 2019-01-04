#include <BlobEngine/BlobException.hpp>

#include <iostream>

using namespace std;

int main() {

	try {

	} catch (BlobException &e) {
		std::cout << e.what();
	}

	return 0;
}