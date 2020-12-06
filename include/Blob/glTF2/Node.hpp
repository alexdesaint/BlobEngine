#pragma once

#include <Blob/glTF2/Mesh.hpp>
#include <Blob/Core/Shape.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {

class Node : public Core::Shape {
public:
    int camera = -1; ///< The index of the camera referenced by this node.

    std::vector<int> children; ///< The indices of this node's children.

    int skin = -1; ///< The index of the skin referenced by this node.

    int mesh = -1; ///< The index of the mesh in this node.

    std::vector<float> weights; ///< The weights of the instantiated Morph Target. Number of elements must match
                                ///< number of Morph Targets of used mesh.

    std::string name; ///< The user-defined name of this object.

    friend std::ostream &operator<<(std::ostream &s, const Node &a);
    Node(const nlohmann::json &j, std::deque<glTF2::Mesh> &meshes);

    void updateChild(std::deque<Node> &nodes);
};

} // namespace Blob::glTF2
