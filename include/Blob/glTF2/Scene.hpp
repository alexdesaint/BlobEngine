#ifndef BLOBENGINE_SCENE_HPP
#define BLOBENGINE_SCENE_HPP

#include <vector>
#include <nlohmann/json.hpp>
#include <Blob/glTF2/Node.hpp>

namespace Blob::glTF2 {

    class Scene : public GL::Shape {
	public:

        std::vector<int> nodes;
        std::string name;

        Scene(const nlohmann::json &j, std::list<Node> &nodesList);

		friend std::ostream &operator<<(std::ostream &s, const Scene &a);
	};
}

#endif //BLOBENGINE_SCENE_HPP
