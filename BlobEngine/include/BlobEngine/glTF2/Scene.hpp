#ifndef BLOBENGINE_SCENE_HPP
#define BLOBENGINE_SCENE_HPP

#include <BlobEngine/BlobGL/Scene.hpp>
#include <BlobEngine/glTF2/Shape.hpp>
#include <BlobEngine/glTF2/Mesh.hpp>

#include <vector>

namespace BlobEngine::glTF2 {

	class Scene : public BlobGL::Scene {
	public:

		std::vector<glTF2::Shape> nodes;

		explicit Scene(Reader::JsonExplorer explorer, Mesh &m);

		glTF2::Shape& getShape(unsigned int num);

		friend std::ostream& operator<<(std::ostream &s, const Scene &a);
	};
}

#endif //BLOBENGINE_SCENE_HPP
