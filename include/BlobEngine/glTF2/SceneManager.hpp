#ifndef BLOBENGINE_SCENEMANAGER_HPP
#define BLOBENGINE_SCENEMANAGER_HPP

#include <BlobEngine/glTF2/Asset.hpp>
#include <BlobEngine/glTF2/Scene.hpp>
#include <BlobEngine/glTF2/Mesh.hpp>

#include <vector>

namespace BlobEngine::glTF2 {
	class SceneManager {
		friend BufferView;
		friend Accessor;
	public:

		std::vector<Scene> scenes;

		Reader::JsonExplorer baseNode;

		Asset asset;
		Mesh mesh;

		explicit SceneManager(const std::string &file);

		Scene& getScene(unsigned int num);

		friend std::ostream& operator<<(std::ostream &s, const SceneManager &a);
	};
}

#endif //BLOBENGINE_SCENEMANAGER_HPP
