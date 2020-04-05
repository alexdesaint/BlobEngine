#pragma once

#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/Mesh.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {

class Mesh {
public:
    class Primitive {
        friend Mesh;

    public:
        class Attribute {
        public:
            int POSITION = -1;
            int NORMAL = -1;
            int TANGENT = -1;
            int TEXCOORD_0 = -1;
            int TEXCOORD_1 = -1;
            int COLOR_0 = -1;
            int JOINTS_0 = -1;
            int WEIGHTS_0 = -1;
        }; ///< attributes : A dictionary object, where each key corresponds to
        ///< mesh attribute semantic and each value is the index of the accessor containing attribute's data.
        ///< see : https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#meshes

        Attribute attributes;

        int indices = -1;  ///< The index of the accessor that contains the indices.
        int material = -1; ///< The index of the material to apply to this primitive when rendering.
        int mode = 4;      ///< The type of primitives to render. default: 4
        // targets; ///< An array of Morph Targets, each Morph Target is a dictionary mapping attributes
        // (only POSITION, NORMAL, and TANGENT supported) to their deviations in the Morph Target.

        //GL::VertexArrayObject vao;

        friend std::ostream &operator<<(std::ostream &s, const Primitive &a);
    };

    // Blob::Mesh mesh;

    std::vector<Primitive> primitives; ///< An array of primitives, each defining geometry to be rendered with a
    ///< material. Required
    std::vector<int> weights; ///< Array of weights to be applied to the Morph Targets.
    std::string name;         ///< The user-defined name of this object.

    Mesh(const nlohmann::json &j);

    friend std::ostream &operator<<(std::ostream &s, const Primitive &a);

    friend std::ostream &operator<<(std::ostream &s, const Mesh &a);
};

void from_json(const nlohmann::json &j, Mesh::Primitive::Attribute &a);
void from_json(const nlohmann::json &j, Mesh::Primitive &a);

} // namespace Blob::glTF2
