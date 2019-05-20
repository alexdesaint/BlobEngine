#include <Blob/glTF2/Node.hpp>

using namespace std;

namespace Blob::glTF2 {

    Node::Node(const nlohmann::json &j, std::list<Mesh> &meshes) {

        if (j.find("camera") != j.end())
            j.at("camera").get_to(camera);

        if (j.find("children") != j.end())
            j.at("children").get_to(children);

        if (j.find("skin") != j.end())
            j.at("skin").get_to(skin);

        if (j.find("matrix") != j.end()) {
            j.at("matrix").get_to(matrix);
            setModelMatrix(matrix);
        }

        if (j.find("mesh") != j.end()) {
            j.at("mesh").get_to(mesh);

            auto meshIt = std::next(meshes.begin(), mesh);

            for (const auto &prim : meshIt->primitives)
                addRenderable(prim);
        }

        if (j.find("rotation") != j.end()) {
            j.at("rotation").get_to(rotation);
            setRotation(rotation[3], rotation[0], rotation[1], rotation[2]);
        }

        if (j.find("scale") != j.end()) {
            j.at("scale").get_to(scale);
            setScale(scale[0], scale[1], scale[2]);
        }

        if (j.find("translation") != j.end()) {
            j.at("translation").get_to(translation);
            setPosition(translation[0], translation[1], translation[2]);
        }

        if (j.find("weights") != j.end())
            j.at("weights").get_to(weights);

        if (j.find("name") != j.end())
            j.at("name").get_to(name);
    }

    void Node::setChildren(std::list<Node> &nodes) {
        for (const auto &c : children)
            addRenderable(*std::next(nodes.begin(), c));
    }

    std::ostream &operator<<(std::ostream &s, const Node &a) {
        s << "  Node {" << endl;

        if (a.camera != -1)
            s << "    camera : " << a.camera;

        if (!a.children.empty()) {
            s << "    children : ";
            for (const auto &b : a.children)
                s << " " << b;
            s << endl;
        }

        if (a.skin != -1)
            s << "    skin : " << a.skin;

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
            s << "    name : " << a.name;

        s << "  }" << endl;
        return s;
    }
}