#ifndef BLOBENGINE_MESH_HPP
#define BLOBENGINE_MESH_HPP

#include <BlobEngine/BlobGL/Renderable.hpp>
#include <BlobEngine/glTF2/Accessor.hpp>

namespace Blob::glTF2 {

	class Mesh {
	private:

		struct Data {
			GLfloat coor[3];
			GLfloat normal[3];
			GLfloat texCoor[2];
		};

		std::vector<Data> dataBuffer;

		Buffer buffer;

		Accessor accessor;

		class Primitive : public GL::Renderable {
			friend Mesh;
		private:
			unsigned int dataBufferOffset = 0;

			int position = -1;
			int normal = -1;
			int indices = -1;
		};

		std::vector<std::vector<Primitive>> primitives;

		GL::VertexBufferObject vbo;

	public:
		explicit Mesh(Reader::JsonExplorer explorer);

		friend std::ostream &operator<<(std::ostream &s, Mesh &a);

		std::vector<GL::Renderable *> getShape(int mesh);
	};
}

#endif //BLOBENGINE_MESH_HPP
