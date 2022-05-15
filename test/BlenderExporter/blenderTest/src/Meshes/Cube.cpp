#include <blenderTest/Meshes.hpp>
#include <Blob/Materials.hpp>
namespace blenderTest::Meshes {
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
};
const Data data[24]{
{-1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.375, 0.0, 1.0, 0.76862746, 0.5058824, 1.0},
{-1.0, -1.0, -1.0, 0.0, -1.0, 0.0, 0.375, 1.0, 0.8117647, 1.0, 0.43137255, 1.0},
{-1.0, -1.0, -1.0, 0.0, 0.0, -1.0, 0.125, 0.75, 0.39607844, 0.9411765, 1.0, 1.0},
{-1.0, -1.0, 1.0, -1.0, 0.0, 0.0, 0.625, 0.0, 1.0, 0.76862746, 0.5058824, 1.0},
{-1.0, -1.0, 1.0, 0.0, -1.0, 0.0, 0.625, 1.0, 0.8117647, 1.0, 0.43137255, 1.0},
{-1.0, -1.0, 1.0, 0.0, 0.0, 1.0, 0.875, 0.75, 0.44313726, 1.0, 0.72156864, 1.0},
{-1.0, 1.0, -1.0, -1.0, 0.0, 0.0, 0.375, 0.25, 1.0, 0.76862746, 0.5058824, 1.0},
{-1.0, 1.0, -1.0, 0.0, 0.0, -1.0, 0.125, 0.5, 0.39607844, 0.9411765, 1.0, 1.0},
{-1.0, 1.0, -1.0, 0.0, 1.0, 0.0, 0.375, 0.25, 1.0, 0.49019608, 0.8980392, 1.0},
{-1.0, 1.0, 1.0, -1.0, 0.0, 0.0, 0.625, 0.25, 1.0, 0.76862746, 0.5058824, 1.0},
{-1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.875, 0.5, 0.44313726, 1.0, 0.72156864, 1.0},
{-1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.625, 0.25, 1.0, 0.49019608, 0.8980392, 1.0},
{1.0, -1.0, -1.0, 0.0, -1.0, 0.0, 0.375, 0.75, 0.8117647, 1.0, 0.43137255, 1.0},
{1.0, -1.0, -1.0, 0.0, 0.0, -1.0, 0.375, 0.75, 0.39607844, 0.9411765, 1.0, 1.0},
{1.0, -1.0, -1.0, 1.0, 0.0, 0.0, 0.375, 0.75, 0.5176471, 1.0, 0.42352942, 1.0},
{1.0, -1.0, 1.0, 0.0, -1.0, 0.0, 0.625, 0.75, 0.8117647, 1.0, 0.43137255, 1.0},
{1.0, -1.0, 1.0, 0.0, 0.0, 1.0, 0.625, 0.75, 0.44313726, 1.0, 0.72156864, 1.0},
{1.0, -1.0, 1.0, 1.0, 0.0, 0.0, 0.625, 0.75, 0.5176471, 1.0, 0.42352942, 1.0},
{1.0, 1.0, -1.0, 0.0, 0.0, -1.0, 0.375, 0.5, 0.39607844, 0.9411765, 1.0, 1.0},
{1.0, 1.0, -1.0, 0.0, 1.0, 0.0, 0.375, 0.5, 1.0, 0.49019608, 0.8980392, 1.0},
{1.0, 1.0, -1.0, 1.0, 0.0, 0.0, 0.375, 0.5, 0.5176471, 1.0, 0.42352942, 1.0},
{1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.625, 0.5, 0.44313726, 1.0, 0.72156864, 1.0},
{1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.625, 0.5, 1.0, 0.49019608, 0.8980392, 1.0},
{1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.625, 0.5, 0.5176471, 1.0, 0.42352942, 1.0}
};
const uint16_t indicesArrayColor[36]{21, 10, 5, 21, 5, 16, 12, 15, 4, 12, 4, 1, 0, 3, 9, 0, 9, 6, 7, 18, 13, 7, 13, 2, 20, 23, 17, 20, 17, 14, 8, 11, 22, 8, 22, 19};
Cube::Cube(Blob::Context &context) {
    Blob::VertexLayout vertexLayout;
    vertexLayout.begin();
    vertexLayout.add<float>(bgfx::Attrib::Position, 3);
    vertexLayout.add<float>(bgfx::Attrib::Normal, 3);
    vertexLayout.add<float>(bgfx::Attrib::TexCoord0, 2);
    vertexLayout.add<float>(bgfx::Attrib::Color0, 4);
    vertexLayout.end();
    std::unique_ptr<Blob::VertexBuffer> &CubeVertexBuffer = context.vertexBuffers["Cube"];
    if(!CubeVertexBuffer)
        CubeVertexBuffer = std::make_unique<Blob::VertexBuffer>(Blob::Buffer{data}, vertexLayout);
    std::unique_ptr<Blob::RenderOptions> &ArrayColorRo = context.renderOptions["CubeArrayColor"];
    if(!ArrayColorRo)
        ArrayColorRo = std::make_unique<Blob::RenderOptions>(Blob::Buffer{indicesArrayColor});
    ArrayColor.material = Blob::Materials::pbrSingleColor(context, Blob::Color{0.800000011920929, 0.800000011920929, 0.800000011920929, 1.0});
    ArrayColor.renderOptions = ArrayColorRo.get();
    ArrayColor.vertexBuffer = CubeVertexBuffer.get();
    addPrimitive(ArrayColor);
}
}
