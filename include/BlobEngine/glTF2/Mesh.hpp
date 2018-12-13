#ifndef BLOBENGINE_MESH_HPP
#define BLOBENGINE_MESH_HPP

#include <BlobEngine/glTF2/Accessor.hpp>

namespace BlobEngine::glTF2 {

	class Mesh { //un sous-objet appartenant à un objet
	private:
		class Primitive {
		private:

			class Attributes {
			public:
				//Accessor accessor;

				explicit Attributes(Reader::JsonExplorer explorer);
			};

		public:

			Attributes attributes;

			explicit Primitive(Reader::JsonExplorer explorer);

		};

		std::vector<Primitive> primitives;

	public:
		void load(int num, Reader::JsonExplorer explorer);

		//BlobGL::VertexArrayObject& getVAO();

		friend std::ostream &operator<<(std::ostream &s, const Mesh &a);
	};
}

#endif //BLOBENGINE_MESH_HPP
