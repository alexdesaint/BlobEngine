#pragma once

#include <deque>
#include <vector>

#include <Blob/glTF2/Accessor.hpp>
#include <Blob/glTF2/Asset.hpp>
#include <Blob/glTF2/Buffer.hpp>
#include <Blob/glTF2/BufferView.hpp>
#include <Blob/glTF2/Mesh.hpp>
#include <Blob/glTF2/Node.hpp>
#include <Blob/glTF2/Scene.hpp>
/*
#include <Blob/glTF2/Image.hpp>
#include <Blob/glTF2/Material.hpp>
#include <Blob/glTF2/Sampler.hpp>
#include <Blob/glTF2/Texture.hpp>
*/

namespace Blob::glTF2 {
class SceneManager {
public:

    // version check
    Asset asset;

    // buffer part
    std::vector<Buffer> buffers;
    std::vector<BufferView> bufferViews;

    // material part
    //    std::vector<Image> images;
    //    std::vector<Sampler> samplers;
    //    std::vector<Texture> textures;
    //    std::vector<Material> materials;

    // model part
    std::vector<Accessor> accessors;
    std::vector<Mesh> meshes;
    std::vector<Node> nodes;
    std::vector<Scene> scenes;

    explicit SceneManager(const std::string &file);

    friend std::ostream &operator<<(std::ostream &s, const SceneManager &a);

    void createVBO(std::string path);
};
} // namespace Blob::glTF2
