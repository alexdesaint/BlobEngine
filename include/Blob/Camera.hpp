#pragma once

#include <Blob/Maths.hpp>

namespace Blob {
class Camera : public ViewTransform {
public:
    Camera() = default;
    Camera(const Vec3<float> &cameraPosition,
           const Vec3<float> &cameraLookAt,
           const Vec3<float> &cameraUp = {0, 0, 1}) :
        ViewTransform(cameraPosition, cameraLookAt, cameraUp) {}
};
} // namespace Blob
