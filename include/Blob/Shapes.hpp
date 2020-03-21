#pragma once

#include <Blob/Exception.hpp>
#include <Blob/Renderable.hpp>
#include <Blob/Shapes.hpp>

#include <iostream>

namespace Blob::Shapes {

void init();

void destroy();

struct Light{
    int positionPos = -1;
    glm::vec3 position = glm::vec3(1.2f, 1.0f, 2.0f);

    int ambientPos = -1;
    Color ambient = Color(0.2f, 0.2f, 0.2f);
    int diffusePos = -1;
    Color diffuse = Color(0.5f, 0.5f, 0.5f);
    int specularPos = -1;
    Color specular = Color::White;
};

/// A Material to draw in a single color
class SingleColorMaterial : public Material {
private:
    static int model, view, projection;//, lightDirPos, lightColorPos, colorPos;

    // texture
    static int ambientPos;
    static int diffusePos;
    static int specularPos;
    static int shininessPos;

    static int viewPos;

    void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const ModelTransform &mt) const final;

public:
    Color ambient = Color(1.0f, 0.5f, 0.31f);
    Color diffuse = Color(1.0f, 0.5f, 0.31f);
    Color specular = Color(0.5f, 0.5f, 0.5f);
    float shininess = 32;

    static Light light;

    //Color color = Color::Aqua;
    //static Color lightColor;
    //static float lightDir[3];
    SingleColorMaterial();
    static void init();
};

class Cube : public Renderable {
public:
    SingleColorMaterial singleColorMaterial;
    explicit Cube();
};

class Plane : public Renderable {
public:
    SingleColorMaterial singleColorMaterial;
    explicit Plane();
};

class OctagonalPrism : public Renderable {
public:
    SingleColorMaterial singleColorMaterial;
    explicit OctagonalPrism();
};
} // namespace Blob::Shapes
