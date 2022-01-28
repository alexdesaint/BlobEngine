#include <Blob/Mesh.hpp>
#include <deque>
#include <iostream>
#include <ostream>
#include <unordered_set>
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
public:
    std::unordered_map<size_t, std::pair<std::vector<Mat4>, std::deque<size_t>>>
        drawCallList;
    std::unordered_map<size_t, std::unordered_set<size_t>> typeIdperId;

    void add(size_t type_id, size_t id, const Mat4 &pos) {
        drawCallList[type_id].first.emplace_back(pos);
        drawCallList[type_id].second.emplace_back(id);
        typeIdperId[id].emplace(type_id);
    }

    void remove(size_t id) {
        for (const auto &typeId : typeIdperId[id]) {
            auto it = drawCallList.find(typeId);
            if (it == drawCallList.end())
                return;

            auto &[positions, ids] = it->second;

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
        typeIdperId.erase(id);
    }

    friend std::ostream &
    operator<<(std::ostream &os,
               const DynamicDrawCallList &dynamicDrawCallList) {
        for (const auto &[typeId, posIdsPair] :
             dynamicDrawCallList.drawCallList) {
            os << typeId << " {" << std::endl;
            auto &[positions, ids] = posIdsPair;
            if (ids.size() != positions.size())
                std::cout << "Error, ids and pos are of different size"
                          << std::endl;
            for (size_t i = 0; i < ids.size(); i++)
                std::cout << ids[i] << " " << positions[i];
            os << "}" << std::endl;
        }
        return os;
    }
};
} // namespace Blob
