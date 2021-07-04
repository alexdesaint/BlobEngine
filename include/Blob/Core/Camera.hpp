#pragma once

#include <Blob/Maths.inl>

namespace Blob {
class Camera : public ViewTransform {
public:
    Camera() = default;
    Camera(const Vec3<float> &cameraPosition,
           const Vec3<float> &cameraLookAt,
           const Vec3<float> &cameraUp) :
        ViewTransform(cameraPosition, cameraLookAt, cameraUp) {}
};
} // namespace Blob
