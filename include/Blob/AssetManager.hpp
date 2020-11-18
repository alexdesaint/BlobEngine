#pragma once

#include <Blob/Materials.hpp>
#include <Blob/Shaders.hpp>
#include <Blob/Shapes.hpp>

#include <Blob/Core/Buffer.hpp>
#include <Blob/Core/Material.hpp>
#include <Blob/Core/Mesh.hpp>
#include <Blob/Core/Scene.hpp>
#include <Blob/Core/Shape.hpp>
#include <Blob/Core/Texture.hpp>

namespace Blob {
class AssetManager {
public:
    /*
        Shaders::SingleColor shaderSingleColor;
        Shaders::PBRSingleColor shaderPBRSingleColor;
        Shaders::PBRSingleTexture shaderPBRSingleTexture;
    */

    Materials::SingleColor defaultMaterial;
    Shapes shapes;

    /*std::unordered_map<std::string, Core::Shader> shaders;

    std::unordered_map<std::string, Core::Primitive> primitives;

    std::unordered_map<std::string, Core::Buffer> buffers;

    std::unordered_map<std::string, Core::Texture> textures;
    std::unordered_map<std::string, Core::Material> materials;

    // model part
    std::unordered_map<std::string, Core::Accessor> accessors;
    std::unordered_map<std::string, Core::Mesh> meshes;
    std::unordered_map<std::string, Core::Shape> nodes;
    std::unordered_map<std::string, Core::Scene> scenes;*/

    AssetManager();
};
} // namespace Blob