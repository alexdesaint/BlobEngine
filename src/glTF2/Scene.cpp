#include <BlobEngine/glTF2/Scene.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {
	Scene::Scene(Reader::JsonExplorer explorer, Mesh &m) {

		int size = explorer.getArraySize("nodes");

		for (unsigned int i = 0; i < size; i++) {
			nodes.emplace_back(explorer.getArrayInt("nodes", i), explorer, m);
		}

		for (unsigned int i = 0; i < size; i++) {
			addRenderable(&nodes[i]);
		}
	}

	glTF2::Shape &Scene::getShape(unsigned int num) {
		return nodes[num];
	}

	std::ostream &operator<<(std::ostream &s, const Scene &a) {
		s << "Scene {" << endl;
		for (const Shape &node : a.nodes)
			s << node;
		s << "}" << endl;
		return s;
	}
}
