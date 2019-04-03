#include <Blob/Controls.hpp>

#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Blob {

    bool
            Keys::UNKNOWN = false,
            Keys::SPACE = false,
            Keys::APOSTROPHE = false,
            Keys::COMMA = false,
            Keys::MINUS = false,
            Keys::PERIOD = false,
            Keys::SLASH = false,
            Keys::NUM_0 = false,
            Keys::NUM_1 = false,
            Keys::NUM_2 = false,
            Keys::NUM_3 = false,
            Keys::NUM_4 = false,
            Keys::NUM_5 = false,
            Keys::NUM_6 = false,
            Keys::NUM_7 = false,
            Keys::NUM_8 = false,
            Keys::NUM_9 = false,
            Keys::SEMICOLON = false,
            Keys::EQUAL = false,
            Keys::A = false,
            Keys::B = false,
            Keys::C = false,
            Keys::D = false,
            Keys::E = false,
            Keys::F = false,
            Keys::G = false,
            Keys::H = false,
            Keys::I = false,
            Keys::J = false,
            Keys::K = false,
            Keys::L = false,
            Keys::M = false,
            Keys::N = false,
            Keys::O = false,
            Keys::P = false,
            Keys::Q = false,
            Keys::R = false,
            Keys::S = false,
            Keys::T = false,
            Keys::U = false,
            Keys::V = false,
            Keys::W = false,
            Keys::X = false,
            Keys::Y = false,
            Keys::Z = false,
            Keys::LEFT_BRACKET = false,
            Keys::BACKSLASH = false,
            Keys::RIGHT_BRACKET = false,
            Keys::GRAVE_ACCENT = false,
            Keys::WORLD_1 = false,
            Keys::WORLD_2 = false,
            Keys::ESCAPE = false,
            Keys::ENTER = false,
            Keys::TAB = false,
            Keys::BACKSPACE = false,
            Keys::INSERT = false,
            Keys::DELETE = false,
            Keys::RIGHT = false,
            Keys::LEFT = false,
            Keys::DOWN = false,
            Keys::UP = false,
            Keys::PAGE_UP = false,
            Keys::PAGE_DOWN = false,
            Keys::HOME = false,
            Keys::END = false,
            Keys::CAPS_LOCK = false,
            Keys::SCROLL_LOCK = false,
            Keys::NUM_LOCK = false,
            Keys::PRINT_SCREEN = false,
            Keys::PAUSE = false,
            Keys::F1 = false,
            Keys::F2 = false,
            Keys::F3 = false,
            Keys::F4 = false,
            Keys::F5 = false,
            Keys::F6 = false,
            Keys::F7 = false,
            Keys::F8 = false,
            Keys::F9 = false,
            Keys::F10 = false,
            Keys::F11 = false,
            Keys::F12 = false,
            Keys::F13 = false,
            Keys::F14 = false,
            Keys::F15 = false,
            Keys::F16 = false,
            Keys::F17 = false,
            Keys::F18 = false,
            Keys::F19 = false,
            Keys::F20 = false,
            Keys::F21 = false,
            Keys::F22 = false,
            Keys::F23 = false,
            Keys::F24 = false,
            Keys::F25 = false,
            Keys::KP_0 = false,
            Keys::KP_1 = false,
            Keys::KP_2 = false,
            Keys::KP_3 = false,
            Keys::KP_4 = false,
            Keys::KP_5 = false,
            Keys::KP_6 = false,
            Keys::KP_7 = false,
            Keys::KP_8 = false,
            Keys::KP_9 = false,
            Keys::KP_DECIMAL = false,
            Keys::KP_DIVIDE = false,
            Keys::KP_MULTIPLY = false,
            Keys::KP_SUBTRACT = false,
            Keys::KP_ADD = false,
            Keys::KP_ENTER = false,
            Keys::KP_EQUAL = false,
            Keys::LEFT_SHIFT = false,
            Keys::LEFT_CONTROL = false,
            Keys::LEFT_ALT = false,
            Keys::LEFT_SUPER = false,
            Keys::RIGHT_SHIFT = false,
            Keys::RIGHT_CONTROL = false,
            Keys::RIGHT_ALT = false,
            Keys::RIGHT_SUPER = false,
            Keys::MENU = false;

    static bool *keys[GLFW_KEY_LAST + 2];

    ImGuiIO* io;
    
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

        if (action != 2) {
            (*keys[key + 1]) = (bool)action;
            io->KeysDown[key + 1] = (bool)action;
        }

        // Modifiers are not reliable across systems
        io->KeyCtrl = io->KeysDown[GLFW_KEY_LEFT_CONTROL + 1] || io->KeysDown[GLFW_KEY_RIGHT_CONTROL + 1];
        io->KeyShift = io->KeysDown[GLFW_KEY_LEFT_SHIFT + 1] || io->KeysDown[GLFW_KEY_RIGHT_SHIFT + 1];
        io->KeyAlt = io->KeysDown[GLFW_KEY_LEFT_ALT + 1] || io->KeysDown[GLFW_KEY_RIGHT_ALT + 1];
        io->KeySuper = io->KeysDown[GLFW_KEY_LEFT_SUPER + 1] || io->KeysDown[GLFW_KEY_RIGHT_SUPER + 1];
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
        io->MouseDown[button] = action != GLFW_RELEASE;
    }

    GLFWcursor* g_MouseCursors[ImGuiMouseCursor_COUNT] = {nullptr};
    int oldCursor = 0;

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)	{
        io->MousePos = Vec2f((float) xpos, (float) ypos);

        ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
        if(imgui_cursor != oldCursor) {
            if (imgui_cursor == ImGuiMouseCursor_None) {
                // Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
            } else {
                // Show OS mouse cursor
                if (g_MouseCursors[imgui_cursor] != nullptr)
                    glfwSetCursor(window, g_MouseCursors[imgui_cursor]);
                else
                    glfwSetCursor(window, g_MouseCursors[ImGuiMouseCursor_Arrow]);

                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
        }
        oldCursor = imgui_cursor;
    }

    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
        io->MouseWheelH += (float)xoffset;
        io->MouseWheel += (float)yoffset;
    }

    void character_callback(GLFWwindow* window, unsigned int c) {
        if (c > 0 && c < 0x10000)
            io->AddInputCharacter((unsigned short)c);
    }

    static const char* GetClipboardText(void* user_data) {
        return glfwGetClipboardString((GLFWwindow*)user_data);
    }

    static void SetClipboardText(void* user_data, const char* text) {
        glfwSetClipboardString((GLFWwindow*)user_data, text);
    }

    namespace Controls {

        void init(void *window) {
            keys[GLFW_KEY_UNKNOWN + 1] = &Keys::UNKNOWN;
            keys[GLFW_KEY_SPACE + 1] = &Keys::SPACE;
            keys[GLFW_KEY_APOSTROPHE + 1] = &Keys::APOSTROPHE;
            keys[GLFW_KEY_COMMA + 1] = &Keys::COMMA;
            keys[GLFW_KEY_MINUS + 1] = &Keys::MINUS;
            keys[GLFW_KEY_PERIOD + 1] = &Keys::PERIOD;
            keys[GLFW_KEY_SLASH + 1] = &Keys::SLASH;
            keys[GLFW_KEY_0 + 1] = &Keys::NUM_0;
            keys[GLFW_KEY_1 + 1] = &Keys::NUM_1;
            keys[GLFW_KEY_2 + 1] = &Keys::NUM_2;
            keys[GLFW_KEY_3 + 1] = &Keys::NUM_3;
            keys[GLFW_KEY_4 + 1] = &Keys::NUM_4;
            keys[GLFW_KEY_5 + 1] = &Keys::NUM_5;
            keys[GLFW_KEY_6 + 1] = &Keys::NUM_6;
            keys[GLFW_KEY_7 + 1] = &Keys::NUM_7;
            keys[GLFW_KEY_8 + 1] = &Keys::NUM_8;
            keys[GLFW_KEY_9 + 1] = &Keys::NUM_9;
            keys[GLFW_KEY_SEMICOLON + 1] = &Keys::SEMICOLON;
            keys[GLFW_KEY_EQUAL + 1] = &Keys::EQUAL;
            keys[GLFW_KEY_A + 1] = &Keys::A;
            keys[GLFW_KEY_B + 1] = &Keys::B;
            keys[GLFW_KEY_C + 1] = &Keys::C;
            keys[GLFW_KEY_D + 1] = &Keys::D;
            keys[GLFW_KEY_E + 1] = &Keys::E;
            keys[GLFW_KEY_F + 1] = &Keys::F;
            keys[GLFW_KEY_G + 1] = &Keys::G;
            keys[GLFW_KEY_H + 1] = &Keys::H;
            keys[GLFW_KEY_I + 1] = &Keys::I;
            keys[GLFW_KEY_J + 1] = &Keys::J;
            keys[GLFW_KEY_K + 1] = &Keys::K;
            keys[GLFW_KEY_L + 1] = &Keys::L;
            keys[GLFW_KEY_M + 1] = &Keys::M;
            keys[GLFW_KEY_N + 1] = &Keys::N;
            keys[GLFW_KEY_O + 1] = &Keys::O;
            keys[GLFW_KEY_P + 1] = &Keys::P;
            keys[GLFW_KEY_Q + 1] = &Keys::Q;
            keys[GLFW_KEY_R + 1] = &Keys::R;
            keys[GLFW_KEY_S + 1] = &Keys::S;
            keys[GLFW_KEY_T + 1] = &Keys::T;
            keys[GLFW_KEY_U + 1] = &Keys::U;
            keys[GLFW_KEY_V + 1] = &Keys::V;
            keys[GLFW_KEY_W + 1] = &Keys::W;
            keys[GLFW_KEY_X + 1] = &Keys::X;
            keys[GLFW_KEY_Y + 1] = &Keys::Y;
            keys[GLFW_KEY_Z + 1] = &Keys::Z;
            keys[GLFW_KEY_LEFT_BRACKET + 1] = &Keys::LEFT_BRACKET;
            keys[GLFW_KEY_BACKSLASH + 1] = &Keys::BACKSLASH;
            keys[GLFW_KEY_RIGHT_BRACKET + 1] = &Keys::RIGHT_BRACKET;
            keys[GLFW_KEY_GRAVE_ACCENT + 1] = &Keys::GRAVE_ACCENT;
            keys[GLFW_KEY_WORLD_1 + 1] = &Keys::WORLD_1;
            keys[GLFW_KEY_WORLD_2 + 1] = &Keys::WORLD_2;
            keys[GLFW_KEY_ESCAPE + 1] = &Keys::ESCAPE;
            keys[GLFW_KEY_ENTER + 1] = &Keys::ENTER;
            keys[GLFW_KEY_TAB + 1] = &Keys::TAB;
            keys[GLFW_KEY_BACKSPACE + 1] = &Keys::BACKSLASH;
            keys[GLFW_KEY_INSERT + 1] = &Keys::INSERT;
            keys[GLFW_KEY_DELETE + 1] = &Keys::DELETE;
            keys[GLFW_KEY_RIGHT + 1] = &Keys::RIGHT;
            keys[GLFW_KEY_LEFT + 1] = &Keys::LEFT;
            keys[GLFW_KEY_DOWN + 1] = &Keys::DOWN;
            keys[GLFW_KEY_UP + 1] = &Keys::UP;
            keys[GLFW_KEY_PAGE_UP + 1] = &Keys::PAGE_UP;
            keys[GLFW_KEY_PAGE_DOWN + 1] = &Keys::PAGE_DOWN;
            keys[GLFW_KEY_HOME + 1] = &Keys::HOME;
            keys[GLFW_KEY_END + 1] = &Keys::END;
            keys[GLFW_KEY_CAPS_LOCK + 1] = &Keys::CAPS_LOCK;
            keys[GLFW_KEY_SCROLL_LOCK + 1] = &Keys::SCROLL_LOCK;
            keys[GLFW_KEY_NUM_LOCK + 1] = &Keys::NUM_LOCK;
            keys[GLFW_KEY_PRINT_SCREEN + 1] = &Keys::PRINT_SCREEN;
            keys[GLFW_KEY_PAUSE + 1] = &Keys::PAUSE;
            keys[GLFW_KEY_F1 + 1] = &Keys::F1;
            keys[GLFW_KEY_F2 + 1] = &Keys::F2;
            keys[GLFW_KEY_F3 + 1] = &Keys::F3;
            keys[GLFW_KEY_F4 + 1] = &Keys::F4;
            keys[GLFW_KEY_F5 + 1] = &Keys::F5;
            keys[GLFW_KEY_F6 + 1] = &Keys::F6;
            keys[GLFW_KEY_F7 + 1] = &Keys::F7;
            keys[GLFW_KEY_F8 + 1] = &Keys::F8;
            keys[GLFW_KEY_F9 + 1] = &Keys::F9;
            keys[GLFW_KEY_F10 + 1] = &Keys::F10;
            keys[GLFW_KEY_F11 + 1] = &Keys::F11;
            keys[GLFW_KEY_F12 + 1] = &Keys::F12;
            keys[GLFW_KEY_F13 + 1] = &Keys::F13;
            keys[GLFW_KEY_F14 + 1] = &Keys::F14;
            keys[GLFW_KEY_F15 + 1] = &Keys::F15;
            keys[GLFW_KEY_F16 + 1] = &Keys::F16;
            keys[GLFW_KEY_F17 + 1] = &Keys::F17;
            keys[GLFW_KEY_F18 + 1] = &Keys::F18;
            keys[GLFW_KEY_F19 + 1] = &Keys::F19;
            keys[GLFW_KEY_F20 + 1] = &Keys::F20;
            keys[GLFW_KEY_F21 + 1] = &Keys::F21;
            keys[GLFW_KEY_F22 + 1] = &Keys::F22;
            keys[GLFW_KEY_F23 + 1] = &Keys::F23;
            keys[GLFW_KEY_F24 + 1] = &Keys::F24;
            keys[GLFW_KEY_F25 + 1] = &Keys::F25;
            keys[GLFW_KEY_KP_0 + 1] = &Keys::KP_0;
            keys[GLFW_KEY_KP_1 + 1] = &Keys::KP_1;
            keys[GLFW_KEY_KP_2 + 1] = &Keys::KP_2;
            keys[GLFW_KEY_KP_3 + 1] = &Keys::KP_3;
            keys[GLFW_KEY_KP_4 + 1] = &Keys::KP_4;
            keys[GLFW_KEY_KP_5 + 1] = &Keys::KP_5;
            keys[GLFW_KEY_KP_6 + 1] = &Keys::KP_6;
            keys[GLFW_KEY_KP_7 + 1] = &Keys::KP_7;
            keys[GLFW_KEY_KP_8 + 1] = &Keys::KP_8;
            keys[GLFW_KEY_KP_9 + 1] = &Keys::KP_9;
            keys[GLFW_KEY_KP_DECIMAL + 1] = &Keys::KP_DECIMAL;
            keys[GLFW_KEY_KP_DIVIDE + 1] = &Keys::KP_DIVIDE;
            keys[GLFW_KEY_KP_MULTIPLY + 1] = &Keys::KP_MULTIPLY;
            keys[GLFW_KEY_KP_SUBTRACT + 1] = &Keys::KP_SUBTRACT;
            keys[GLFW_KEY_KP_ADD + 1] = &Keys::KP_ADD;
            keys[GLFW_KEY_KP_ENTER + 1] = &Keys::KP_ENTER;
            keys[GLFW_KEY_KP_EQUAL + 1] = &Keys::KP_EQUAL;
            keys[GLFW_KEY_LEFT_SHIFT + 1] = &Keys::LEFT_SHIFT;
            keys[GLFW_KEY_LEFT_CONTROL + 1] = &Keys::LEFT_CONTROL;
            keys[GLFW_KEY_LEFT_ALT + 1] = &Keys::LEFT_ALT;
            keys[GLFW_KEY_LEFT_SUPER + 1] = &Keys::LEFT_SUPER;
            keys[GLFW_KEY_RIGHT_SHIFT + 1] = &Keys::RIGHT_SHIFT;
            keys[GLFW_KEY_RIGHT_CONTROL + 1] = &Keys::RIGHT_CONTROL;
            keys[GLFW_KEY_RIGHT_ALT + 1] = &Keys::RIGHT_ALT;
            keys[GLFW_KEY_RIGHT_SUPER + 1] = &Keys::RIGHT_SUPER;
            keys[GLFW_KEY_MENU + 1] = &Keys::MENU;

            io = &ImGui::GetIO();

            //callback
            // Setup back-end capabilities flags
            io->BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
            io->BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

            // Keyboard mapping. ImGui will use those indices to peek into the io->KeysDown[] array.
            io->KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB + 1;
            io->KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT + 1;
            io->KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT + 1;
            io->KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP + 1;
            io->KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN + 1;
            io->KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP + 1;
            io->KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN + 1;
            io->KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME + 1;
            io->KeyMap[ImGuiKey_End] = GLFW_KEY_END + 1;
            io->KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT + 1;
            io->KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE + 1;
            io->KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE + 1;
            io->KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE + 1;
            io->KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER + 1;
            io->KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE + 1;
            io->KeyMap[ImGuiKey_A] = GLFW_KEY_A + 1;
            io->KeyMap[ImGuiKey_C] = GLFW_KEY_C + 1;
            io->KeyMap[ImGuiKey_V] = GLFW_KEY_V + 1;
            io->KeyMap[ImGuiKey_X] = GLFW_KEY_X + 1;
            io->KeyMap[ImGuiKey_Y] = GLFW_KEY_Y + 1;
            io->KeyMap[ImGuiKey_Z] = GLFW_KEY_Z + 1;
            glfwSetKeyCallback((GLFWwindow *) window, key_callback);
            glfwSetMouseButtonCallback((GLFWwindow *) window, mouse_button_callback);

            g_MouseCursors[ImGuiMouseCursor_Arrow] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
            g_MouseCursors[ImGuiMouseCursor_TextInput] = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
            g_MouseCursors[ImGuiMouseCursor_ResizeAll] = glfwCreateStandardCursor(
                    GLFW_CROSSHAIR_CURSOR);   // FIXME: GLFW doesn't have this.
            g_MouseCursors[ImGuiMouseCursor_ResizeNS] = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
            g_MouseCursors[ImGuiMouseCursor_ResizeEW] = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
            g_MouseCursors[ImGuiMouseCursor_ResizeNESW] = glfwCreateStandardCursor(
                    GLFW_CROSSHAIR_CURSOR);  // FIXME: GLFW doesn't have this.
            g_MouseCursors[ImGuiMouseCursor_ResizeNWSE] = glfwCreateStandardCursor(
                    GLFW_CROSSHAIR_CURSOR);  // FIXME: GLFW doesn't have this.
            g_MouseCursors[ImGuiMouseCursor_Hand] = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
            io->MousePos = Vec2f();
            glfwSetCursorPosCallback((GLFWwindow *) window, cursor_position_callback);
            glfwSetScrollCallback((GLFWwindow *) window, scroll_callback);
            glfwSetCharCallback((GLFWwindow *) window, character_callback);

            io->SetClipboardTextFn = SetClipboardText;
            io->GetClipboardTextFn = GetClipboardText;
        }
    }
}