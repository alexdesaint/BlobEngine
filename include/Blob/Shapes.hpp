#pragma once

#include <Blob/Core/Buffer.hpp>
#include <Blob/Core/Exception.hpp>
#include <Blob/Core/Mesh.hpp>
#include <Blob/Core/Primitive.hpp>
#include <Blob/Core/Shape.hpp>
#include <Blob/Materials.hpp>

#include <iostream>

namespace Blob {
class Shapes {
private:
    static Shapes *instance;

    static const std::array<const uint8_t, 2880> data;

    Blob::Core::Buffer buffer;

public:
    struct Materials {
        Blob::Materials::PBRSingleColor defaultM;
    } materials;

private:
    struct CubeAttributes {
        static const std::array<const uint8_t, 72> indicesArray0;
        Blob::Core::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit CubeAttributes(const Blob::Core::Buffer &buffer) {
            attribute0.setBuffer(buffer, 48, 0);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(4, 2, 5126, 24, 0);
            attribute0.setArray(2, 3, 5126, 40, 0);
            renderOptions0.setIndices(indicesArray0.data(), 36, 5123);
        }
    } cubeAttributes{buffer};

    struct PlaneAttributes {
        static const std::array<const uint8_t, 12> indicesArray0;
        Blob::Core::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit PlaneAttributes(const Blob::Core::Buffer &buffer) {
            attribute0.setBuffer(buffer, 48, 1152);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(4, 2, 5126, 24, 0);
            attribute0.setArray(2, 3, 5126, 40, 0);
            renderOptions0.setIndices(indicesArray0.data(), 6, 5123);
        }
    } planeAttributes{buffer};

    struct OctagonalPrismAttributes {
        static const std::array<const uint8_t, 168> indicesArray0;
        Blob::Core::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit OctagonalPrismAttributes(const Blob::Core::Buffer &buffer) {
            renderOptions0.setIndices(indicesArray0.data(), 84, 5123);
            attribute0.setBuffer(buffer, 32, 1344);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(2, 3, 5126, 24, 0);
        }
    } octagonalPrismAttributes{buffer};

public:
    struct Cube : public Core::Mesh {
        Blob::Core::Primitive primitive0;
        explicit Cube(const Blob::Core::Material &material = instance->materials.defaultM)
            : primitive0(instance->cubeAttributes.attribute0, material, instance->cubeAttributes.renderOptions0) {
            addPrimitive(primitive0);
        }
    };

    struct Plane : public Core::Mesh {
        Blob::Core::Primitive primitive0;
        explicit Plane(const Blob::Core::Material &material = instance->materials.defaultM)
            : primitive0(instance->planeAttributes.attribute0, material, instance->planeAttributes.renderOptions0) {
            addPrimitive(primitive0);
        }
    };

    struct OctagonalPrism : public Core::Mesh {
        Blob::Core::Primitive primitive0;
        explicit OctagonalPrism(const Blob::Core::Material &material = instance->materials.defaultM)
            : primitive0(instance->octagonalPrismAttributes.attribute0, material, instance->octagonalPrismAttributes.renderOptions0) {
            addPrimitive(primitive0);
        }
    };

    Shapes() {
        if (instance != nullptr)
            throw Blob::Core::Exception("Shapes already loaded");
        instance = this;
        buffer.setData(data.data(), data.size());
    }

    ~Shapes() { instance = nullptr; }
};
} // namespace Blob
