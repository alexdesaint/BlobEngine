#include <BlobEngine/glTF2/SceneManager.hpp>
#include <BlobEngine/glTF2/Scene.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	SceneManager::SceneManager(const std::string &file) :
			baseNode(file),
			buffer(baseNode),
			asset(baseNode),
			bufferView(baseNode),
			accessor(baseNode) {
		if (baseNode.hasMember("scene"))
			defaultScene = baseNode.getInt("scene");

		if (baseNode.hasMember("version"))
			defaultScene = baseNode.getInt("scene");

		Reader::JsonExplorer scenesObject = baseNode.getArray("scenes");

		int size = scenesObject.getArraySize();

		for (unsigned int i = 0; i < size; i++) {
			scenes.emplace_back(scenesObject.getArrayObject(i));
		}
	}

	Scene& SceneManager::getScene(unsigned int num) {
		return scenes[num];
	}

	std::ostream &operator<<(std::ostream &s, const SceneManager &a) {
		s << "SceneManager {" << endl;

		s << a.asset;
		s << a.buffer;
		s << a.bufferView;
		s << a.accessor;

		//for(const Scene &scene : a.scenes)
		//	s << scene;

		s << "}" << endl;
		return s;
	}

}