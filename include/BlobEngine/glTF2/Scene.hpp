#ifndef BLOBENGINE_SCENE_HPP
#define BLOBENGINE_SCENE_HPP

#include <BlobEngine/glTF2/Shape.hpp>

#include <vector>

namespace BlobEngine::glTF2 {

	class Scene {
	public:

		std::vector<Shape> nodes;

		explicit Scene(Reader::JsonExplorer explorer);

		Shape& getShape(unsigned int num);

		friend std::ostream& operator<<(std::ostream &s, const Scene &a);
	};
}

#endif //BLOBENGINE_SCENE_HPP
