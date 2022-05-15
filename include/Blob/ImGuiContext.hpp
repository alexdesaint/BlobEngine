#pragma once

#include <Blob/Controls.hpp>
#include <Blob/Shader.hpp>
#include <imgui.h>
#include <memory>

namespace Blob {
class ImGuiContext {
private:
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture> texture;
    std::unique_ptr<UniformSampler> uniformSampler;
    bgfx::VertexLayout m_layout;
    bgfx::ViewId m_viewId = 1;

public:
    static ImGuiKey KeycodeToImGuiKey(Key keycode);

    ImGuiContext();
    ~ImGuiContext();
    void RenderDrawData(ImDrawData *draw_data);
    static void setClipboardText(const std::string &text);
};
} // namespace Blob
