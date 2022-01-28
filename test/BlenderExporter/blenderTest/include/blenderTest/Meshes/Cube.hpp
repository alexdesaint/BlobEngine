#pragma once
#include <Blob/AttributeLocation.hpp>
#include <Blob/Buffer.hpp>
#include <Blob/Mesh.hpp>
#include <blenderTest/Materials/Material.hpp>
namespace blenderTest::Meshes {
struct Cube : public Blob::Mesh {
    struct Attributes : public Blob::Asset<Attributes> {
        struct Data {
            float x;
            float y;
            float z;
            float nx;
            float ny;
            float nz;
            float uv0x;
            float uv0y;
            float color0r;
            float colog0r;
            float colob0r;
            float coloa0r;
            static Blob::VertexLayout getVertexLayout();
        };
        static const Data data[24];
        static const uint16_t indices0[36];
        Blob::RenderOptions renderOptions0{Blob::Buffer{indices0}};
        Blob::VertexBuffer attribute{Blob::Buffer{data},
                                     Data::getVertexLayout()};
    };
    Attributes::Instance attributes{Attributes::getInstance()};
    Materials::Material Material;
    Blob::Primitive primitives[1];
    Cube();
};
} // namespace blenderTest::Meshes
