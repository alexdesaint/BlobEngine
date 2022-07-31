#pragma once

#include <Blob/Context.hpp>

namespace Blob {
class Camera : public ViewTransform {
protected:
    Context &context;

public:
    Camera(Context &context) : context(context) {}
    Camera(Context &context,
           const Vec3<float> &cameraPosition,
           const Vec3<float> &cameraLookAt,
           const Vec3<float> &cameraUp = {0, 0, 1}) :
        context(context), ViewTransform(cameraPosition, cameraLookAt, cameraUp) {}

    Vec3<float> screenToWorldCoordinate(const Vec3<float> screenCoordinate) {
        const auto mvpInv = (context.projectionTransform * (*this)).inverse();

        Vec4<> worldCoordinate = mvpInv * screenCoordinate;

        return worldCoordinate / worldCoordinate.w;
    }

    Vec3<float> screenToWorldCoordinate(const Vec2<> screenPos, float zWorld) {
        const auto mvpInv = (context.projectionTransform * (*this)).inverse();

        Vec4<> worldPos{screenPos};

        worldPos.z = (mvpInv.a34 - screenPos.x * (mvpInv.a41 * zWorld - mvpInv.a31)
                      - screenPos.y * (mvpInv.a42 * zWorld - mvpInv.a32) - mvpInv.a44 * zWorld)
                     / (mvpInv.a43 * zWorld - mvpInv.a33);

        worldPos = mvpInv * worldPos;
        return worldPos / worldPos.w;
    }

    std::array<Vec3<>, 4> getCameraCornersInWorld(float zWorld = 0) {
        return {
            screenToWorldCoordinate({+1, +1}, zWorld),
            screenToWorldCoordinate({-1, +1}, zWorld),
            screenToWorldCoordinate({-1, -1}, zWorld),
            screenToWorldCoordinate({+1, -1}, zWorld),
        };
    }
};

} // namespace Blob
