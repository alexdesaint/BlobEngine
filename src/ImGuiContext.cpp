#include "bgfx/bgfx.h"
#include "imgui.h"
#include <Blob/ImGuiContext.hpp>
#include <bgfx/embedded_shader.h>
#include <bx/math.h>
#include <memory>
#include <shaders/fs_ocornut_imgui.sc.spv.bin.h>
#include <shaders/vs_ocornut_imgui.sc.spv.bin.h>

namespace Blob {

ImGuiKey ImGuiContext::KeycodeToImGuiKey(Key keycode) {
    if (Keys::TAB == keycode)
        return ImGuiKey_Tab;
    if (Keys::LEFT == keycode)
        return ImGuiKey_LeftArrow;
    if (Keys::RIGHT == keycode)
        return ImGuiKey_RightArrow;
    if (Keys::UP == keycode)
        return ImGuiKey_UpArrow;
    if (Keys::DOWN == keycode)
        return ImGuiKey_DownArrow;
    if (Keys::PAGE_UP == keycode)
        return ImGuiKey_PageUp;
    if (Keys::PAGE_DOWN == keycode)
        return ImGuiKey_PageDown;
    if (Keys::HOME == keycode)
        return ImGuiKey_Home;
    if (Keys::END == keycode)
        return ImGuiKey_End;
    if (Keys::INSERT == keycode)
        return ImGuiKey_Insert;
    if (Keys::DEL == keycode)
        return ImGuiKey_Delete;
    if (Keys::BACKSPACE == keycode)
        return ImGuiKey_Backspace;
    if (Keys::SPACE == keycode)
        return ImGuiKey_Space;
    if (Keys::ENTER == keycode)
        return ImGuiKey_Enter;
    if (Keys::ESCAPE == keycode)
        return ImGuiKey_Escape;
    if (Keys::APOSTROPHE == keycode)
        return ImGuiKey_Apostrophe;
    if (Keys::COMMA == keycode)
        return ImGuiKey_Comma;
    if (Keys::MINUS == keycode)
        return ImGuiKey_Minus;
    if (Keys::PERIOD == keycode)
        return ImGuiKey_Period;
    if (Keys::SLASH == keycode)
        return ImGuiKey_Slash;
    if (Keys::SEMICOLON == keycode)
        return ImGuiKey_Semicolon;
    if (Keys::EQUAL == keycode)
        return ImGuiKey_Equal;
    if (Keys::LEFT_BRACKET == keycode)
        return ImGuiKey_LeftBracket;
    if (Keys::BACKSLASH == keycode)
        return ImGuiKey_Backslash;
    if (Keys::RIGHT_BRACKET == keycode)
        return ImGuiKey_RightBracket;
    if (Keys::GRAVE_ACCENT == keycode)
        return ImGuiKey_GraveAccent;
    if (Keys::CAPS_LOCK == keycode)
        return ImGuiKey_CapsLock;
    if (Keys::SCROLL_LOCK == keycode)
        return ImGuiKey_ScrollLock;
    if (Keys::NUM_LOCK == keycode)
        return ImGuiKey_NumLock;
    if (Keys::PRINT_SCREEN == keycode)
        return ImGuiKey_PrintScreen;
    if (Keys::PAUSE == keycode)
        return ImGuiKey_Pause;
    if (Keys::NumericKeypadZero == keycode)
        return ImGuiKey_Keypad0;
    if (Keys::NumericKeypadOne == keycode)
        return ImGuiKey_Keypad1;
    if (Keys::NumericKeypadTwo == keycode)
        return ImGuiKey_Keypad2;
    if (Keys::NumericKeypadThree == keycode)
        return ImGuiKey_Keypad3;
    if (Keys::NumericKeypadFour == keycode)
        return ImGuiKey_Keypad4;
    if (Keys::NumericKeypadFive == keycode)
        return ImGuiKey_Keypad5;
    if (Keys::NumericKeypadSix == keycode)
        return ImGuiKey_Keypad6;
    if (Keys::NumericKeypadSeven == keycode)
        return ImGuiKey_Keypad7;
    if (Keys::NumericKeypadEight == keycode)
        return ImGuiKey_Keypad8;
    if (Keys::NumericKeypadNine == keycode)
        return ImGuiKey_Keypad9;
    if (Keys::NumericKeypadDECIMAL == keycode)
        return ImGuiKey_KeypadDecimal;
    if (Keys::NumericKeypadDIVIDE == keycode)
        return ImGuiKey_KeypadDivide;
    if (Keys::NumericKeypadMULTIPLY == keycode)
        return ImGuiKey_KeypadMultiply;
    if (Keys::NumericKeypadSUBTRACT == keycode)
        return ImGuiKey_KeypadSubtract;
    if (Keys::NumericKeypadADD == keycode)
        return ImGuiKey_KeypadAdd;
    if (Keys::NumericKeypadENTER == keycode)
        return ImGuiKey_KeypadEnter;
    if (Keys::NumericKeypadEQUAL == keycode)
        return ImGuiKey_KeypadEqual;
    if (Keys::LEFT_CONTROL == keycode)
        return ImGuiKey_LeftCtrl;
    if (Keys::LEFT_SHIFT == keycode)
        return ImGuiKey_LeftShift;
    if (Keys::LEFT_ALT == keycode)
        return ImGuiKey_LeftAlt;
    if (Keys::LEFT_SUPER == keycode)
        return ImGuiKey_LeftSuper;
    if (Keys::RIGHT_CONTROL == keycode)
        return ImGuiKey_RightCtrl;
    if (Keys::RIGHT_SHIFT == keycode)
        return ImGuiKey_RightShift;
    if (Keys::RIGHT_ALT == keycode)
        return ImGuiKey_RightAlt;
    if (Keys::RIGHT_SUPER == keycode)
        return ImGuiKey_RightSuper;
    if (Keys::MENU == keycode)
        return ImGuiKey_Menu;
    if (Keys::Zero == keycode)
        return ImGuiKey_0;
    if (Keys::One == keycode)
        return ImGuiKey_1;
    if (Keys::Two == keycode)
        return ImGuiKey_2;
    if (Keys::Three == keycode)
        return ImGuiKey_3;
    if (Keys::Four == keycode)
        return ImGuiKey_4;
    if (Keys::Five == keycode)
        return ImGuiKey_5;
    if (Keys::Six == keycode)
        return ImGuiKey_6;
    if (Keys::Seven == keycode)
        return ImGuiKey_7;
    if (Keys::Eight == keycode)
        return ImGuiKey_8;
    if (Keys::Nine == keycode)
        return ImGuiKey_9;
    if (Keys::A == keycode)
        return ImGuiKey_A;
    if (Keys::B == keycode)
        return ImGuiKey_B;
    if (Keys::C == keycode)
        return ImGuiKey_C;
    if (Keys::D == keycode)
        return ImGuiKey_D;
    if (Keys::E == keycode)
        return ImGuiKey_E;
    if (Keys::F == keycode)
        return ImGuiKey_F;
    if (Keys::G == keycode)
        return ImGuiKey_G;
    if (Keys::H == keycode)
        return ImGuiKey_H;
    if (Keys::I == keycode)
        return ImGuiKey_I;
    if (Keys::J == keycode)
        return ImGuiKey_J;
    if (Keys::K == keycode)
        return ImGuiKey_K;
    if (Keys::L == keycode)
        return ImGuiKey_L;
    if (Keys::M == keycode)
        return ImGuiKey_M;
    if (Keys::N == keycode)
        return ImGuiKey_N;
    if (Keys::O == keycode)
        return ImGuiKey_O;
    if (Keys::P == keycode)
        return ImGuiKey_P;
    if (Keys::Q == keycode)
        return ImGuiKey_Q;
    if (Keys::R == keycode)
        return ImGuiKey_R;
    if (Keys::S == keycode)
        return ImGuiKey_S;
    if (Keys::T == keycode)
        return ImGuiKey_T;
    if (Keys::U == keycode)
        return ImGuiKey_U;
    if (Keys::V == keycode)
        return ImGuiKey_V;
    if (Keys::W == keycode)
        return ImGuiKey_W;
    if (Keys::X == keycode)
        return ImGuiKey_X;
    if (Keys::Y == keycode)
        return ImGuiKey_Y;
    if (Keys::Z == keycode)
        return ImGuiKey_Z;
    if (Keys::F1 == keycode)
        return ImGuiKey_F1;
    if (Keys::F2 == keycode)
        return ImGuiKey_F2;
    if (Keys::F3 == keycode)
        return ImGuiKey_F3;
    if (Keys::F4 == keycode)
        return ImGuiKey_F4;
    if (Keys::F5 == keycode)
        return ImGuiKey_F5;
    if (Keys::F6 == keycode)
        return ImGuiKey_F6;
    if (Keys::F7 == keycode)
        return ImGuiKey_F7;
    if (Keys::F8 == keycode)
        return ImGuiKey_F8;
    if (Keys::F9 == keycode)
        return ImGuiKey_F9;
    if (Keys::F10 == keycode)
        return ImGuiKey_F10;
    if (Keys::F11 == keycode)
        return ImGuiKey_F11;
    if (Keys::F12 == keycode)
        return ImGuiKey_F12;
    return ImGuiKey_None;
}

ImGuiContext::ImGuiContext() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    shader = std::make_unique<Shader>(Buffer{vs_ocornut_imgui_spv}, Buffer{fs_ocornut_imgui_spv});
    ImGuiIO &io = ImGui::GetIO();

    m_layout.begin()
        .add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
        .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
        .end();

    uniformSampler = std::make_unique<UniformSampler>("s_tex");
    uint8_t *data;
    int32_t width;
    int32_t height;
    io.Fonts->GetTexDataAsRGBA32(&data, &width, &height);

    texture = std::make_unique<Texture>();
    texture->textureHandle = bgfx::createTexture2D((uint16_t) width,
                                                   (uint16_t) height,
                                                   false,
                                                   1,
                                                   bgfx::TextureFormat::BGRA8,
                                                   0,
                                                   bgfx::copy(data, width * height * 4));
    io.Fonts->SetTexID((ImTextureID) texture.get());
}

ImGuiContext::~ImGuiContext() { ImGui::DestroyContext(); }

void ImGuiContext::RenderDrawData(ImDrawData *draw_data) {
    // Avoid rendering when minimized, scale coordinates for retina displays
    // (screen coordinates != framebuffer coordinates)
    int fb_width = (int) (draw_data->DisplaySize.x * draw_data->FramebufferScale.x);
    int fb_height = (int) (draw_data->DisplaySize.y * draw_data->FramebufferScale.y);
    if (fb_width <= 0 || fb_height <= 0)
        return;

    bgfx::setViewName(m_viewId, "ImGui");
    bgfx::setViewMode(m_viewId, bgfx::ViewMode::Sequential);

    const bgfx::Caps *caps = bgfx::getCaps();
    {
        float ortho[16];
        float x = draw_data->DisplayPos.x;
        float y = draw_data->DisplayPos.y;
        float width = draw_data->DisplaySize.x;
        float height = draw_data->DisplaySize.y;

        bx::mtxOrtho(ortho, x, x + width, y + height, y, 0.0f, 1000.0f, 0.0f, caps->homogeneousDepth);
        bgfx::setViewTransform(m_viewId, NULL, ortho);
        bgfx::setViewRect(m_viewId, 0, 0, uint16_t(width), uint16_t(height));
    }

    const ImVec2 clipPos = draw_data->DisplayPos;
    const ImVec2 clipScale = draw_data->FramebufferScale;

    // Render command lists
    for (int32_t ii = 0, num = draw_data->CmdListsCount; ii < num; ++ii) {
        bgfx::TransientVertexBuffer tvb;
        bgfx::TransientIndexBuffer tib;

        const ImDrawList *drawList = draw_data->CmdLists[ii];
        uint32_t numVertices = (uint32_t) drawList->VtxBuffer.size();
        uint32_t numIndices = (uint32_t) drawList->IdxBuffer.size();

        bgfx::allocTransientVertexBuffer(&tvb, numVertices, m_layout);
        bgfx::allocTransientIndexBuffer(&tib, numIndices, sizeof(ImDrawIdx) == 4);

        ImDrawVert *verts = (ImDrawVert *) tvb.data;
        bx::memCopy(verts, drawList->VtxBuffer.begin(), numVertices * sizeof(ImDrawVert));

        ImDrawIdx *indices = (ImDrawIdx *) tib.data;
        bx::memCopy(indices, drawList->IdxBuffer.begin(), numIndices * sizeof(ImDrawIdx));

        bgfx::Encoder *encoder = bgfx::begin();

        uint32_t offset = 0;
        for (const ImDrawCmd *cmd = drawList->CmdBuffer.begin(), *cmdEnd = drawList->CmdBuffer.end(); cmd != cmdEnd;
             ++cmd) {
            if (cmd->UserCallback) {
                cmd->UserCallback(drawList, cmd);
            } else if (0 != cmd->ElemCount) {
                ImVec4 clipRect;
                clipRect.x = (cmd->ClipRect.x - clipPos.x) * clipScale.x;
                clipRect.y = (cmd->ClipRect.y - clipPos.y) * clipScale.y;
                clipRect.z = (cmd->ClipRect.z - clipPos.x) * clipScale.x;
                clipRect.w = (cmd->ClipRect.w - clipPos.y) * clipScale.y;

                if (clipRect.x < fb_width && clipRect.y < fb_height && clipRect.z >= 0.0f && clipRect.w >= 0.0f) {
                    const uint16_t xx = uint16_t(bx::max(clipRect.x, 0.0f));
                    const uint16_t yy = uint16_t(bx::max(clipRect.y, 0.0f));
                    encoder->setScissor(xx,
                                        yy,
                                        uint16_t(bx::min(clipRect.z, 65535.0f) - xx),
                                        uint16_t(bx::min(clipRect.w, 65535.0f) - yy));

                    encoder->setState(
                        BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_MSAA |
                        BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA));
                    encoder->setTexture(0, uniformSampler->uniformHandle, cmd->GetTexID()->textureHandle);
                    encoder->setVertexBuffer(0, &tvb, 0, numVertices);
                    encoder->setIndexBuffer(&tib, offset, cmd->ElemCount);
                    encoder->submit(m_viewId, shader->shaderHandle);
                }
            }

            offset += cmd->ElemCount;
        }

        bgfx::end(encoder);
    }

    bgfx::setViewRect(m_viewId, 0, 0, uint16_t(draw_data->DisplaySize.x), uint16_t(draw_data->DisplaySize.y));
}

} // namespace Blob
