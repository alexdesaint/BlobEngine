#pragma once

#include <Blob/Shapes.hpp>

namespace Blob::Shaders {

/// Simples shaders

class SingleColor : public Core::Shader {
private:
public:
    static SingleColor instance;

    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;

    void build();
    void destroy();
};

class SingleColorTransparent : public Core::Shader {
private:
public:
    static SingleColorTransparent instance;

    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;

    void build();
    void destroy();
};

class SingleTexture : public Core::Shader {
private:
public:
    static SingleTexture instance;

    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int textureScale = 3;

    void build();
    void destroy();
};

/// Utils

class PerFaceNormal : public Core::Shader {
public:
    static PerFaceNormal instance;

    static const int model = 0;
    static const int view = 1;
    static const int projection = 2;

    static const int albedo = 3;
    static const int length = 4;

    void build();
    void destroy();
};

class Deferred : public Core::Shader {
public:
    static Deferred instance;

    void build();
    void destroy();
};

/// PBR

class PBRSingleColor : public Core::Shader {
private:
public:
    static PBRSingleColor instance;

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
    void build();
    void destroy();
};

class PBRSingleTexture : public Core::Shader {
private:
public:
    static PBRSingleTexture instance;

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
    void build();
    void destroy();
};

class PBRColorArray : public Core::Shader {
private:
public:
    static PBRColorArray instance;

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
    void build();
    void destroy();
};

class PBRWater : public Core::Shader {
private:
public:
    static PBRWater instance;

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

    void build();
    void destroy();
};

} // namespace Blob::Shaders