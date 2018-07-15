#include <BlobEngine/Shape.hpp>

#include <BlobEngine/BlobException.hpp>

#include <iostream>

using namespace BlobEngine;
using namespace std;

int main() {

	try {
		Shape shape;
		shape.loadOBJ(R"(../data/sphere.obj)");

	} catch (BlobException &e) {
		std::cout << e.what();
	}

	return 0;
}