#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Scene.hpp>

using namespace std;

namespace Blob::glTF2 {

Scene::Scene(const nlohmann::json &j, const std::vector<Node> &nodesVector) {
    NotRequired(j, "nodes", nodes);
    NotRequired(j, "name", name);

    for (auto i : nodes)
        addShape(nodesVector[i]);
}

std::ostream &operator<<(std::ostream &s, const Scene &a) {
    s << "  Scene {" << endl;

    s << "    nodes :";
    for (const auto &node : a.nodes)
        s << " " << node;
    s << endl << "  }" << endl;
    return s;
}
} // namespace Blob::glTF2
