#ifndef BLOBENGINE_MESH_HPP
#define BLOBENGINE_MESH_HPP

#include <iostream>
#include <nlohmann/json.hpp>

#include <Blob/glTF2/Accessor.hpp>
#include <Blob/glTF2/Material.hpp>
#include <Blob/GL/Renderable.hpp>

namespace Blob::glTF2 {

    class Mesh {
    public:

        class Primitive : public GL::Renderable {
            friend Mesh;
        public:
            /// attributes : A dictionary object, where each key corresponds to mesh attribute semantic and each value
            /// is the index of the accessor containing attribute's data.

            std::map<std::string, int> attributes; ///< attributes : A dictionary object, where each key corresponds to
            ///< mesh attribute semantic and each value is the index of the accessor containing attribute's data.
            ///< see : https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#meshes

            int indices = -1; ///< The index of the accessor that contains the indices.
            int material = -1; ///< The index of the material to apply to this primitive when rendering.
            int mode = 4; ///< The type of primitives to render. default: 4
            // targets; ///< An array of Morph Targets, each Morph Target is a dictionary mapping attributes
            // (only POSITION, NORMAL, and TANGENT supported) to their deviations in the Morph Target.

            explicit Primitive(const nlohmann::json &j,
                               std::list<Blob::glTF2::Accessor> &a,
                               std::list<Material> &materials);

            friend std::ostream &operator<<(std::ostream &s, const Primitive &a);
        };

        std::list<Primitive> primitives; ///<An array of primitives, each defining geometry to be rendered with a
        ///< material. Required
        std::vector<int> weights; ///<Array of weights to be applied to the Morph Targets.
        std::string name; ///< The user-defined name of this object.

        Mesh(const nlohmann::json &j, std::list<Accessor> &a, std::list<Material> &materials);

        friend std::ostream &operator<<(std::ostream &s, const Primitive &a);

        friend std::ostream &operator<<(std::ostream &s, const Mesh &a);
    };
}

#endif //BLOBENGINE_MESH_HPP
