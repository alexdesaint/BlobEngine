#include <Blob/glTF2/Scene.hpp>

using namespace std;

namespace Blob::glTF2 {

    Scene::Scene(const nlohmann::json &j, std::list<Node> &nodesList) {
        if (j.find("nodes") != j.end())
            j.at("nodes").get_to(nodes);

        for (const auto &n : nodes)
            addRenderable(*std::next(nodesList.begin(), n));

        if (j.find("name") != j.end())
            j.at("name").get_to(name);
	}

	std::ostream &operator<<(std::ostream &s, const Scene &a) {
        s << "  Scene {" << endl;

        s << "    nodes :";
        for (const auto &node : a.nodes)
            s << " " << node;
        s << endl << "  }" << endl;
		return s;
	}
}
