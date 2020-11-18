#pragma once

#include <Blob/Maths.inl>

namespace Blob::Core {
class Camera : public Maths::ViewTransform {
public:
    Camera() = default;
    Camera(const Maths::Vec3<float> &cameraPosition, const Maths::Vec3<float> &cameraLookAt, const Maths::Vec3<float> &cameraUp)
        : Maths::ViewTransform(cameraPosition, cameraLookAt, cameraUp) {}
};
} // namespace Blob::Core
