#pragma once

#include <deque>
#include <vector>

#include <Blob/AssetManager.hpp>
#include <Blob/glTF2/Accessor.hpp>
#include <Blob/glTF2/Asset.hpp>
#include <Blob/glTF2/Buffer.hpp>
#include <Blob/glTF2/BufferView.hpp>
#include <Blob/glTF2/Image.hpp>
#include <Blob/glTF2/Material.hpp>
#include <Blob/glTF2/Mesh.hpp>
#include <Blob/glTF2/Node.hpp>
#include <Blob/glTF2/Sampler.hpp>
#include <Blob/glTF2/Scene.hpp>
#include <Blob/glTF2/Texture.hpp>

namespace Blob::glTF2 {
class SceneManager : AssetManager {
private:
    std::string file;
public:
    // version check
    Asset asset;

    // buffer part
    std::vector<glTF2::Buffer> buffers;
    std::vector<glTF2::BufferView> bufferViews;

    // material part
    std::vector<glTF2::Image> images;
    std::vector<glTF2::Sampler> samplers;
    std::vector<glTF2::Texture> textures;
    std::vector<glTF2::Material> materials;

    // model part
    std::vector<glTF2::Accessor> accessors;
    std::vector<glTF2::Mesh> meshes;
    std::vector<glTF2::Node> nodes;
    std::vector<glTF2::Scene> scenes;

    //
    Core::Buffer buffer;
    std::vector<uint8_t> finalBuffer;

    explicit SceneManager(const std::string &file);

    friend std::ostream &operator<<(std::ostream &s, const SceneManager &a);

    void copyToBuffer(int attribute, std::unordered_map<int, std::vector<uint8_t>> &bufferData, size_t &cursor, int i);

    void setPrimitive(int accessor, int position, const Mesh::Primitive &p, size_t &relativeOffset);
    std::string getPrimitiveLine(int accessor, int position, unsigned int p, size_t &relativeOffset) const;

    void createVBO();

    [[nodiscard]] std::string toCHeader() const;
};
} // namespace Blob::glTF2
