#ifndef BLOBENGINE_SCENEMANAGER_HPP
#define BLOBENGINE_SCENEMANAGER_HPP

#include <BlobEngine/glTF2/Asset.hpp>
#include <BlobEngine/glTF2/Buffer.hpp>
#include <BlobEngine/glTF2/BufferView.hpp>
#include <BlobEngine/glTF2/Scene.hpp>

#include <vector>

namespace BlobEngine::glTF2 {
	class SceneManager {
	public:

		std::vector<Scene> scenes;

		int defaultScene = 0;

		Reader::JsonExplorer baseNode;

		Asset asset;
		Buffer buffer;
		BufferView bufferView;
		Accessor accessor;

		explicit SceneManager(const std::string &file);

		Scene& getScene(unsigned int num);

		friend std::ostream& operator<<(std::ostream &s, const SceneManager &a);
	};
}

#endif //BLOBENGINE_SCENEMANAGER_HPP
