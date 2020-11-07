#pragma once

#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/Mesh.hpp>
#include <Blob/glTF2/Accessor.hpp>
#include <Blob/glTF2/Buffer.hpp>
#include <Blob/glTF2/BufferView.hpp>
#include <Blob/glTF2/Material.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

namespace Blob::glTF2 {

class Mesh {
public:
    class Primitive : public Core::Mesh {
        friend Mesh;

    public:
        class Attribute : public GL::VertexArrayObject {
        private:
        public:
            int POSITION = -1;
            int NORMAL = -1;
            int TANGENT = -1;
            int TEXCOORD_0 = -1;
            int TEXCOORD_1 = -1;
            int COLOR_0 = -1;
            int JOINTS_0 = -1;
            int WEIGHTS_0 = -1;
            Attribute(const nlohmann::json &j, std::vector<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
                      std::vector<glTF2::BufferView> &bufferViews);

            friend std::ostream &operator<<(std::ostream &s, const Attribute &a);
        } attributes; ///< attributes : A dictionary object, where each key corresponds to
        ///< mesh attribute semantic and each value is the index of the accessor containing attribute's data.
        ///< see : https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#meshes

        int indices = -1;  ///< The index of the accessor that contains the indices.
        int material = -1; ///< The index of the material to apply to this primitive when rendering.
        /// TODO: Use this :
        int mode = 4;      ///< The type of primitives to render. default: 4
        // targets; ///< An array of Morph Targets, each Morph Target is a dictionary mapping attributes
        // (only POSITION, NORMAL, and TANGENT supported) to their deviations in the Morph Target.

        // Engine variable
        std::vector<uint8_t> indicesArray;

        Primitive(const nlohmann::json &j, std::vector<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
                  std::vector<glTF2::BufferView> &bufferViews, std::vector<glTF2::Material> &materials);

        friend std::ostream &operator<<(std::ostream &s, const Primitive &a);
    };

    std::vector<Primitive> primitives; ///< An array of primitives, each defining geometry to be rendered with a
    ///< material. Required
    std::vector<int> weights; ///< Array of weights to be applied to the Morph Targets.
    std::string name;         ///< The user-defined name of this object.

    Mesh() = delete;

    Mesh(const nlohmann::json &j, std::vector<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
         std::vector<glTF2::BufferView> &bufferViews, std::vector<glTF2::Material> &materials);

    friend std::ostream &operator<<(std::ostream &s, const Primitive &a);

    friend std::ostream &operator<<(std::ostream &s, const Mesh &a);
};

void from_json(const nlohmann::json &j, Mesh::Primitive::Attribute &a);
void from_json(const nlohmann::json &j, Mesh::Primitive &a);

} // namespace Blob::glTF2
