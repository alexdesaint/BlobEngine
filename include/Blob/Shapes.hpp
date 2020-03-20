#pragma once

#include <Blob/Exception.hpp>
#include <Blob/Renderable.hpp>
#include <Blob/Shapes.hpp>

#include <iostream>

namespace Blob::Shapes {

void init();

void destroy();

/// A Material to draw in a single color
class SingleColorMaterial : public Material {
private:
    static int model, view, projection, lightDirPos, lightColorPos, colorPos;

    void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const ModelTransform &mt) const final;

public:
    Color color = Color::Aqua;
    static Color lightColor;
    static float lightDir[3];
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
