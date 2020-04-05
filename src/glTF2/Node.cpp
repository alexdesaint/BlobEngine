#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Node.hpp>

using namespace std;

namespace Blob::glTF2 {

Node::Node(const nlohmann::json &j, std::vector<glTF2::Mesh> &meshes) {
    NotRequired(j, "camera", camera);
    NotRequired(j, "children", children);
    NotRequired(j, "skin", skin);
    NotRequired(j, "matrix", matrix);
    //if(NotRequired(j, "mesh", mesh) && !meshes[mesh].primitives.empty())
    //    setMesh(meshes[mesh].primitives[0]);
    NotRequired(j, "rotation", rotation);
    NotRequired(j, "scale", scale);
    NotRequired(j, "translation", translation);
    NotRequired(j, "weights", weights);
    NotRequired(j, "name", name);
}

void Node::updateChild(std::vector<Node> &nodes) {
    for(auto i : children)
        setChild(nodes[i]);
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

    s << "    matrix :";
    for (const auto &b : a.matrix)
        s << " " << b;
    s << endl;

    if (a.mesh != -1)
        s << "    mesh : " << a.mesh << endl;

    s << "    rotation :";
    for (const auto &b : a.rotation)
        s << " " << b;
    s << endl;

    s << "    scale :";
    for (const auto &b : a.scale)
        s << " " << b;
    s << endl;

    s << "    translation :";
    for (const auto &b : a.translation)
        s << " " << b;
    s << endl;

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