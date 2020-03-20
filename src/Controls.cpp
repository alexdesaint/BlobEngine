#include <Blob/Controls.hpp>

#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Blob {

    static bool
            LOCAL_UNKNOWN = false,
            LOCAL_SPACE = false,
            LOCAL_APOSTROPHE = false,
            LOCAL_COMMA = false,
            LOCAL_MINUS = false,
            LOCAL_PERIOD = false,
            LOCAL_SLASH = false,
            LOCAL_NUM_0 = false,
            LOCAL_NUM_1 = false,
            LOCAL_NUM_2 = false,
            LOCAL_NUM_3 = false,
            LOCAL_NUM_4 = false,
            LOCAL_NUM_5 = false,
            LOCAL_NUM_6 = false,
            LOCAL_NUM_7 = false,
            LOCAL_NUM_8 = false,
            LOCAL_NUM_9 = false,
            LOCAL_SEMICOLON = false,
            LOCAL_EQUAL = false,
            LOCAL_A = false,
            LOCAL_B = false,
            LOCAL_C = false,
            LOCAL_D = false,
            LOCAL_E = false,
            LOCAL_F = false,
            LOCAL_G = false,
            LOCAL_H = false,
            LOCAL_I = false,
            LOCAL_J = false,
            LOCAL_K = false,
            LOCAL_L = false,
            LOCAL_M = false,
            LOCAL_N = false,
            LOCAL_O = false,
            LOCAL_P = false,
            LOCAL_Q = false,
            LOCAL_R = false,
            LOCAL_S = false,
            LOCAL_T = false,
            LOCAL_U = false,
            LOCAL_V = false,
            LOCAL_W = false,
            LOCAL_X = false,
            LOCAL_Y = false,
            LOCAL_Z = false,
            LOCAL_LEFT_BRACKET = false,
            LOCAL_BACKSLASH = false,
            LOCAL_RIGHT_BRACKET = false,
            LOCAL_GRAVE_ACCENT = false,
            LOCAL_WORLD_1 = false,
            LOCAL_WORLD_2 = false,
            LOCAL_ESCAPE = false,
            LOCAL_ENTER = false,
            LOCAL_TAB = false,
            LOCAL_BACKSPACE = false,
            LOCAL_INSERT = false,
            LOCAL_DELETE = false,
            LOCAL_RIGHT = false,
            LOCAL_LEFT = false,
            LOCAL_DOWN = false,
            LOCAL_UP = false,
            LOCAL_PAGE_UP = false,
            LOCAL_PAGE_DOWN = false,
            LOCAL_HOME = false,
            LOCAL_END = false,
            LOCAL_CAPS_LOCK = false,
            LOCAL_SCROLL_LOCK = false,
            LOCAL_NUM_LOCK = false,
            LOCAL_PRINT_SCREEN = false,
            LOCAL_PAUSE = false,
            LOCAL_F1 = false,
            LOCAL_F2 = false,
            LOCAL_F3 = false,
            LOCAL_F4 = false,
            LOCAL_F5 = false,
            LOCAL_F6 = false,
            LOCAL_F7 = false,
            LOCAL_F8 = false,
            LOCAL_F9 = false,
            LOCAL_F10 = false,
            LOCAL_F11 = false,
            LOCAL_F12 = false,
            LOCAL_F13 = false,
            LOCAL_F14 = false,
            LOCAL_F15 = false,
            LOCAL_F16 = false,
            LOCAL_F17 = false,
            LOCAL_F18 = false,
            LOCAL_F19 = false,
            LOCAL_F20 = false,
            LOCAL_F21 = false,
            LOCAL_F22 = false,
            LOCAL_F23 = false,
            LOCAL_F24 = false,
            LOCAL_F25 = false,
            LOCAL_KP_0 = false,
            LOCAL_KP_1 = false,
            LOCAL_KP_2 = false,
            LOCAL_KP_3 = false,
            LOCAL_KP_4 = false,
            LOCAL_KP_5 = false,
            LOCAL_KP_6 = false,
            LOCAL_KP_7 = false,
            LOCAL_KP_8 = false,
            LOCAL_KP_9 = false,
            LOCAL_KP_DECIMAL = false,
            LOCAL_KP_DIVIDE = false,
            LOCAL_KP_MULTIPLY = false,
            LOCAL_KP_SUBTRACT = false,
            LOCAL_KP_ADD = false,
            LOCAL_KP_ENTER = false,
            LOCAL_KP_EQUAL = false,
            LOCAL_LEFT_SHIFT = false,
            LOCAL_LEFT_CONTROL = false,
            LOCAL_LEFT_ALT = false,
            LOCAL_LEFT_SUPER = false,
            LOCAL_RIGHT_SHIFT = false,
            LOCAL_RIGHT_CONTROL = false,
            LOCAL_RIGHT_ALT = false,
            LOCAL_RIGHT_SUPER = false,
            LOCAL_MENU = false;

    static bool *keys[GLFW_KEY_LAST + 2];

    const bool
            &Controls::Keys::UNKNOWN = LOCAL_UNKNOWN,
            &Controls::Keys::SPACE = LOCAL_SPACE,
            &Controls::Keys::APOSTROPHE = LOCAL_APOSTROPHE,
            &Controls::Keys::COMMA = LOCAL_COMMA,
            &Controls::Keys::MINUS = LOCAL_MINUS,
            &Controls::Keys::PERIOD = LOCAL_PERIOD,
            &Controls::Keys::SLASH = LOCAL_SLASH,
            &Controls::Keys::NUM_0 = LOCAL_NUM_0,
            &Controls::Keys::NUM_1 = LOCAL_NUM_1,
            &Controls::Keys::NUM_2 = LOCAL_NUM_2,
            &Controls::Keys::NUM_3 = LOCAL_NUM_3,
            &Controls::Keys::NUM_4 = LOCAL_NUM_4,
            &Controls::Keys::NUM_5 = LOCAL_NUM_5,
            &Controls::Keys::NUM_6 = LOCAL_NUM_6,
            &Controls::Keys::NUM_7 = LOCAL_NUM_7,
            &Controls::Keys::NUM_8 = LOCAL_NUM_8,
            &Controls::Keys::NUM_9 = LOCAL_NUM_9,
            &Controls::Keys::SEMICOLON = LOCAL_SEMICOLON,
            &Controls::Keys::EQUAL = LOCAL_EQUAL,
            &Controls::Keys::A = LOCAL_A,
            &Controls::Keys::B = LOCAL_B,
            &Controls::Keys::C = LOCAL_C,
            &Controls::Keys::D = LOCAL_D,
            &Controls::Keys::E = LOCAL_E,
            &Controls::Keys::F = LOCAL_F,
            &Controls::Keys::G = LOCAL_G,
            &Controls::Keys::H = LOCAL_H,
            &Controls::Keys::I = LOCAL_I,
            &Controls::Keys::J = LOCAL_J,
            &Controls::Keys::K = LOCAL_K,
            &Controls::Keys::L = LOCAL_L,
            &Controls::Keys::M = LOCAL_M,
            &Controls::Keys::N = LOCAL_N,
            &Controls::Keys::O = LOCAL_O,
            &Controls::Keys::P = LOCAL_P,
            &Controls::Keys::Q = LOCAL_Q,
            &Controls::Keys::R = LOCAL_R,
            &Controls::Keys::S = LOCAL_S,
            &Controls::Keys::T = LOCAL_T,
            &Controls::Keys::U = LOCAL_U,
            &Controls::Keys::V = LOCAL_V,
            &Controls::Keys::W = LOCAL_W,
            &Controls::Keys::X = LOCAL_X,
            &Controls::Keys::Y = LOCAL_Y,
            &Controls::Keys::Z = LOCAL_Z,
            &Controls::Keys::LEFT_BRACKET = LOCAL_LEFT_BRACKET,
			&Controls::Keys::BACKSLASH = LOCAL_BACKSLASH,
			&Controls::Keys::RIGHT_BRACKET = LOCAL_RIGHT_BRACKET,
			&Controls::Keys::GRAVE_ACCENT = LOCAL_GRAVE_ACCENT,
			&Controls::Keys::WORLD_1 = LOCAL_WORLD_1,
			&Controls::Keys::WORLD_2 = LOCAL_WORLD_2,
			&Controls::Keys::ESCAPE = LOCAL_ESCAPE,
			&Controls::Keys::ENTER = LOCAL_ENTER,
			&Controls::Keys::TAB = LOCAL_TAB,
			&Controls::Keys::BACKSPACE = LOCAL_BACKSPACE,
			&Controls::Keys::INSERT = LOCAL_INSERT,
			&Controls::Keys::DEL = LOCAL_DELETE,
			&Controls::Keys::RIGHT = LOCAL_RIGHT,
			&Controls::Keys::LEFT = LOCAL_LEFT,
			&Controls::Keys::DOWN = LOCAL_DOWN,
			&Controls::Keys::UP = LOCAL_UP,
			&Controls::Keys::PAGE_UP = LOCAL_PAGE_UP,
			&Controls::Keys::PAGE_DOWN = LOCAL_PAGE_DOWN,
			&Controls::Keys::HOME = LOCAL_HOME,
			&Controls::Keys::END = LOCAL_END,
			&Controls::Keys::CAPS_LOCK = LOCAL_CAPS_LOCK,
			&Controls::Keys::SCROLL_LOCK = LOCAL_SCROLL_LOCK,
            &Controls::Keys::NUM_LOCK = LOCAL_NUM_LOCK,
            &Controls::Keys::PRINT_SCREEN = LOCAL_PRINT_SCREEN,
            &Controls::Keys::PAUSE = LOCAL_PAUSE,
            &Controls::Keys::F1 = LOCAL_F1,
            &Controls::Keys::F2 = LOCAL_F2,
            &Controls::Keys::F3 = LOCAL_F3,
            &Controls::Keys::F4 = LOCAL_F4,
            &Controls::Keys::F5 = LOCAL_F5,
            &Controls::Keys::F6 = LOCAL_F6,
            &Controls::Keys::F7 = LOCAL_F7,
            &Controls::Keys::F8 = LOCAL_F8,
            &Controls::Keys::F9 = LOCAL_F9,
            &Controls::Keys::F10 = LOCAL_F10,
            &Controls::Keys::F11 = LOCAL_F11,
            &Controls::Keys::F12 = LOCAL_F12,
            &Controls::Keys::F13 = LOCAL_F13,
            &Controls::Keys::F14 = LOCAL_F14,
            &Controls::Keys::F15 = LOCAL_F15,
            &Controls::Keys::F16 = LOCAL_F16,
            &Controls::Keys::F17 = LOCAL_F17,
            &Controls::Keys::F18 = LOCAL_F18,
            &Controls::Keys::F19 = LOCAL_F19,
            &Controls::Keys::F20 = LOCAL_F20,
            &Controls::Keys::F21 = LOCAL_F21,
            &Controls::Keys::F22 = LOCAL_F22,
            &Controls::Keys::F23 = LOCAL_F23,
            &Controls::Keys::F24 = LOCAL_F24,
            &Controls::Keys::F25 = LOCAL_F25,
            &Controls::Keys::KP_0 = LOCAL_KP_0,
            &Controls::Keys::KP_1 = LOCAL_KP_1,
            &Controls::Keys::KP_2 = LOCAL_KP_2,
            &Controls::Keys::KP_3 = LOCAL_KP_3,
            &Controls::Keys::KP_4 = LOCAL_KP_4,
            &Controls::Keys::KP_5 = LOCAL_KP_5,
            &Controls::Keys::KP_6 = LOCAL_KP_6,
            &Controls::Keys::KP_7 = LOCAL_KP_7,
            &Controls::Keys::KP_8 = LOCAL_KP_8,
            &Controls::Keys::KP_9 = LOCAL_KP_9,
            &Controls::Keys::KP_DECIMAL = LOCAL_KP_DECIMAL,
            &Controls::Keys::KP_DIVIDE = LOCAL_KP_DIVIDE,
            &Controls::Keys::KP_MULTIPLY = LOCAL_KP_MULTIPLY,
            &Controls::Keys::KP_SUBTRACT = LOCAL_KP_SUBTRACT,
            &Controls::Keys::KP_ADD = LOCAL_KP_ADD,
            &Controls::Keys::KP_ENTER = LOCAL_KP_ENTER,
            &Controls::Keys::KP_EQUAL = LOCAL_KP_EQUAL,
            &Controls::Keys::LEFT_SHIFT = LOCAL_LEFT_SHIFT,
            &Controls::Keys::LEFT_CONTROL = LOCAL_LEFT_CONTROL,
            &Controls::Keys::LEFT_ALT = LOCAL_LEFT_ALT,
            &Controls::Keys::LEFT_SUPER = LOCAL_LEFT_SUPER,
            &Controls::Keys::RIGHT_SHIFT = LOCAL_RIGHT_SHIFT,
            &Controls::Keys::RIGHT_CONTROL = LOCAL_RIGHT_CONTROL,
            &Controls::Keys::RIGHT_ALT = LOCAL_RIGHT_ALT,
            &Controls::Keys::RIGHT_SUPER = LOCAL_RIGHT_SUPER,
            &Controls::Keys::MENU = LOCAL_MENU;

    std::string Controls::Keys::getName(const bool &key) {

        int keyMap = -1;

        for (int i = 0; i < GLFW_KEY_LAST + 2; i++) {
            if (keys[i] == &key)
                keyMap = i - 1;
        }

        const char *name = glfwGetKeyName(keyMap, 0);

        if (name == nullptr)
            return std::string();
        else
            return std::string(name);
    }

    static Controls::Controller LOCAL_GLFW_Controllers[GLFW_JOYSTICK_LAST + 1];

    std::list<const Controls::Controller *> LOCAL_Controllers;

    const std::list<const Controls::Controller *> &Controls::controllers(LOCAL_Controllers);

    ImGuiIO *io;

    void joystick_callback(int joy, int event) {
        if (event == GLFW_CONNECTED) {
            LOCAL_GLFW_Controllers[joy].stillConnected = true;
            LOCAL_GLFW_Controllers[joy].number = joy;
            LOCAL_GLFW_Controllers[joy].name = std::string(glfwGetJoystickName(joy));
            LOCAL_Controllers.push_back(&LOCAL_GLFW_Controllers[joy]);
        } else if (event == GLFW_DISCONNECTED) {
            LOCAL_GLFW_Controllers[joy].stillConnected = false;
            LOCAL_Controllers.remove(&LOCAL_GLFW_Controllers[joy]);
        }
    }

    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

        if (action != 2) {
            (*keys[key + 1]) = (bool) action;// BlobEngine
            io->KeysDown[key + 1] = (bool) action;// ImGUI
        }

        // ImGUI : Modifiers are not reliable across systems
        io->KeyCtrl = io->KeysDown[GLFW_KEY_LEFT_CONTROL + 1] || io->KeysDown[GLFW_KEY_RIGHT_CONTROL + 1];
        io->KeyShift = io->KeysDown[GLFW_KEY_LEFT_SHIFT + 1] || io->KeysDown[GLFW_KEY_RIGHT_SHIFT + 1];
        io->KeyAlt = io->KeysDown[GLFW_KEY_LEFT_ALT + 1] || io->KeysDown[GLFW_KEY_RIGHT_ALT + 1];
        io->KeySuper = io->KeysDown[GLFW_KEY_LEFT_SUPER + 1] || io->KeysDown[GLFW_KEY_RIGHT_SUPER + 1];
    }

    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
        io->MouseDown[button] = action != GLFW_RELEASE;
    }

    GLFWcursor *g_MouseCursors[ImGuiMouseCursor_COUNT] = {nullptr};
    int oldCursor = 0;

    void cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
        io->MousePos = Vec2f((float) xpos, (float) ypos);

        ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
        if (imgui_cursor != oldCursor) {
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

    void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
        io->MouseWheelH += (float) xoffset;
        io->MouseWheel += (float) yoffset;
    }

    void character_callback(GLFWwindow *window, unsigned int c) {
        if (c > 0 && c < 0x10000)
            io->AddInputCharacter((unsigned short) c);
    }

    const char *GetClipboardText(void *user_data) {
        return glfwGetClipboardString((GLFWwindow *) user_data);
    }

    void SetClipboardText(void *user_data, const char *text) {
        glfwSetClipboardString((GLFWwindow *) user_data, text);
    }

    void Controls::init(void *window) {
        ImGui::CreateContext();
        // keyboard init
        keys[GLFW_KEY_UNKNOWN + 1] = &LOCAL_UNKNOWN;
        keys[GLFW_KEY_SPACE + 1] = &LOCAL_SPACE;
        keys[GLFW_KEY_APOSTROPHE + 1] = &LOCAL_APOSTROPHE;
        keys[GLFW_KEY_COMMA + 1] = &LOCAL_COMMA;
        keys[GLFW_KEY_MINUS + 1] = &LOCAL_MINUS;
        keys[GLFW_KEY_PERIOD + 1] = &LOCAL_PERIOD;
        keys[GLFW_KEY_SLASH + 1] = &LOCAL_SLASH;
        keys[GLFW_KEY_0 + 1] = &LOCAL_NUM_0;
        keys[GLFW_KEY_1 + 1] = &LOCAL_NUM_1;
        keys[GLFW_KEY_2 + 1] = &LOCAL_NUM_2;
        keys[GLFW_KEY_3 + 1] = &LOCAL_NUM_3;
        keys[GLFW_KEY_4 + 1] = &LOCAL_NUM_4;
        keys[GLFW_KEY_5 + 1] = &LOCAL_NUM_5;
        keys[GLFW_KEY_6 + 1] = &LOCAL_NUM_6;
        keys[GLFW_KEY_7 + 1] = &LOCAL_NUM_7;
        keys[GLFW_KEY_8 + 1] = &LOCAL_NUM_8;
        keys[GLFW_KEY_9 + 1] = &LOCAL_NUM_9;
        keys[GLFW_KEY_SEMICOLON + 1] = &LOCAL_SEMICOLON;
        keys[GLFW_KEY_EQUAL + 1] = &LOCAL_EQUAL;
        keys[GLFW_KEY_A + 1] = &LOCAL_A;
        keys[GLFW_KEY_B + 1] = &LOCAL_B;
        keys[GLFW_KEY_C + 1] = &LOCAL_C;
        keys[GLFW_KEY_D + 1] = &LOCAL_D;
        keys[GLFW_KEY_E + 1] = &LOCAL_E;
        keys[GLFW_KEY_F + 1] = &LOCAL_F;
        keys[GLFW_KEY_G + 1] = &LOCAL_G;
        keys[GLFW_KEY_H + 1] = &LOCAL_H;
        keys[GLFW_KEY_I + 1] = &LOCAL_I;
        keys[GLFW_KEY_J + 1] = &LOCAL_J;
        keys[GLFW_KEY_K + 1] = &LOCAL_K;
        keys[GLFW_KEY_L + 1] = &LOCAL_L;
        keys[GLFW_KEY_M + 1] = &LOCAL_M;
        keys[GLFW_KEY_N + 1] = &LOCAL_N;
        keys[GLFW_KEY_O + 1] = &LOCAL_O;
        keys[GLFW_KEY_P + 1] = &LOCAL_P;
        keys[GLFW_KEY_Q + 1] = &LOCAL_Q;
        keys[GLFW_KEY_R + 1] = &LOCAL_R;
        keys[GLFW_KEY_S + 1] = &LOCAL_S;
        keys[GLFW_KEY_T + 1] = &LOCAL_T;
        keys[GLFW_KEY_U + 1] = &LOCAL_U;
        keys[GLFW_KEY_V + 1] = &LOCAL_V;
        keys[GLFW_KEY_W + 1] = &LOCAL_W;
        keys[GLFW_KEY_X + 1] = &LOCAL_X;
        keys[GLFW_KEY_Y + 1] = &LOCAL_Y;
        keys[GLFW_KEY_Z + 1] = &LOCAL_Z;
        keys[GLFW_KEY_LEFT_BRACKET + 1] = &LOCAL_LEFT_BRACKET;
        keys[GLFW_KEY_BACKSLASH + 1] = &LOCAL_BACKSLASH;
        keys[GLFW_KEY_RIGHT_BRACKET + 1] = &LOCAL_RIGHT_BRACKET;
        keys[GLFW_KEY_GRAVE_ACCENT + 1] = &LOCAL_GRAVE_ACCENT;
        keys[GLFW_KEY_WORLD_1 + 1] = &LOCAL_WORLD_1;
        keys[GLFW_KEY_WORLD_2 + 1] = &LOCAL_WORLD_2;
        keys[GLFW_KEY_ESCAPE + 1] = &LOCAL_ESCAPE;
        keys[GLFW_KEY_ENTER + 1] = &LOCAL_ENTER;
        keys[GLFW_KEY_TAB + 1] = &LOCAL_TAB;
        keys[GLFW_KEY_BACKSPACE + 1] = &LOCAL_BACKSPACE;
        keys[GLFW_KEY_INSERT + 1] = &LOCAL_INSERT;
        keys[GLFW_KEY_DELETE + 1] = &LOCAL_DELETE;
        keys[GLFW_KEY_RIGHT + 1] = &LOCAL_RIGHT;
        keys[GLFW_KEY_LEFT + 1] = &LOCAL_LEFT;
        keys[GLFW_KEY_DOWN + 1] = &LOCAL_DOWN;
        keys[GLFW_KEY_UP + 1] = &LOCAL_UP;
        keys[GLFW_KEY_PAGE_UP + 1] = &LOCAL_PAGE_UP;
        keys[GLFW_KEY_PAGE_DOWN + 1] = &LOCAL_PAGE_DOWN;
        keys[GLFW_KEY_HOME + 1] = &LOCAL_HOME;
        keys[GLFW_KEY_END + 1] = &LOCAL_END;
        keys[GLFW_KEY_CAPS_LOCK + 1] = &LOCAL_CAPS_LOCK;
        keys[GLFW_KEY_SCROLL_LOCK + 1] = &LOCAL_SCROLL_LOCK;
        keys[GLFW_KEY_NUM_LOCK + 1] = &LOCAL_NUM_LOCK;
        keys[GLFW_KEY_PRINT_SCREEN + 1] = &LOCAL_PRINT_SCREEN;
        keys[GLFW_KEY_PAUSE + 1] = &LOCAL_PAUSE;
        keys[GLFW_KEY_F1 + 1] = &LOCAL_F1;
        keys[GLFW_KEY_F2 + 1] = &LOCAL_F2;
        keys[GLFW_KEY_F3 + 1] = &LOCAL_F3;
        keys[GLFW_KEY_F4 + 1] = &LOCAL_F4;
        keys[GLFW_KEY_F5 + 1] = &LOCAL_F5;
        keys[GLFW_KEY_F6 + 1] = &LOCAL_F6;
        keys[GLFW_KEY_F7 + 1] = &LOCAL_F7;
        keys[GLFW_KEY_F8 + 1] = &LOCAL_F8;
        keys[GLFW_KEY_F9 + 1] = &LOCAL_F9;
        keys[GLFW_KEY_F10 + 1] = &LOCAL_F10;
        keys[GLFW_KEY_F11 + 1] = &LOCAL_F11;
        keys[GLFW_KEY_F12 + 1] = &LOCAL_F12;
        keys[GLFW_KEY_F13 + 1] = &LOCAL_F13;
        keys[GLFW_KEY_F14 + 1] = &LOCAL_F14;
        keys[GLFW_KEY_F15 + 1] = &LOCAL_F15;
        keys[GLFW_KEY_F16 + 1] = &LOCAL_F16;
        keys[GLFW_KEY_F17 + 1] = &LOCAL_F17;
        keys[GLFW_KEY_F18 + 1] = &LOCAL_F18;
        keys[GLFW_KEY_F19 + 1] = &LOCAL_F19;
        keys[GLFW_KEY_F20 + 1] = &LOCAL_F20;
        keys[GLFW_KEY_F21 + 1] = &LOCAL_F21;
        keys[GLFW_KEY_F22 + 1] = &LOCAL_F22;
        keys[GLFW_KEY_F23 + 1] = &LOCAL_F23;
        keys[GLFW_KEY_F24 + 1] = &LOCAL_F24;
        keys[GLFW_KEY_F25 + 1] = &LOCAL_F25;
        keys[GLFW_KEY_KP_0 + 1] = &LOCAL_KP_0;
        keys[GLFW_KEY_KP_1 + 1] = &LOCAL_KP_1;
        keys[GLFW_KEY_KP_2 + 1] = &LOCAL_KP_2;
        keys[GLFW_KEY_KP_3 + 1] = &LOCAL_KP_3;
        keys[GLFW_KEY_KP_4 + 1] = &LOCAL_KP_4;
        keys[GLFW_KEY_KP_5 + 1] = &LOCAL_KP_5;
        keys[GLFW_KEY_KP_6 + 1] = &LOCAL_KP_6;
        keys[GLFW_KEY_KP_7 + 1] = &LOCAL_KP_7;
        keys[GLFW_KEY_KP_8 + 1] = &LOCAL_KP_8;
        keys[GLFW_KEY_KP_9 + 1] = &LOCAL_KP_9;
        keys[GLFW_KEY_KP_DECIMAL + 1] = &LOCAL_KP_DECIMAL;
        keys[GLFW_KEY_KP_DIVIDE + 1] = &LOCAL_KP_DIVIDE;
        keys[GLFW_KEY_KP_MULTIPLY + 1] = &LOCAL_KP_MULTIPLY;
        keys[GLFW_KEY_KP_SUBTRACT + 1] = &LOCAL_KP_SUBTRACT;
        keys[GLFW_KEY_KP_ADD + 1] = &LOCAL_KP_ADD;
        keys[GLFW_KEY_KP_ENTER + 1] = &LOCAL_KP_ENTER;
        keys[GLFW_KEY_KP_EQUAL + 1] = &LOCAL_KP_EQUAL;
        keys[GLFW_KEY_LEFT_SHIFT + 1] = &LOCAL_LEFT_SHIFT;
        keys[GLFW_KEY_LEFT_CONTROL + 1] = &LOCAL_LEFT_CONTROL;
        keys[GLFW_KEY_LEFT_ALT + 1] = &LOCAL_LEFT_ALT;
        keys[GLFW_KEY_LEFT_SUPER + 1] = &LOCAL_LEFT_SUPER;
        keys[GLFW_KEY_RIGHT_SHIFT + 1] = &LOCAL_RIGHT_SHIFT;
        keys[GLFW_KEY_RIGHT_CONTROL + 1] = &LOCAL_RIGHT_CONTROL;
        keys[GLFW_KEY_RIGHT_ALT + 1] = &LOCAL_RIGHT_ALT;
        keys[GLFW_KEY_RIGHT_SUPER + 1] = &LOCAL_RIGHT_SUPER;
        keys[GLFW_KEY_MENU + 1] = &LOCAL_MENU;

        // ImGUI control init
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

        glfwSetKeyCallback((GLFWwindow *) window, key_callback);
        glfwSetMouseButtonCallback((GLFWwindow *) window, mouse_button_callback);
        glfwSetCursorPosCallback((GLFWwindow *) window, cursor_position_callback);
        glfwSetScrollCallback((GLFWwindow *) window, scroll_callback);
        glfwSetCharCallback((GLFWwindow *) window, character_callback);

        io->MousePos = Vec2f();

        io->SetClipboardTextFn = SetClipboardText;
        io->GetClipboardTextFn = GetClipboardText;

        // Controller init
        glfwSetJoystickCallback(joystick_callback);

        for (int i = 0; i < GLFW_JOYSTICK_LAST + 1; i++) {
            if (glfwJoystickPresent(i))
                joystick_callback(i, GLFW_CONNECTED);
        }
    }

    void Controls::update() {
        glfwPollEvents();

        // Controller buttons (must be on the windows thread
        for (auto c : LOCAL_Controllers) {
            LOCAL_GLFW_Controllers[c->number].buttons =
                    glfwGetJoystickButtons(c->number, &LOCAL_GLFW_Controllers[c->number].buttonsCount);

            LOCAL_GLFW_Controllers[c->number].joystickAxes =
                    glfwGetJoystickAxes(c->number, &LOCAL_GLFW_Controllers[c->number].joystickAxesCount);
        }
    }

    void Controls::Controller::controllerOut() const {
        ImGui::Begin(name.c_str());

        for (int i = 0; i < joystickAxesCount; i++)
            ImGui::SliderFloat(
                    (std::string("Axe :") + std::to_string(i)).c_str(),
                    (float *) &joystickAxes[i],
                    -1.0f,
                    1.0f,
                    "%.2f"
                    );

        for (int i = 0; i < buttonsCount; i++) {
            ImGui::Checkbox((std::string("B") + std::to_string(i + 1)).c_str(), (bool *) &buttons[i]);
            if((i+1)%5 != 0)
                ImGui::SameLine();
        }

        ImGui::End();
    }
}
