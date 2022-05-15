#include <Blob/Controls.hpp>
#include <GLFW/glfw3.h>

namespace Blob {

// std::string Key::getName() const {
//     const char *name = nullptr; // glfwGetKeyName(id - 1, 0);

//     if (name == nullptr)
//         return std::string();
//     else
//         return std::string(name);
// }

const MouseKey MouseKeys::LEFT = GLFW_MOUSE_BUTTON_LEFT;
const MouseKey MouseKeys::MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE;
const MouseKey MouseKeys::RIGHT = GLFW_MOUSE_BUTTON_RIGHT;
const MouseKey MouseKeys::X1 = GLFW_MOUSE_BUTTON_4;
const MouseKey MouseKeys::X2 = GLFW_MOUSE_BUTTON_5;
const MouseKey MouseKeys::X3 = GLFW_MOUSE_BUTTON_5;
const MouseKey MouseKeys::X4 = GLFW_MOUSE_BUTTON_5;
const MouseKey MouseKeys::X5 = GLFW_MOUSE_BUTTON_5;

const Key Keys::UNKNOWN = GLFW_KEY_UNKNOWN;
const Key Keys::SPACE = GLFW_KEY_SPACE;
const Key Keys::APOSTROPHE = GLFW_KEY_APOSTROPHE;
const Key Keys::COMMA = GLFW_KEY_COMMA;
const Key Keys::MINUS = GLFW_KEY_MINUS;
const Key Keys::PERIOD = GLFW_KEY_PERIOD;
const Key Keys::SLASH = GLFW_KEY_SLASH;
const Key Keys::Zero = GLFW_KEY_0;
const Key Keys::One = GLFW_KEY_1;
const Key Keys::Two = GLFW_KEY_2;
const Key Keys::Three = GLFW_KEY_3;
const Key Keys::Four = GLFW_KEY_4;
const Key Keys::Five = GLFW_KEY_5;
const Key Keys::Six = GLFW_KEY_6;
const Key Keys::Seven = GLFW_KEY_7;
const Key Keys::Eight = GLFW_KEY_8;
const Key Keys::Nine = GLFW_KEY_9;
const Key Keys::SEMICOLON = GLFW_KEY_SEMICOLON;
const Key Keys::EQUAL = GLFW_KEY_EQUAL;
const Key Keys::A = GLFW_KEY_A;
const Key Keys::B = GLFW_KEY_B;
const Key Keys::C = GLFW_KEY_C;
const Key Keys::D = GLFW_KEY_D;
const Key Keys::E = GLFW_KEY_E;
const Key Keys::F = GLFW_KEY_F;
const Key Keys::G = GLFW_KEY_G;
const Key Keys::H = GLFW_KEY_H;
const Key Keys::I = GLFW_KEY_I;
const Key Keys::J = GLFW_KEY_J;
const Key Keys::K = GLFW_KEY_K;
const Key Keys::L = GLFW_KEY_L;
const Key Keys::M = GLFW_KEY_M;
const Key Keys::N = GLFW_KEY_N;
const Key Keys::O = GLFW_KEY_O;
const Key Keys::P = GLFW_KEY_P;
const Key Keys::Q = GLFW_KEY_Q;
const Key Keys::R = GLFW_KEY_R;
const Key Keys::S = GLFW_KEY_S;
const Key Keys::T = GLFW_KEY_T;
const Key Keys::U = GLFW_KEY_U;
const Key Keys::V = GLFW_KEY_V;
const Key Keys::W = GLFW_KEY_W;
const Key Keys::X = GLFW_KEY_X;
const Key Keys::Y = GLFW_KEY_Y;
const Key Keys::Z = GLFW_KEY_Z;
const Key Keys::LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET;
const Key Keys::BACKSLASH = GLFW_KEY_BACKSLASH;
const Key Keys::RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET;
const Key Keys::GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT;
const Key Keys::ESCAPE = GLFW_KEY_ESCAPE;
const Key Keys::ENTER = GLFW_KEY_ENTER;
const Key Keys::TAB = GLFW_KEY_TAB;
const Key Keys::BACKSPACE = GLFW_KEY_BACKSPACE;
const Key Keys::INSERT = GLFW_KEY_INSERT;
const Key Keys::DEL = GLFW_KEY_DELETE;
const Key Keys::RIGHT = GLFW_KEY_RIGHT;
const Key Keys::LEFT = GLFW_KEY_LEFT;
const Key Keys::DOWN = GLFW_KEY_DOWN;
const Key Keys::UP = GLFW_KEY_UP;
const Key Keys::PAGE_UP = GLFW_KEY_PAGE_UP;
const Key Keys::PAGE_DOWN = GLFW_KEY_PAGE_DOWN;
const Key Keys::HOME = GLFW_KEY_HOME;
const Key Keys::END = GLFW_KEY_END;
const Key Keys::CAPS_LOCK = GLFW_KEY_CAPS_LOCK;
const Key Keys::SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK;
const Key Keys::NUM_LOCK = GLFW_KEY_NUM_LOCK;
const Key Keys::PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN;
const Key Keys::PAUSE = GLFW_KEY_PAUSE;
const Key Keys::F1 = GLFW_KEY_F1;
const Key Keys::F2 = GLFW_KEY_F2;
const Key Keys::F3 = GLFW_KEY_F3;
const Key Keys::F4 = GLFW_KEY_F4;
const Key Keys::F5 = GLFW_KEY_F5;
const Key Keys::F6 = GLFW_KEY_F6;
const Key Keys::F7 = GLFW_KEY_F7;
const Key Keys::F8 = GLFW_KEY_F8;
const Key Keys::F9 = GLFW_KEY_F9;
const Key Keys::F10 = GLFW_KEY_F10;
const Key Keys::F11 = GLFW_KEY_F11;
const Key Keys::F12 = GLFW_KEY_F12;
const Key Keys::F13 = GLFW_KEY_F13;
const Key Keys::F14 = GLFW_KEY_F14;
const Key Keys::F15 = GLFW_KEY_F15;
const Key Keys::F16 = GLFW_KEY_F16;
const Key Keys::F17 = GLFW_KEY_F17;
const Key Keys::F18 = GLFW_KEY_F18;
const Key Keys::F19 = GLFW_KEY_F19;
const Key Keys::F20 = GLFW_KEY_F20;
const Key Keys::F21 = GLFW_KEY_F21;
const Key Keys::F22 = GLFW_KEY_F22;
const Key Keys::F23 = GLFW_KEY_F23;
const Key Keys::F24 = GLFW_KEY_F24;
const Key Keys::NumericKeypadZero = GLFW_KEY_KP_0;
const Key Keys::NumericKeypadOne = GLFW_KEY_KP_1;
const Key Keys::NumericKeypadTwo = GLFW_KEY_KP_2;
const Key Keys::NumericKeypadThree = GLFW_KEY_KP_3;
const Key Keys::NumericKeypadFour = GLFW_KEY_KP_4;
const Key Keys::NumericKeypadFive = GLFW_KEY_KP_5;
const Key Keys::NumericKeypadSix = GLFW_KEY_KP_6;
const Key Keys::NumericKeypadSeven = GLFW_KEY_KP_7;
const Key Keys::NumericKeypadEight = GLFW_KEY_KP_8;
const Key Keys::NumericKeypadNine = GLFW_KEY_KP_9;
const Key Keys::NumericKeypadDECIMAL = GLFW_KEY_KP_DECIMAL;
const Key Keys::NumericKeypadDIVIDE = GLFW_KEY_KP_DIVIDE;
const Key Keys::NumericKeypadMULTIPLY = GLFW_KEY_KP_MULTIPLY;
const Key Keys::NumericKeypadSUBTRACT = GLFW_KEY_KP_SUBTRACT;
const Key Keys::NumericKeypadADD = GLFW_KEY_KP_ADD;
const Key Keys::NumericKeypadENTER = GLFW_KEY_KP_ENTER;
const Key Keys::NumericKeypadEQUAL = GLFW_KEY_KP_EQUAL;
const Key Keys::LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
const Key Keys::LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
const Key Keys::LEFT_ALT = GLFW_KEY_LEFT_ALT;
const Key Keys::LEFT_SUPER = GLFW_KEY_LEFT_SUPER;
const Key Keys::RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
const Key Keys::RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
const Key Keys::RIGHT_ALT = GLFW_KEY_RIGHT_ALT;
const Key Keys::RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER;
const Key Keys::MENU = GLFW_KEY_MENU;

const GamepadKey GamepadKeys::A = GLFW_GAMEPAD_BUTTON_A;
const GamepadKey GamepadKeys::B = GLFW_GAMEPAD_BUTTON_B;
const GamepadKey GamepadKeys::X = GLFW_GAMEPAD_BUTTON_X;
const GamepadKey GamepadKeys::Y = GLFW_GAMEPAD_BUTTON_Y;
const GamepadKey GamepadKeys::LEFT_BUMPER = GLFW_GAMEPAD_BUTTON_LEFT_BUMPER;
const GamepadKey GamepadKeys::RIGHT_BUMPER = GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER;
const GamepadKey GamepadKeys::BACK = GLFW_GAMEPAD_BUTTON_BACK;
const GamepadKey GamepadKeys::START = GLFW_GAMEPAD_BUTTON_START;
const GamepadKey GamepadKeys::GUIDE = GLFW_GAMEPAD_BUTTON_GUIDE;
const GamepadKey GamepadKeys::LEFT_THUMB = GLFW_GAMEPAD_BUTTON_LEFT_THUMB;
const GamepadKey GamepadKeys::RIGHT_THUMB = GLFW_GAMEPAD_BUTTON_RIGHT_THUMB;
const GamepadKey GamepadKeys::DPAD_UP = GLFW_GAMEPAD_BUTTON_DPAD_UP;
const GamepadKey GamepadKeys::DPAD_RIGHT = GLFW_GAMEPAD_BUTTON_DPAD_RIGHT;
const GamepadKey GamepadKeys::DPAD_DOWN = GLFW_GAMEPAD_BUTTON_DPAD_DOWN;
const GamepadKey GamepadKeys::DPAD_LEFT = GLFW_GAMEPAD_BUTTON_DPAD_LEFT;
const GamepadKey GamepadKeys::CROSS = GLFW_GAMEPAD_BUTTON_CROSS;
const GamepadKey GamepadKeys::CIRCLE = GLFW_GAMEPAD_BUTTON_CIRCLE;
const GamepadKey GamepadKeys::SQUARE = GLFW_GAMEPAD_BUTTON_SQUARE;
const GamepadKey GamepadKeys::TRIANGLE = GLFW_GAMEPAD_BUTTON_TRIANGLE;

const GamepadKey GamepadAxis::leftX = GLFW_GAMEPAD_AXIS_LEFT_X;
const GamepadKey GamepadAxis::leftY = GLFW_GAMEPAD_AXIS_LEFT_Y;
const GamepadKey GamepadAxis::rightX = GLFW_GAMEPAD_AXIS_RIGHT_X;
const GamepadKey GamepadAxis::rightY = GLFW_GAMEPAD_AXIS_RIGHT_Y;
const GamepadKey GamepadAxis::leftTRIGGER = GLFW_GAMEPAD_AXIS_LEFT_TRIGGER;
const GamepadKey GamepadAxis::rightTRIGGER = GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER;

/*
void Controller::controllerOut() const {
    ImGui::Begin(name.c_str());

    for (int i = 0; i < joystickAxesCount; i++)
        ImGui::SliderFloat((std::string("Axe :") + std::to_string(i)).c_str(),
(float *) &joystickAxes[i], -1.0f, 1.0f, "%.2f");

    for (int i = 0; i < buttonsCount; i++) {
        ImGui::Checkbox((std::string("B") + std::to_string(i + 1)).c_str(),
(bool *) &buttons[i]); if ((i + 1) % 5 != 0) ImGui::SameLine();
    }

    ImGui::End();
}
*/

std::list<KeyboardEvents *> KeyboardEvents::subscribers;
std::list<MouseEvents *> MouseEvents::subscribers;

} // namespace Blob
