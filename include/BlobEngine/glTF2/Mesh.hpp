#ifndef BLOBENGINE_MESH_HPP
#define BLOBENGINE_MESH_HPP

#include <BlobEngine/BlobGL/Shape.hpp>
#include <BlobEngine/glTF2/Accessor.hpp>

namespace BlobEngine::glTF2{

	class Mesh { //un sous-objet appartenant à un objet
	private:

		struct Attributes {
			int position;
		};


		struct Primitive {
			int indices;

			Attributes attributes;
		};

		struct Data {
			std::vector<Primitive> primitives;
		};

		std::vector<Data> data;

		Accessor accessor;

	public:
		explicit Mesh(Reader::JsonExplorer explorer);

		friend std::ostream &operator<<(std::ostream &s, const Mesh &a);

		BlobGL::Shape getShape(int mesh);
	};
}

#endif //BLOBENGINE_MESH_HPP
