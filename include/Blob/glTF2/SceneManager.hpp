#ifndef BLOBENGINE_SCENEMANAGER_HPP
#define BLOBENGINE_SCENEMANAGER_HPP

#include <Blob/glTF2/Asset.hpp>
#include <Blob/glTF2/Accessor.hpp>
#include <Blob/glTF2/Scene.hpp>
#include <Blob/glTF2/Mesh.hpp>
#include <Blob/glTF2/BufferView.hpp>
#include <Blob/glTF2/Node.hpp>
#include <Blob/glTF2/Buffer.hpp>
#include <Blob/glTF2/Image.hpp>
#include <Blob/glTF2/Sampler.hpp>
#include <Blob/glTF2/Texture.hpp>
#include <Blob/glTF2/Material.hpp>

namespace Blob::glTF2 {
	class SceneManager {
	public:

        // version check
		Asset asset;

        // buffer part
        std::list<Buffer> buffers;
        std::list<BufferView> bufferViews;

        // material part
        std::list<Image> images;
        std::list<Sampler> samplers;
        std::list<Texture> textures;
        std::list<Material> materials;

        // model part
        std::list<Accessor> accessors;
        std::list<Mesh> meshes;
        std::list<Node> nodes;
        std::list<Scene> scenes;

		explicit SceneManager(const std::string &file);

        friend std::ostream &operator<<(std::ostream &s, const SceneManager &a);
	};
}

#endif //BLOBENGINE_SCENEMANAGER_HPP
