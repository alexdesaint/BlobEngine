#pragma once

#include <Blob/Core/Asset.hpp>
#include <Blob/Core/Shader.hpp>
#include <memory>

namespace Blob::Shaders {

/// Simples shaders

class SingleColor2D : public Core::Shader, public Core::Asset<SingleColor2D> {
private:
    friend Core::Asset<SingleColor2D>;
    SingleColor2D();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;
};

class SingleColorSingleTexture2D : public Core::Shader, public Core::Asset<SingleColorSingleTexture2D> {
private:
    friend Core::Asset<SingleColorSingleTexture2D>;
    SingleColorSingleTexture2D();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;
};

class ColorArraySingleTexture2D : public Core::Shader, public Core::Asset<ColorArraySingleTexture2D> {
    friend Core::Asset<ColorArraySingleTexture2D>;

private:
    ColorArraySingleTexture2D();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;
};

class SingleColor : public Core::Shader, public Core::Asset<SingleColor> {
private:
    friend Core::Asset<SingleColor>;
    SingleColor();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;
};

class SingleColorTransparent : public Core::Shader, public Core::Asset<SingleColorTransparent> {
private:
    friend Core::Asset<SingleColorTransparent>;
    SingleColorTransparent();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;
};

class SingleTexture : public Core::Shader, public Core::Asset<SingleTexture> {
private:
    friend Core::Asset<SingleTexture>;
    SingleTexture();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int textureScale = 3;
};

/// Utils

class PerFaceNormal : public Core::Shader, public Core::Asset<PerFaceNormal> {
private:
    friend Core::Asset<PerFaceNormal>;
    PerFaceNormal();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;
    static const int length = 4;
};

class Deferred : public Core::Shader {
private:
    friend Core::Asset<SingleColor2D>;
    Deferred();
};

/// PBR

class PBRSingleColor : public Core::Shader, public Core::Asset<PBRSingleColor> {
private:
    friend Core::Asset<PBRSingleColor>;
    PBRSingleColor();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;
    static const int metallic = 4;
    static const int roughness = 5;
    static const int ao = 6;

    static const int cameraPosition = 7;
    static const int lightPosition = 8;
    static const int lightColor = 9;
    static const int lightRadius = 10;
    static const int lightPower = 11;
};

class PBRSingleTexture : public Core::Shader, public Core::Asset<PBRSingleTexture> {
private:
    friend Core::Asset<PBRSingleTexture>;
    PBRSingleTexture();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int textureScale = 3;
    static const int metallic = 4;
    static const int roughness = 5;
    static const int ao = 6;

    static const int cameraPosition = 7;
    static const int lightPosition = 8;
    static const int lightColor = 9;
    static const int lightRadius = 10;
    static const int lightPower = 11;
};

class PBRColorArray : public Core::Shader, public Core::Asset<PBRColorArray> {
private:
    friend Core::Asset<PBRColorArray>;
    PBRColorArray();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int metallic = 4;
    static const int roughness = 5;
    static const int ao = 6;

    static const int cameraPosition = 7;
    static const int lightPosition = 8;
    static const int lightColor = 9;
    static const int lightRadius = 10;
    static const int lightPower = 11;
};

class PBRWater : public Core::Shader, public Core::Asset<PBRWater> {
private:
    friend Core::Asset<PBRWater>;
    PBRWater();

public:
    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;
    static const int metallic = 4;
    static const int roughness = 5;
    static const int ao = 6;

    static const int cameraPosition = 7;
    static const int lightPosition = 8;
    static const int lightColor = 9;
    static const int lightRadius = 10;
    static const int lightPower = 11;
    static const int timeStep = 12;
};

} // namespace Blob::Shaders