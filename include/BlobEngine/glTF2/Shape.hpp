#ifndef BLOBENGINE_SHAPE_HPP
#define BLOBENGINE_SHAPE_HPP

#include <BlobEngine/glTF2/Mesh.hpp>
#include <glm/mat4x4.hpp>

namespace BlobEngine::glTF2 {

	class Shape { //un objet à modéliser
	public:
		std::vector<Shape> children;
		Mesh mesh;

		// déjà dans Shape
		glm::mat4 matrix{1};
		glm::vec3 translation{};
		glm::vec4 rotation{};
		glm::vec3 scale{};

		explicit Shape(int num, Reader::JsonExplorer explorer);

		friend std::ostream &operator<<(std::ostream &s, const Shape &a);
	};
}

#endif //BLOBENGINE_SHAPE_HPP
