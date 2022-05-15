#pragma once

#include <Blob/Camera.hpp>
#include <Blob/Controls.hpp>
#include <Blob/Maths.hpp>
#include <imgui.h>

namespace Blob {

class OrbitCamera : private MouseEvents, public Camera {
public:
    Vec3<> lookAt;
    Vec2<> mousePos, oldMousePos;
    bool rotate = false;
    float zAngle = 1, xyAngle = 1;
    Vec3<> up{0, 0, 1}, backward{-0.5, -0.5, 0.5};
    float zAngleOld = zAngle, xyAngleOld = xyAngle, dist = 10;
    float minZ = 0.001, maxZ = std::numbers::pi, sensibility = 400;
    float minDist = 5, maxDist = 40;
    MouseKey mouseKey = MouseKeys::LEFT;

    void mouseButtonUpdate(MouseKey button, bool pressed) final {
        if (button != mouseKey)
            return;

        if (ImGui::GetIO().WantCaptureMouse)
            return;

        if (pressed) {
            oldMousePos = mousePos;
            xyAngleOld = xyAngle;
            zAngleOld = zAngle;
        }
        rotate = pressed;
    }

    void cursorPosUpdate(double xpos, double ypos) final {
        mousePos.x = xpos;
        mousePos.y = ypos;

        if (!rotate)
            return;

        auto diff = mousePos - oldMousePos;

        zAngle = zAngleOld - diff.y / sensibility;
        if (zAngle > maxZ)
            zAngle = maxZ;
        if (zAngle < minZ)
            zAngle = minZ;
        xyAngle = xyAngleOld - diff.x / sensibility;
        backward = Vec3{std::cos(xyAngle) * std::sin(zAngle),
                        std::sin(xyAngle) * std::sin(zAngle),
                        std::cos(zAngle)};

        if ((unsigned int) (zAngle / std::numbers::pi + 10000) % 2 == 0)
            up.z = 1;
        else
            up.z = -1;

        setCameraUp(up);
        setPosition(backward * dist + lookAt, lookAt);
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
    OrbitCamera(Vec3<float> lookAt = {}, float dist = 32) :
        lookAt(lookAt),
        dist(dist),
        backward{std::cos(xyAngle) * std::sin(zAngle),
                 std::sin(xyAngle) * std::sin(zAngle),
                 std::cos(zAngle)} {
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
        ImGui::Text("forward: %f %f %f", backward.x, backward.y, backward.z);
        ImGui::Text("dist: %f", dist);
        ImGui::Text("lookAt: %f %f %f", lookAt.x, lookAt.y, lookAt.z);
        ImGui::Text("camPos: %f %f %f", camPos.x, camPos.y, camPos.z);
        ImGui::Text("xy Angle: %f", xyAngle);
        ImGui::Text("z Angle: %f", zAngle);
        ImGui::Text("up: %0.1f %0.1f %0.1f", up.x, up.y, up.z);
    }
};
} // namespace Blob
