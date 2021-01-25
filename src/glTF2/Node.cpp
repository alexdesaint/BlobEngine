#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Node.hpp>

using namespace std;

namespace Blob::glTF2 {

Node::Node(const nlohmann::json &j, std::deque<glTF2::Mesh> &meshes) {
    NotRequired(j, "camera", camera);
    NotRequired(j, "children", children);
    NotRequired(j, "skin", skin);

    std::array<float, 16> matrix = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}; ///< A floating-point 4x4 transformation
    ///< matrix stored in column-major order. default: [1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]

    float rotation[4]{0, 0, 0, 1}; ///< The node's unit quaternion rotation in the order (x, y, z, w),
    ///< where w is the scalar. default: [0,0,0,1]

    float scale[3]{1, 1, 1}; ///< The node's non-uniform scale, given as the scaling factors along the
    ///< x, y, and z axes. default: [1,1,1]

    float translation[3]{0, 0, 0}; ///< The node's translation along the x, y, and z axes.
    ///< default: [0,0,0]

    if (NotRequired(j, "mesh", mesh))
        setMesh(meshes[mesh]);

    if (NotRequired(j, "matrix", matrix))
        load(matrix);

    if (NotRequired(j, "rotation", rotation))
        setRotation(Maths::Vec4<float>(rotation));

    if (NotRequired(j, "scale", scale))
        setScale(Maths::Vec3<float>(scale));
    if (NotRequired(j, "translation", translation))
        setPosition(Maths::Vec3<float>(translation));

    NotRequired(j, "weights", weights);
    NotRequired(j, "name", name);
}

void Node::updateChild(std::deque<Node> &nodes) {
    for (auto i : children)
        addChild(nodes[i]);
}

std::ostream &operator<<(std::ostream &s, const Node &a) {
    s << "  Node {" << endl;

    if (a.camera != -1)
        s << "    camera : " << a.camera << endl;

    if (!a.children.empty()) {
        s << "    children : ";
        for (const auto &b : a.children)
            s << " " << b;
        s << endl;
    }

    if (a.skin != -1)
        s << "    skin : " << a.skin << endl;

    if (a.mesh != -1)
        s << "    mesh : " << a.mesh << endl;

    s << (Maths::ModelTransform) a << endl;

    if (!a.weights.empty()) {
        s << "    weights :";
        for (const auto &b : a.weights)
            s << " " << b;
        s << endl;
    }

    if (!a.name.empty())
        s << "    name : " << a.name << endl;

    s << "  }" << endl;
    return s;
}
} // namespace Blob::glTF2