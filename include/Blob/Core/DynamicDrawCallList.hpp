#include <Blob/Core/Primitive.hpp>
#include <deque>
#include <ostream>
#include <vector>

namespace Blob {
/* DynamicDrawCallList manage vectors of position matrice.
 * It is usefull for dynamic instenced rendering (if you modify the instenced
 * buffer regularly). It require to use add and remove with the same object.
 * Insertion is fast but removing elements is slow. It is still better that
 * generating the drawCallList at every frame.
 */
class DynamicDrawCallList {
private:
    std::unordered_map<const Primitive *,
                       std::pair<std::vector<Mat4>, std::deque<const void *>>>
        drawCallList;

public:
    void add(const void *id, const Primitive *primitive, const Mat4 &pos) {
        drawCallList[primitive].first.emplace_back(pos);
        drawCallList[primitive].second.emplace_back(id);
    }

    void remove(const void *id, const Primitive *primitive) {
        auto it = drawCallList.find(primitive);
        if (it == drawCallList.end())
            return;

        auto &ids = it->second.second;
        auto &positions = it->second.first;

        for (size_t i = 0; i < ids.size(); i++) {
            if (ids[i] != id)
                continue;

            positions[i] = positions.back();
            positions.pop_back();
            ids[i] = ids.back();
            ids.pop_back();
        }

        if (ids.empty())
            drawCallList.erase(it);
    }

    friend std::ostream &
    operator<<(std::ostream &os,
               const DynamicDrawCallList &dynamicDrawCallList) {
        for (const auto &[prim, posIdsPair] :
             dynamicDrawCallList.drawCallList) {
            os << prim << " {" << std::endl;
            auto &ids = posIdsPair.second;
            auto &pos = posIdsPair.first;
            if (ids.size() != pos.size())
                std::cout << "Error, ids and pos are of different size"
                          << std::endl;
            for (size_t i = 0; i < ids.size(); i++)
                std::cout << ids[i] << " " << pos[i];
            os << "}" << std::endl;
        }
        return os;
    }
};
} // namespace Blob
