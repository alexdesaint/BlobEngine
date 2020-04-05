#pragma once

#include <Blob/Exception.hpp>
#include <nlohmann/json.hpp>
namespace Blob::glTF2 {
template<typename T>
static void Required(const nlohmann::json &j, const std::string &name, T &s) {
    auto o = j.find(name);
    if (o == j.end())
        throw Blob::Exception("glTF : Required field \"" + name + "\" not found");
    else
        o->get_to(s);
}

template<typename T>
static bool NotRequired(const nlohmann::json &j, const std::string &name, T &s) {
    auto o = j.find(name);
    if (o != j.end()) {
        o->get_to(s);
        return true;
    }
    return false;
}
} // namespace Blob::glTF2