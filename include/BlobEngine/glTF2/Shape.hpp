#ifndef BLOBENGINE_SHAPE_GLTF2_HPP
#define BLOBENGINE_SHAPE_GLTF2_HPP

#include <BlobEngine/glTF2/Mesh.hpp>

class BlobEngine::glTF2::SceneManager;

namespace BlobEngine::glTF2 {

	class Shape { //un objet à modéliser
	public:
		std::vector<Shape> children;

		int mesh;

		const SceneManager &sm;

		explicit Shape(int num, Reader::JsonExplorer explorer, const SceneManager &sm);

		friend std::ostream &operator<<(std::ostream &s, const Shape &a);

		BlobGL::Shape getShape();
	};
}

#endif //BLOBENGINE_SHAPE_HPP
