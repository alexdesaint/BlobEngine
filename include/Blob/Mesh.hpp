#pragma once

#include <list>
#include <unordered_map>

#include <Blob/Primitive.hpp>

namespace Blob {

class Mesh {
    friend class Window;

private:
    std::list<const Primitive *> primitives;
    std::list<const Primitive *> transparentPrimitives;

public:
    Mesh() = default;
    Mesh(const Mesh &) = delete;
    Mesh(Mesh &&) = delete;
    explicit Mesh(const Primitive &r);

    void addPrimitive(const Primitive &r);
    void addPrimitive(const Primitive *r);

    void removePrimitive(const Primitive &r);
    void removePrimitive(const Primitive *r);
    void removeAllPrimitive();

    void addTransparentPrimitive(const Primitive &r);
    void addTransparentPrimitive(const Primitive *r);

    void removeTransparentPrimitive(const Primitive &r);
    void removeTransparentPrimitive(const Primitive *r);

    friend std::ostream &operator<<(std::ostream &s, const Mesh &a);
};

} // namespace Blob
