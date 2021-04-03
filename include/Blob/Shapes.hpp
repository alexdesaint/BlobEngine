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
    struct Data {
        Blob::Maths::Vec2<float> position;
        Blob::Maths::Vec2<float> texturePosition;
    };
    inline static const std::array<Data, 6> data2D{
        Data{{-0.5, -0.5}, {0, 1}},
        Data{{0.5, -0.5}, {1, 1}},
        Data{{0.5, 0.5}, {1, 0}},
        Data{{-0.5, -0.5}, {0, 1}},
        Data{{-0.5, 0.5}, {0, 0}},
        Data{{0.5, 0.5}, {1, 0}},
    };

    Blob::Core::Buffer buffer{data}, buffer2D{data2D};

public:
    struct Materials {
        Blob::Materials::PBRSingleColor defaultM;
    } materials;

private:
    struct CubeAttributes {
        static const std::array<const uint8_t, 72> indicesArray0;
        Blob::Core::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit CubeAttributes(const Blob::Core::Buffer &buffer) : renderOptions0(indicesArray0.data(), 36, 5123) {
            attribute0.setBuffer(buffer, 48, 0);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(4, 2, 5126, 24, 0);
            attribute0.setArray(2, 3, 5126, 40, 0);
        }
    } cubeAttributes{buffer};

    struct PlaneAttributes {
        static const std::array<const uint8_t, 12> indicesArray0;
        Blob::Core::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit PlaneAttributes(const Blob::Core::Buffer &buffer) : renderOptions0(indicesArray0.data(), 6, 5123) {
            attribute0.setBuffer(buffer, 48, 1152);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(4, 2, 5126, 24, 0);
            attribute0.setArray(2, 3, 5126, 40, 0);
        }
    } planeAttributes{buffer};

    struct OctagonalPrismAttributes {
        static const std::array<const uint8_t, 168> indicesArray0;
        Blob::Core::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit OctagonalPrismAttributes(const Blob::Core::Buffer &buffer) : renderOptions0(indicesArray0.data(), 84, 5123) {
            attribute0.setBuffer(buffer, 32, 1344);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(2, 3, 5126, 24, 0);
        }
    } octagonalPrismAttributes{buffer};

    struct Plane2DAttributes {
        Blob::Core::RenderOptions renderOptions;
        Blob::GL::VertexArrayObject attribute;

        explicit Plane2DAttributes(const Blob::Core::Buffer &buffer) {
            renderOptions.setArray(6);
            attribute.setBuffer(buffer, sizeof(Data));
            attribute.setArray<float>(2, Core::Shader::AttributeLocation::POSITION, 0);
            attribute.setArray<float>(2, Core::Shader::AttributeLocation::TEXCOORD_0, 8);
        }

    } plane2DAttributes{buffer2D};

public:
    struct Cube : public Core::Shape {
        Blob::Core::Primitive primitive0;
        Blob::Core::Mesh mesh;
        explicit Cube(const Blob::Core::Material &material = instance->materials.defaultM) : primitive0(&instance->cubeAttributes.attribute0, &material, &instance->cubeAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
    };

    struct Plane : public Core::Shape {
        Blob::Core::Primitive primitive0;
        Blob::Core::Mesh mesh;
        explicit Plane(const Blob::Core::Material &material = instance->materials.defaultM) : primitive0(&instance->planeAttributes.attribute0, &material, &instance->planeAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
    };

    struct OctagonalPrism : public Core::Shape {
        Blob::Core::Primitive primitive0;
        Blob::Core::Mesh mesh;
        explicit OctagonalPrism(const Blob::Core::Material &material = instance->materials.defaultM) :
            primitive0(&instance->octagonalPrismAttributes.attribute0, &material, &instance->octagonalPrismAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
    };

    template<class Material>
    struct Plane2D : public Core::Shape2D {
        Blob::Core::Primitive2D primitive0;
        Material material;
        Blob::Core::Mesh2D mesh;
        template<class... Args>
        explicit Plane2D(const Args &...args) :
            Core::Shape2D(mesh), primitive0(&instance->plane2DAttributes.attribute, &material, &instance->plane2DAttributes.renderOptions), mesh(primitive0), material(args...) {}
        template<class Transform>
        explicit Plane2D(const Material &materialRef, const Transform &transform) :
            Core::Shape2D(mesh, transform), primitive0(&instance->plane2DAttributes.attribute, &material, &instance->plane2DAttributes.renderOptions), mesh(primitive0), material(materialRef) {}
    };

    Shapes() {
        if (instance != nullptr)
            throw Blob::Core::Exception("Shapes already loaded");
        instance = this;
    }

    ~Shapes() { instance = nullptr; }
};
} // namespace Blob
