#include <BlobEngine/glTF2/Scene.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {
	Scene::Scene(Reader::JsonExplorer explorer, Mesh &m) {
		explorer.goToBaseNode();

		int size = explorer.getArraySize("nodes");

		for (unsigned int i = 0; i < size; i++) {
			Reader::JsonExplorer n = explorer.getArrayObject("nodes", i);
			nodes.emplace_back(n.getInt("mesh"), explorer, m);
		}
	}

	Shape& Scene::getShape(unsigned int num) {
		return nodes[num];
	}

	std::ostream &operator<<(std::ostream &s, const Scene &a) {
		s << "Scene {" << endl;
		for(const Shape &node : a.nodes)
			s << node;
		s << "}" << endl;
		return s;
	}
}
