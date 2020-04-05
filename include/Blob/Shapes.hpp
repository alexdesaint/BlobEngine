#pragma once

#include <Blob/Exception.hpp>
#include <Blob/Mesh.hpp>
#include <Blob/Shapes.hpp>

#include <iostream>

namespace Blob::Shapes {

void init();

void destroy();

struct Light{
    int positionPos = -1;
    glm::vec3 position = glm::vec3(1.2f, 1.0f, 2.0f);

    int colorPos = -1;
    Color color = Color(1, 1, 1);
};

/// A Material to draw in a single color
class SingleColorMaterial : public Material {
private:
    static int model, view, projection;

    // texture
    static int albedoPos;
    static int metallicPos;
    static int roughnessPos;
    static int aoPos;

    static int optionsPos;

    static int camPos;

    void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const final;

public:
    const struct {
        uint32_t Irradiance = 1;
        uint32_t Radiance = 2;
    } Options;

    Color albedo = Color(1.0f, 0.5f, 0.31f);
    float metallic = 0;
    float roughness = 0;
    float ao = 1;
    uint32_t options = 0xFFFFFFFF;

    /*Color ambient = Color(1.0f, 0.5f, 0.31f);
    Color diffuse = Color(1.0f, 0.5f, 0.31f);
    Color specular = Color(0.5f, 0.5f, 0.5f);
    float shininess = 512;*/

    static Light light;

    SingleColorMaterial();
    static void init();
};

class Cube : public Mesh {
public:
    explicit Cube(const SingleColorMaterial &singleColorMaterial);
};

class Plane : public Mesh {
public:
    explicit Plane(const SingleColorMaterial &singleColorMaterial);
};

class OctagonalPrism : public Mesh {
public:
    explicit OctagonalPrism(const SingleColorMaterial &singleColorMaterial);
};
} // namespace Blob::Shapes
