#pragma once

#include <Blob/Core/Asset.hpp>
#include <Blob/Core/AttributeLocation.hpp>
#include <Blob/Core/Buffer.hpp>
#include <Blob/Core/Exception.hpp>
#include <Blob/Core/Mesh.hpp>
#include <Blob/Core/Primitive.hpp>
#include <Blob/Core/Shape.hpp>
#include <Blob/Materials.hpp>

#include <iostream>

namespace Blob {
class Shapes : public Asset<Shapes> {
private:
    static const std::array<const uint8_t, 2880> data;
    struct Data {
        Blob::Vec2<> position;
        Blob::Vec2<> texturePosition;
    };
    inline static const std::array<Data, 6> data2D{
        Data{{-0.5, -0.5}, {0, 1}},
        Data{{0.5, -0.5}, {1, 1}},
        Data{{0.5, 0.5}, {1, 0}},
        Data{{-0.5, -0.5}, {0, 1}},
        Data{{-0.5, 0.5}, {0, 0}},
        Data{{0.5, 0.5}, {1, 0}},
    };

    Blob::Buffer buffer{data}, buffer2D{data2D};

public:
    Blob::Materials::PBRSingleColor defaultMaterial;

private:
    struct CubeAttributes {
        static const std::array<const uint8_t, 72> indicesArray0;
        Blob::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit CubeAttributes(const Blob::Buffer &buffer) :
            renderOptions0(indicesArray0.data(), 36, 5123) {
            attribute0.setBuffer(buffer, 48, 0);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(4, 2, 5126, 24, 0);
            attribute0.setArray(2, 3, 5126, 40, 0);
        }
    } cubeAttributes{buffer};

    struct PlaneAttributes {
        static const std::array<const uint8_t, 12> indicesArray0;
        Blob::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit PlaneAttributes(const Blob::Buffer &buffer) :
            renderOptions0(indicesArray0.data(), 6, 5123) {
            attribute0.setBuffer(buffer, 48, 1152);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(4, 2, 5126, 24, 0);
            attribute0.setArray(2, 3, 5126, 40, 0);
        }
    } planeAttributes{buffer};

    struct OctagonalPrismAttributes {
        static const std::array<const uint8_t, 168> indicesArray0;
        Blob::RenderOptions renderOptions0;
        Blob::GL::VertexArrayObject attribute0;

        explicit OctagonalPrismAttributes(const Blob::Buffer &buffer) :
            renderOptions0(indicesArray0.data(), 84, 5123) {
            attribute0.setBuffer(buffer, 32, 1344);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(2, 3, 5126, 24, 0);
        }
    } octagonalPrismAttributes{buffer};

    struct Plane2DAttributes {
        Blob::RenderOptions renderOptions;
        Blob::GL::VertexArrayObject attribute;

        explicit Plane2DAttributes(const Blob::Buffer &buffer) {
            renderOptions.setArray(6);
            attribute.setBuffer(buffer, sizeof(Data));
            attribute.setArray<float>(2, AttributeLocation::POSITION, 0);
            attribute.setArray<float>(2, AttributeLocation::TEXCOORD_0, 8);
        }

    } plane2DAttributes{buffer2D};

public:
    struct Cube : public Shape {
        std::shared_ptr<Shapes> shapesData;
        Blob::Primitive primitive0;
        Blob::Mesh mesh;
        explicit Cube() :
            shapesData(getInstance()),
            primitive0(&shapesData->cubeAttributes.attribute0,
                       &shapesData->defaultMaterial,
                       &shapesData->cubeAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
        explicit Cube(Blob::Material &material) :
            shapesData(getInstance()),
            primitive0(&shapesData->cubeAttributes.attribute0,
                       &material,
                       &shapesData->cubeAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
    };

    struct Plane : public Shape {
        std::shared_ptr<Shapes> shapesData;
        Blob::Primitive primitive0;
        Blob::Mesh mesh;
        explicit Plane() :
            shapesData(getInstance()),
            primitive0(&shapesData->planeAttributes.attribute0,
                       &shapesData->defaultMaterial,
                       &shapesData->planeAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
        explicit Plane(Blob::Material &material) :
            shapesData(getInstance()),
            primitive0(&shapesData->planeAttributes.attribute0,
                       &material,
                       &shapesData->planeAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
    };

    struct OctagonalPrism : public Shape {
        std::shared_ptr<Shapes> shapesData;
        Blob::Primitive primitive0;
        Blob::Mesh mesh;
        explicit OctagonalPrism() :
            shapesData(getInstance()),
            primitive0(&shapesData->octagonalPrismAttributes.attribute0,
                       &shapesData->defaultMaterial,
                       &shapesData->octagonalPrismAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
        explicit OctagonalPrism(Blob::Material &material) :
            shapesData(getInstance()),
            primitive0(&shapesData->octagonalPrismAttributes.attribute0,
                       &material,
                       &shapesData->octagonalPrismAttributes.renderOptions0) {
            mesh.addPrimitive(primitive0);
            setMesh(mesh);
        }
    };

    struct Plane2D : public Shape2D {
        std::shared_ptr<Shapes> shapesData;
        Blob::Primitive2D primitive0;
        Blob::Mesh2D mesh;
        template<class... Args>
        explicit Plane2D(const Blob::Material2D &material) :
            shapesData(getInstance()),
            Shape2D(mesh),
            primitive0(&shapesData->plane2DAttributes.attribute,
                       &material,
                       &shapesData->plane2DAttributes.renderOptions),
            mesh(primitive0) {}
        template<class Transform>
        explicit Plane2D(const Material2D &material,
                         const Transform &transform) :
            shapesData(getInstance()),
            Shape2D(mesh, transform),
            primitive0(&shapesData->plane2DAttributes.attribute,
                       &material,
                       &shapesData->plane2DAttributes.renderOptions),
            mesh(primitive0) {}
    };
};
} // namespace Blob
