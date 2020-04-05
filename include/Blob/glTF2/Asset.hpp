#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {

class Asset {
private:
    std::string version;

public:
    friend std::ostream &operator<<(std::ostream &s, const Asset &a);
    friend void from_json(const nlohmann::json &j, Asset &a);
};
} // namespace Blob::glTF2
