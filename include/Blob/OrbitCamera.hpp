#pragma once

#include <Blob/Camera.hpp>
#include <Blob/Controls.hpp>
#include <Blob/Maths.hpp>
#include <imgui.h>

namespace Blob {

class OrbitCamera : private MouseEvents, public Camera {
private:
    enum Mode { Nothing, Rotate, Move } mode = Nothing;
    MouseKey rotateKey = MouseKeys::RIGHT;
    MouseKey moveKey = MouseKeys::LEFT;

    Vec3<> lookAt;
    Vec2<> mouseScreenPosition, mouseCameraPosition, oldMousePos, oldMouseWorldPos, oldCameraLookAt;
    float zAngle = 1, xyAngle = 1;
    Vec3<> up{0, 0, 1}, backward{-0.5, -0.5, 0.5};
    float zAngleOld = zAngle, xyAngleOld = xyAngle, dist = 10;

public:
    float minDist = 5, maxDist = 40;
    float minZ = 0.001, maxZ = std::numbers::pi;
    float sensibility = 400;

    void mouseButtonUpdate(MouseKey button, bool pressed) final {
        if (ImGui::GetIO().WantCaptureMouse)
            return;

        if (mode == Nothing && button == rotateKey && pressed) {
            oldMousePos = mouseScreenPosition;
            xyAngleOld = xyAngle;
            zAngleOld = zAngle;

            mode = Rotate;
        } else if (mode == Nothing && button == moveKey && pressed) {
            oldMouseWorldPos = screenToWorldCoordinate(mouseCameraPosition, 0);
            oldCameraLookAt = lookAt;

            mode = Move;
        } else
            mode = Nothing;
    }

    void cursorPosUpdate(const Vec2<> &screenPosition, const Vec2<> &cameraPosition) final {
        mouseScreenPosition = screenPosition;
        mouseCameraPosition = cameraPosition;

        if (mode == Rotate) {
            auto diff = screenPosition - oldMousePos;

            zAngle = zAngleOld - diff.y / sensibility;
            if (zAngle > maxZ)
                zAngle = maxZ;
            if (zAngle < minZ)
                zAngle = minZ;
            xyAngle = xyAngleOld - diff.x / sensibility;
            backward =
                Vec3{std::cos(xyAngle) * std::sin(zAngle), std::sin(xyAngle) * std::sin(zAngle), std::cos(zAngle)};

            if ((unsigned int) (zAngle / std::numbers::pi + 10000) % 2 == 0)
                up.z = 1;
            else
                up.z = -1;

            setCameraUp(up);
            setPosition(backward * dist + lookAt, lookAt);
        } else if (mode == Move) {
            oldCameraLookAt += oldMouseWorldPos - ((Blob::Vec2<>) screenToWorldCoordinate(mouseCameraPosition, 0));
            setLookAt(oldCameraLookAt);
        }
    }

    void scrollUpdate(double, double yoffset) final {
        if (ImGui::GetIO().WantCaptureMouse)
            return;
        dist -= yoffset * 2;
        if (dist < minDist)
            dist = minDist;
        if (dist > maxDist)
            dist = maxDist;
        setPosition(backward * dist + lookAt, lookAt);
    }

public:
    OrbitCamera(Context &context, Vec3<float> lookAt = {}, float dist = 30, float minDist = 5, float maxDist = 40) :
        Camera(context),
        MouseEvents(context),
        lookAt(lookAt),
        dist(dist),
        minDist(minDist),
        maxDist(maxDist),
        backward{std::cos(xyAngle) * std::sin(zAngle), std::sin(xyAngle) * std::sin(zAngle), std::cos(zAngle)} {
        setCameraUp(up);
        setPosition(backward * dist + lookAt, lookAt);
    }

    auto getLookAt() { return lookAt; }

    void setLookAt(Vec3<> look) {
        lookAt = look;
        setPosition(backward * dist + lookAt, lookAt);
    }

    void info() {
        auto camPos = backward * dist + lookAt;
        ImGui::Begin("OrbitCamera");
        ImGui::Text("forward: %f %f %f", backward.x, backward.y, backward.z);
        ImGui::Text("dist: %f", dist);
        ImGui::Text("lookAt: %f %f %f", lookAt.x, lookAt.y, lookAt.z);
        ImGui::Text("camPos: %f %f %f", camPos.x, camPos.y, camPos.z);
        ImGui::Text("xy Angle: %f", xyAngle);
        ImGui::Text("z Angle: %f", zAngle);
        ImGui::Text("up: %0.1f %0.1f %0.1f", up.x, up.y, up.z);
        ImGui::End();
    }
};
} // namespace Blob
