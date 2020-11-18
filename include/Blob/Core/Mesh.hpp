#pragma once

#include <list>

#include <Blob/Core/Primitive.hpp>


namespace Blob::Core {

class Mesh {
    friend class Window;

private:
    std::list<Primitive *> primitives;

public:

    void addPrimitive(Primitive &r);
    void addPrimitive(Primitive *r);

    void removePrimitive(Primitive &r);
    void removePrimitive(Primitive *r);
};
} // namespace Blob::Core
