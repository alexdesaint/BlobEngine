#include <Blob/OrbitCamera.hpp>
#include <Blob/Window.hpp>
#include <imgui.h>

#define STB_TRUETYPE_IMPLEMENTATION 1
#include <stb/stb_truetype.h>

#include <nanovg.h>

int main() {
    Blob::Window window;
    Blob::Camera camera;
    NVGcontext *m_nvg = nvgCreate(1, 0);

    while (window.isOpen) {
        ImGui::ShowDemoWindow();

        nvgBeginFrame(m_nvg,
                      float(window.windowSize.x),
                      float(window.windowSize.y),
                      1.0f);

        nvgStrokeWidth(m_nvg, 2.0f);
        nvgStrokeColor(m_nvg, nvgRGBA(0, 192, 255, 255));
        nvgBeginPath(m_nvg);
        nvgMoveTo(m_nvg, 10, 20);
        nvgLineTo(m_nvg, 230, 20);
        nvgLineTo(m_nvg, 230, 460);
        nvgLineTo(m_nvg, 10, 460);
        nvgClosePath(m_nvg);
        nvgStroke(m_nvg);

        nvgFillColor(m_nvg, nvgRGBA(0, 192, 255, 255));
        nvgBeginPath(m_nvg);
        nvgRect(m_nvg, 20, 40, 200, 400);
        nvgFill(m_nvg);

        nvgEndFrame(m_nvg);

        window.display(camera);
    }
    nvgDelete(m_nvg);
}
