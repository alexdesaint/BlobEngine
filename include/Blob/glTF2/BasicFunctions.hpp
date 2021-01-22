#pragma once

#include <Blob/Color.hpp>
#include <Blob/Core/Exception.hpp>
#include <nlohmann/json.hpp>
namespace Blob::glTF2 {
template<typename T>
static void Required(const nlohmann::json &j, const std::string &name, T &s) {
    auto o = j.find(name);
    if (o == j.end())
        throw Blob::Core::Exception("glTF : Required field \"" + name + "\" not found");
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

// template<>
// static bool NotRequired<Blob::Color>(const nlohmann::json &j, const std::string &name, Blob::Color &s) {
//    auto o = j.find(name);
//    float a[4] = {1.f};
//    if (o != j.end()) {
//        o->get_to(a);
//        s.R = a[0];
//        s.G = a[1];
//        s.B = a[2];
//        s.A = a[3];
//        return true;
//    }
//    return false;
//}
} // namespace Blob::glTF2