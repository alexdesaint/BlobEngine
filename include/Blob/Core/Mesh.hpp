#pragma once

#include <list>

#include <Blob/Core/Primitive.hpp>


namespace Blob::Core {

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

    void addTransparentPrimitive(const Primitive &r);
    void addTransparentPrimitive(const Primitive *r);

    void removeTransparentPrimitive(const Primitive &r);
    void removeTransparentPrimitive(const Primitive *r);
};
} // namespace Blob::Core
