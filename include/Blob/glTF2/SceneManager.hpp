#ifndef BLOBENGINE_SCENEMANAGER_HPP
#define BLOBENGINE_SCENEMANAGER_HPP

#include <BlobEngine/glTF2/Asset.hpp>
#include <BlobEngine/glTF2/Scene.hpp>
#include <BlobEngine/glTF2/Mesh.hpp>

#include <vector>

namespace Blob::glTF2 {
	class SceneManager {
		friend BufferView;
		friend Accessor;
	public:

		Reader::JsonExplorer baseNode;

		Asset asset;
		Mesh mesh;

		std::vector<Scene> scenes;

		explicit SceneManager(const std::string &file);

		Scene &getScene(unsigned int num);

		friend std::ostream &operator<<(std::ostream &s, SceneManager &a);
	};
}

#endif //BLOBENGINE_SCENEMANAGER_HPP
