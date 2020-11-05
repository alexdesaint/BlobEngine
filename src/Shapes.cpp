#include <Blob/Shapes.hpp>
#include <iostream>

using namespace Blob::GL;

namespace Blob::Shapes {

/********************* Shapes *********************/

    struct Data {
        float POSITION[3];
        float NORMAL[3];
        float TANGENT[3];
        float TEXCOORD_0[3];
    };

//#define SIZE 1.f
#define SIZE 0.5f

    const Data data[] = {
            // CUBE
            {{SIZE, -SIZE, SIZE}, {0, -0, 1}, {0, 1, 0}, {0.25, 0.25}},
            {{SIZE, SIZE, SIZE}, {0, -0, 1}, {0, 1, 0}, {0.5, 0.25}},
            {{-SIZE, SIZE, SIZE}, {0, -0, 1}, {0, 1, 0}, {0.5, 0}},
            {{-SIZE, -SIZE, SIZE}, {0, -0, 1}, {0, 1, 0}, {0.25, 0}},
            {{-SIZE, -SIZE, SIZE}, {0, -1, 0}, {1, 0, 0}, {0, 0.25}},
            {{-SIZE, -SIZE, -SIZE}, {0, -1, 0}, {1, 0, 0}, {0, 0.5}},
            {{SIZE, -SIZE, -SIZE}, {0, -1, 0}, {1, 0, 0}, {0.25, 0.5}},
            {{SIZE, -SIZE, SIZE}, {0, -1, 0}, {1, 0, 0}, {0.25, 0.25}},
            {{-SIZE, SIZE, SIZE}, {-1, -0, 0}, {0, -1, 0}, {0.75, 0.25}},
            {{-SIZE, SIZE, -SIZE}, {-1, -0, 0}, {0, -1, 0}, {0.75, 0.5}},
            {{-SIZE, -SIZE, -SIZE}, {-1, -0, 0}, {0, -1, 0}, {1, 0.5}},
            {{-SIZE, -SIZE, SIZE}, {-1, -0, 0}, {0, -1, 0}, {1, 0.25}},
            {{-SIZE, -SIZE, -SIZE}, {0, 0, -1}, {0, 1, 0}, {0.25, 0.75}},
            {{-SIZE, SIZE, -SIZE}, {0, 0, -1}, {0, 1, 0}, {0.5, 0.75}},
            {{SIZE, SIZE, -SIZE}, {0, 0, -1}, {0, 1, 0}, {0.5, 0.5}},
            {{SIZE, -SIZE, -SIZE}, {0, 0, -1}, {0, 1, 0}, {0.25, 0.5}},
            {{SIZE, -SIZE, SIZE}, {1, -0, 0}, {0, 1, 0}, {0.25, 0.25}},
            {{SIZE, -SIZE, -SIZE}, {1, -0, 0}, {0, 1, 0}, {0.25, 0.5}},
            {{SIZE, SIZE, -SIZE}, {1, -0, 0}, {0, 1, 0}, {0.5, 0.5}},
            {{SIZE, SIZE, SIZE}, {1, -0, 0}, {0, 1, 0}, {0.5, 0.25}},
            {{SIZE, SIZE, SIZE}, {0, 1, 0}, {-1, 0, 0}, {0.5, 0.25}},
            {{SIZE, SIZE, -SIZE}, {0, 1, 0}, {-1, 0, 0}, {0.5, 0.5}},
            {{-SIZE, SIZE, -SIZE}, {0, 1, 0}, {-1, 0, 0}, {0.75, 0.5}},
            {{-SIZE, SIZE, SIZE}, {0, 1, 0}, {-1, 0, 0}, {0.75, 0.25}},

            // PLANE
            {{SIZE, -SIZE, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
            {{SIZE, SIZE, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
            {{-SIZE, SIZE, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
            {{-SIZE, -SIZE, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},

            // OCTAGONAL PRISM
            {{0.7f, 0.7f, 1.0f}, {0.4f, 0.9f, 0.0f}, {0.9f, -0.4f, 0.0f}, {0.9f, 0.0f}},
            {{0.7f, 0.7f, -1.0f}, {0.4f, 0.9f, 0.0f}, {0.9f, -0.4f, 0.0f}, {0.9f, 0.5f}},
            {{0.0f, 1.0f, -1.0f}, {0.4f, 0.9f, 0.0f}, {0.9f, -0.4f, 0.0f}, {1.0f, 0.5f}},
            {{0.0f, 1.0f, 1.0f}, {0.4f, 0.9f, 0.0f}, {0.9f, -0.4f, 0.0f}, {1.0f, 0.0f}},
            {{1.0f, -0.0f, 1.0f}, {0.9f, 0.4f, 0.0f}, {0.4f, -0.9f, 0.0f}, {0.8f, 0.0f}},
            {{1.0f, -0.0f, -1.0f}, {0.9f, 0.4f, 0.0f}, {0.4f, -0.9f, 0.0f}, {0.8f, 0.5f}},
            {{0.7f, 0.7f, -1.0f}, {0.9f, 0.4f, 0.0f}, {0.4f, -0.9f, 0.0f}, {0.9f, 0.5f}},
            {{0.7f, 0.7f, 1.0f}, {0.9f, 0.4f, 0.0f}, {0.4f, -0.9f, 0.0f}, {0.9f, 0.0f}},
            {{0.7f, -0.7f, 1.0f}, {0.9f, -0.4f, 0.0f}, {-0.4f, -0.9f, 0.0f}, {0.6f, 0.0f}},
            {{0.7f, -0.7f, -1.0f}, {0.9f, -0.4f, 0.0f}, {-0.4f, -0.9f, 0.0f}, {0.6f, 0.5f}},
            {{1.0f, -0.0f, -1.0f}, {0.9f, -0.4f, 0.0f}, {-0.4f, -0.9f, 0.0f}, {0.8f, 0.5f}},
            {{1.0f, -0.0f, 1.0f}, {0.9f, -0.4f, 0.0f}, {-0.4f, -0.9f, 0.0f}, {0.8f, 0.0f}},
            {{-0.0f, -1.0f, 1.0f}, {0.4f, -0.9f, 0.0f}, {-0.9f, -0.4f, 0.0f}, {0.5f, 0.0f}},
            {{-0.0f, -1.0f, -1.0f}, {0.4f, -0.9f, 0.0f}, {-0.9f, -0.4f, 0.0f}, {0.5f, 0.5f}},
            {{0.7f, -0.7f, -1.0f}, {0.4f, -0.9f, 0.0f}, {-0.9f, -0.4f, 0.0f}, {0.6f, 0.5f}},
            {{0.7f, -0.7f, 1.0f}, {0.4f, -0.9f, 0.0f}, {-0.9f, -0.4f, 0.0f}, {0.6f, 0.0f}},
            {{-0.7f, -0.7f, 1.0f}, {-0.4f, -0.9f, 0.0f}, {-0.9f, 0.4f, 0.0f}, {0.4f, 0.0f}},
            {{-0.7f, -0.7f, -1.0f}, {-0.4f, -0.9f, 0.0f}, {-0.9f, 0.4f, 0.0f}, {0.4f, 0.5f}},
            {{-0.0f, -1.0f, -1.0f}, {-0.4f, -0.9f, 0.0f}, {-0.9f, 0.4f, 0.0f}, {0.5f, 0.5f}},
            {{-0.0f, -1.0f, 1.0f}, {-0.4f, -0.9f, 0.0f}, {-0.9f, 0.4f, 0.0f}, {0.5f, 0.0f}},
            {{-1.0f, 0.0f, 1.0f}, {-0.9f, -0.4f, 0.0f}, {-0.4f, 0.9f, 0.0f}, {0.2f, 0.0f}},
            {{-1.0f, 0.0f, -1.0f}, {-0.9f, -0.4f, 0.0f}, {-0.4f, 0.9f, 0.0f}, {0.2f, 0.5f}},
            {{-0.7f, -0.7f, -1.0f}, {-0.9f, -0.4f, 0.0f}, {-0.4f, 0.9f, 0.0f}, {0.4f, 0.5f}},
            {{-0.7f, -0.7f, 1.0f}, {-0.9f, -0.4f, 0.0f}, {-0.4f, 0.9f, 0.0f}, {0.4f, 0.0f}},
            {{0.7f, 0.7f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.4f, 0.6f}},
            {{0.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.2f, 0.5f}},
            {{-0.7f, 0.7f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.1f, 0.6f}},
            {{1.0f, -0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.5f, 0.8f}},
            {{-1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.8f}},
            {{-0.7f, -0.7f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.1f, 0.9f}},
            {{0.7f, -0.7f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.4f, 0.9f}},
            {{-0.0f, -1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.2f, 1.0f}},
            {{-0.7f, 0.7f, 1.0f}, {-0.9f, 0.4f, 0.0f}, {0.4f, 0.9f, -0.0f}, {0.1f, 0.0f}},
            {{-0.7f, 0.7f, -1.0f}, {-0.9f, 0.4f, 0.0f}, {0.4f, 0.9f, -0.0f}, {0.1f, 0.5f}},
            {{-1.0f, 0.0f, -1.0f}, {-0.9f, 0.4f, 0.0f}, {0.4f, 0.9f, -0.0f}, {0.2f, 0.5f}},
            {{-1.0f, 0.0f, 1.0f}, {-0.9f, 0.4f, 0.0f}, {0.4f, 0.9f, -0.0f}, {0.2f, 0.0f}},
            {{0.0f, 1.0f, 1.0f}, {-0.4f, 0.9f, 0.0f}, {0.9f, 0.4f, -0.0f}, {0.0f, 0.0f}},
            {{0.0f, 1.0f, -1.0f}, {-0.4f, 0.9f, 0.0f}, {0.9f, 0.4f, -0.0f}, {0.0f, 0.5f}},
            {{-0.7f, 0.7f, -1.0f}, {-0.4f, 0.9f, 0.0f}, {0.9f, 0.4f, -0.0f}, {0.1f, 0.5f}},
            {{-0.7f, 0.7f, 1.0f}, {-0.4f, 0.9f, 0.0f}, {0.9f, 0.4f, -0.0f}, {0.1f, 0.0f}},
            {{-0.7f, 0.7f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, -0.0f, 0.0f}, {0.6f, 0.6f}},
            {{0.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, -0.0f, 0.0f}, {0.8f, 0.5f}},
            {{0.7f, 0.7f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, -0.0f, 0.0f}, {0.9f, 0.6f}},
            {{1.0f, -0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, -0.0f, 0.0f}, {1.0f, 0.8f}},
            {{-1.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, -0.0f, 0.0f}, {0.5f, 0.8f}},
            {{-0.7f, -0.7f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, -0.0f, 0.0f}, {0.6f, 0.9f}},
            {{0.7f, -0.7f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, -0.0f, 0.0f}, {0.9f, 0.9f}},
            {{-0.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, -0.0f, 0.0f}, {0.8f, 1.0f}},
    };

    uint16_t cubeIndices[] = {0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11,
                              12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23};

    uint16_t planeIndices[] = {0, 1, 2, 0, 2, 3};

    uint16_t octagonalPrismIndices[] = {0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15,
                                        16, 17, 18, 16,
                                        18, 19, 20, 21, 22, 20, 22, 23, 24, 25, 26, 27, 24, 26, 27, 26, 28, 27, 28, 29,
                                        30, 27, 29, 30, 29, 31, 32, 33,
                                        34, 32, 34, 35, 36, 37, 38, 36, 38, 39, 40, 41, 42, 40, 42, 43, 44, 40, 43, 45,
                                        44, 43, 45, 43, 46, 47, 45, 46};

    VertexBufferObject *vbo;
    VertexArrayObject *vaoCube;
    VertexArrayObject *vaoPlane;
    VertexArrayObject *vaoOctagonalPrism;

    void init() {
        Material::DefaultMaterial::init();
        Material::SingleColorMaterial::init();
        Material::SingleTextureMaterial::init();
        vbo = new VertexBufferObject((uint8_t *) data, sizeof(data));
        vaoCube = new VertexArrayObject();

        vaoCube->setBuffer(*vbo, sizeof(Data));
        vaoCube->setArray<float>(3, ShaderProgram::AttributeLocation::POSITION, (uint32_t) offsetof(Data, POSITION));
        vaoCube->setArray<float>(3, ShaderProgram::AttributeLocation::NORMAL, (uint32_t) offsetof(Data, NORMAL));
        vaoCube->setArray<float>(3, ShaderProgram::AttributeLocation::TANGENT, (uint32_t) offsetof(Data, TANGENT));
        vaoCube->setArray<float>(2, ShaderProgram::AttributeLocation::TEXCOORD_0, (uint32_t) offsetof(Data, TEXCOORD_0));

        vaoPlane = new VertexArrayObject();
        vaoPlane->setBuffer(*vbo, sizeof(Data), 4 * 6 * sizeof(Data));
        vaoPlane->setArray<float>(3, ShaderProgram::AttributeLocation::POSITION, (uint32_t) offsetof(Data, POSITION));
        vaoPlane->setArray<float>(3, ShaderProgram::AttributeLocation::NORMAL, (uint32_t) offsetof(Data, NORMAL));
        vaoPlane->setArray<float>(3, ShaderProgram::AttributeLocation::TANGENT, (uint32_t) offsetof(Data, TANGENT));
        vaoPlane->setArray<float>(2, ShaderProgram::AttributeLocation::TEXCOORD_0, (uint32_t) offsetof(Data, TEXCOORD_0));

        vaoOctagonalPrism = new VertexArrayObject();
        vaoOctagonalPrism->setBuffer(*vbo, sizeof(Data), (4 * 6 + 4) * sizeof(Data));
        vaoOctagonalPrism->setArray<float>(3, ShaderProgram::AttributeLocation::POSITION, (uint32_t) offsetof(Data, POSITION));
        vaoOctagonalPrism->setArray<float>(3, ShaderProgram::AttributeLocation::NORMAL, (uint32_t) offsetof(Data, NORMAL));
        vaoOctagonalPrism->setArray<float>(3, ShaderProgram::AttributeLocation::TANGENT, (uint32_t) offsetof(Data, TANGENT));
        vaoOctagonalPrism->setArray<float>(2, ShaderProgram::AttributeLocation::TEXCOORD_0, (uint32_t) offsetof(Data, TEXCOORD_0));
    }

    void destroy() {
        Material::DefaultMaterial::destroy();
        Material::SingleColorMaterial::destroy();
        Material::SingleTextureMaterial::destroy();

        delete vbo;
        delete vaoCube;
        delete vaoPlane;
        delete vaoOctagonalPrism;
    }

    Cube::Cube(const Material::Material &material) : Mesh(*vaoCube, material) {
        setIndices(cubeIndices, sizeof(cubeIndices) / sizeof(*cubeIndices));
    }

    Plane::Plane(const Material::Material &material) : Mesh(*vaoPlane, material) {
        setIndices(planeIndices, sizeof(planeIndices) / sizeof(*planeIndices));
    }

    OctagonalPrism::OctagonalPrism(const Material::Material &material) : Mesh(*vaoOctagonalPrism, material) {
        setIndices(octagonalPrismIndices, sizeof(octagonalPrismIndices) / sizeof(*octagonalPrismIndices));
    }
} // namespace Blob::Shapes