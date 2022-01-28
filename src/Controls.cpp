#include <Blob/Controls.hpp>

// #include <imgui.h>
#include <Blob/SDL2/Controls.hpp>

namespace Blob {

std::string Key::getName() const {
    const char *name = nullptr; // SDL2GetKeyName(id - 1, 0);

    if (name == nullptr)
        return std::string();
    else
        return std::string(name);
}

Keyboard::Keyboard(const bool (&keys)[512]) :
    UNKNOWN(SDL2::Keys::UNKNOWN, keys),
    SPACE(SDL2::Keys::SPACE, keys),
    APOSTROPHE(SDL2::Keys::APOSTROPHE, keys),
    COMMA(SDL2::Keys::COMMA, keys),
    MINUS(SDL2::Keys::MINUS, keys),
    PERIOD(SDL2::Keys::PERIOD, keys),
    SLASH(SDL2::Keys::SLASH, keys),
    Zero(SDL2::Keys::Zero, keys),
    One(SDL2::Keys::One, keys),
    Two(SDL2::Keys::Two, keys),
    Three(SDL2::Keys::Three, keys),
    Four(SDL2::Keys::Four, keys),
    Five(SDL2::Keys::Five, keys),
    Six(SDL2::Keys::Six, keys),
    Seven(SDL2::Keys::Seven, keys),
    Eight(SDL2::Keys::Eight, keys),
    Nine(SDL2::Keys::Nine, keys),
    SEMICOLON(SDL2::Keys::SEMICOLON, keys),
    EQUAL(SDL2::Keys::EQUAL, keys),
    A(SDL2::Keys::A, keys),
    B(SDL2::Keys::B, keys),
    C(SDL2::Keys::C, keys),
    D(SDL2::Keys::D, keys),
    E(SDL2::Keys::E, keys),
    F(SDL2::Keys::F, keys),
    G(SDL2::Keys::G, keys),
    H(SDL2::Keys::H, keys),
    I(SDL2::Keys::I, keys),
    J(SDL2::Keys::J, keys),
    K(SDL2::Keys::K, keys),
    L(SDL2::Keys::L, keys),
    M(SDL2::Keys::M, keys),
    N(SDL2::Keys::N, keys),
    O(SDL2::Keys::O, keys),
    P(SDL2::Keys::P, keys),
    Q(SDL2::Keys::Q, keys),
    R(SDL2::Keys::R, keys),
    S(SDL2::Keys::S, keys),
    T(SDL2::Keys::T, keys),
    U(SDL2::Keys::U, keys),
    V(SDL2::Keys::V, keys),
    W(SDL2::Keys::W, keys),
    X(SDL2::Keys::X, keys),
    Y(SDL2::Keys::Y, keys),
    Z(SDL2::Keys::Z, keys),
    LEFT_BRACKET(SDL2::Keys::LEFT_BRACKET, keys),
    BACKSLASH(SDL2::Keys::BACKSLASH, keys),
    RIGHT_BRACKET(SDL2::Keys::RIGHT_BRACKET, keys),
    GRAVE_ACCENT(SDL2::Keys::GRAVE_ACCENT, keys),
    ESCAPE(SDL2::Keys::ESCAPE, keys),
    ENTER(SDL2::Keys::ENTER, keys),
    TAB(SDL2::Keys::TAB, keys),
    BACKSPACE(SDL2::Keys::BACKSPACE, keys),
    INSERT(SDL2::Keys::INSERT, keys),
    DELETE(SDL2::Keys::DEL, keys),
    RIGHT(SDL2::Keys::RIGHT, keys),
    LEFT(SDL2::Keys::LEFT, keys),
    DOWN(SDL2::Keys::DOWN, keys),
    UP(SDL2::Keys::UP, keys),
    PAGE_UP(SDL2::Keys::PAGE_UP, keys),
    PAGE_DOWN(SDL2::Keys::PAGE_DOWN, keys),
    HOME(SDL2::Keys::HOME, keys),
    END(SDL2::Keys::END, keys),
    CAPS_LOCK(SDL2::Keys::CAPS_LOCK, keys),
    SCROLL_LOCK(SDL2::Keys::SCROLL_LOCK, keys),
    NUM_LOCK(SDL2::Keys::NUM_LOCK, keys),
    PRINT_SCREEN(SDL2::Keys::PRINT_SCREEN, keys),
    PAUSE(SDL2::Keys::PAUSE, keys),
    F1(SDL2::Keys::F1, keys),
    F2(SDL2::Keys::F2, keys),
    F3(SDL2::Keys::F3, keys),
    F4(SDL2::Keys::F4, keys),
    F5(SDL2::Keys::F5, keys),
    F6(SDL2::Keys::F6, keys),
    F7(SDL2::Keys::F7, keys),
    F8(SDL2::Keys::F8, keys),
    F9(SDL2::Keys::F9, keys),
    F10(SDL2::Keys::F10, keys),
    F11(SDL2::Keys::F11, keys),
    F12(SDL2::Keys::F12, keys),
    F13(SDL2::Keys::F13, keys),
    F14(SDL2::Keys::F14, keys),
    F15(SDL2::Keys::F15, keys),
    F16(SDL2::Keys::F16, keys),
    F17(SDL2::Keys::F17, keys),
    F18(SDL2::Keys::F18, keys),
    F19(SDL2::Keys::F19, keys),
    F20(SDL2::Keys::F20, keys),
    F21(SDL2::Keys::F21, keys),
    F22(SDL2::Keys::F22, keys),
    F23(SDL2::Keys::F23, keys),
    F24(SDL2::Keys::F24, keys),
    NumericKeypadZero(SDL2::Keys::NumericKeypadZero, keys),
    NumericKeypadOne(SDL2::Keys::NumericKeypadOne, keys),
    NumericKeypadTwo(SDL2::Keys::NumericKeypadTwo, keys),
    NumericKeypadThree(SDL2::Keys::NumericKeypadThree, keys),
    NumericKeypadFour(SDL2::Keys::NumericKeypadFour, keys),
    NumericKeypadFive(SDL2::Keys::NumericKeypadFive, keys),
    NumericKeypadSix(SDL2::Keys::NumericKeypadSix, keys),
    NumericKeypadSeven(SDL2::Keys::NumericKeypadSeven, keys),
    NumericKeypadEight(SDL2::Keys::NumericKeypadEight, keys),
    NumericKeypadNine(SDL2::Keys::NumericKeypadNine, keys),
    NumericKeypadDECIMAL(SDL2::Keys::NumericKeypadDECIMAL, keys),
    NumericKeypadDIVIDE(SDL2::Keys::NumericKeypadDIVIDE, keys),
    NumericKeypadMULTIPLY(SDL2::Keys::NumericKeypadMULTIPLY, keys),
    NumericKeypadSUBTRACT(SDL2::Keys::NumericKeypadSUBTRACT, keys),
    NumericKeypadADD(SDL2::Keys::NumericKeypadADD, keys),
    NumericKeypadENTER(SDL2::Keys::NumericKeypadENTER, keys),
    NumericKeypadEQUAL(SDL2::Keys::NumericKeypadEQUAL, keys),
    LEFT_SHIFT(SDL2::Keys::LEFT_SHIFT, keys),
    LEFT_CONTROL(SDL2::Keys::LEFT_CONTROL, keys),
    LEFT_ALT(SDL2::Keys::LEFT_ALT, keys),
    LEFT_SUPER(SDL2::Keys::LEFT_SUPER, keys),
    RIGHT_SHIFT(SDL2::Keys::RIGHT_SHIFT, keys),
    RIGHT_CONTROL(SDL2::Keys::RIGHT_CONTROL, keys),
    RIGHT_ALT(SDL2::Keys::RIGHT_ALT, keys),
    RIGHT_SUPER(SDL2::Keys::RIGHT_SUPER, keys),
    MENU(SDL2::Keys::MENU, keys),
    keys{{SDL2::Keys::UNKNOWN, &UNKNOWN},
         {SDL2::Keys::SPACE, &SPACE},
         {SDL2::Keys::APOSTROPHE, &APOSTROPHE},
         {SDL2::Keys::COMMA, &COMMA},
         {SDL2::Keys::MINUS, &MINUS},
         {SDL2::Keys::PERIOD, &PERIOD},
         {SDL2::Keys::SLASH, &SLASH},
         {SDL2::Keys::Zero, &Zero},
         {SDL2::Keys::One, &One},
         {SDL2::Keys::Two, &Two},
         {SDL2::Keys::Three, &Three},
         {SDL2::Keys::Four, &Four},
         {SDL2::Keys::Five, &Five},
         {SDL2::Keys::Six, &Six},
         {SDL2::Keys::Seven, &Seven},
         {SDL2::Keys::Eight, &Eight},
         {SDL2::Keys::Nine, &Nine},
         {SDL2::Keys::SEMICOLON, &SEMICOLON},
         {SDL2::Keys::EQUAL, &EQUAL},
         {SDL2::Keys::A, &A},
         {SDL2::Keys::B, &B},
         {SDL2::Keys::C, &C},
         {SDL2::Keys::D, &D},
         {SDL2::Keys::E, &E},
         {SDL2::Keys::F, &F},
         {SDL2::Keys::G, &G},
         {SDL2::Keys::H, &H},
         {SDL2::Keys::I, &I},
         {SDL2::Keys::J, &J},
         {SDL2::Keys::K, &K},
         {SDL2::Keys::L, &L},
         {SDL2::Keys::M, &M},
         {SDL2::Keys::N, &N},
         {SDL2::Keys::O, &O},
         {SDL2::Keys::P, &P},
         {SDL2::Keys::Q, &Q},
         {SDL2::Keys::R, &R},
         {SDL2::Keys::S, &S},
         {SDL2::Keys::T, &T},
         {SDL2::Keys::U, &U},
         {SDL2::Keys::V, &V},
         {SDL2::Keys::W, &W},
         {SDL2::Keys::X, &X},
         {SDL2::Keys::Y, &Y},
         {SDL2::Keys::Z, &Z},
         {SDL2::Keys::LEFT_BRACKET, &LEFT_BRACKET},
         {SDL2::Keys::BACKSLASH, &BACKSLASH},
         {SDL2::Keys::RIGHT_BRACKET, &RIGHT_BRACKET},
         {SDL2::Keys::GRAVE_ACCENT, &GRAVE_ACCENT},
         {SDL2::Keys::ESCAPE, &ESCAPE},
         {SDL2::Keys::ENTER, &ENTER},
         {SDL2::Keys::TAB, &TAB},
         {SDL2::Keys::BACKSPACE, &BACKSPACE},
         {SDL2::Keys::INSERT, &INSERT},
         {SDL2::Keys::DEL, &DELETE},
         {SDL2::Keys::RIGHT, &RIGHT},
         {SDL2::Keys::LEFT, &LEFT},
         {SDL2::Keys::DOWN, &DOWN},
         {SDL2::Keys::UP, &UP},
         {SDL2::Keys::PAGE_UP, &PAGE_UP},
         {SDL2::Keys::PAGE_DOWN, &PAGE_DOWN},
         {SDL2::Keys::HOME, &HOME},
         {SDL2::Keys::END, &END},
         {SDL2::Keys::CAPS_LOCK, &CAPS_LOCK},
         {SDL2::Keys::SCROLL_LOCK, &SCROLL_LOCK},
         {SDL2::Keys::NUM_LOCK, &NUM_LOCK},
         {SDL2::Keys::PRINT_SCREEN, &PRINT_SCREEN},
         {SDL2::Keys::PAUSE, &PAUSE},
         {SDL2::Keys::F1, &F1},
         {SDL2::Keys::F2, &F2},
         {SDL2::Keys::F3, &F3},
         {SDL2::Keys::F4, &F4},
         {SDL2::Keys::F5, &F5},
         {SDL2::Keys::F6, &F6},
         {SDL2::Keys::F7, &F7},
         {SDL2::Keys::F8, &F8},
         {SDL2::Keys::F9, &F9},
         {SDL2::Keys::F10, &F10},
         {SDL2::Keys::F11, &F11},
         {SDL2::Keys::F12, &F12},
         {SDL2::Keys::F13, &F13},
         {SDL2::Keys::F14, &F14},
         {SDL2::Keys::F15, &F15},
         {SDL2::Keys::F16, &F16},
         {SDL2::Keys::F17, &F17},
         {SDL2::Keys::F18, &F18},
         {SDL2::Keys::F19, &F19},
         {SDL2::Keys::F20, &F20},
         {SDL2::Keys::F21, &F21},
         {SDL2::Keys::F22, &F22},
         {SDL2::Keys::F23, &F23},
         {SDL2::Keys::F24, &F24},
         {SDL2::Keys::NumericKeypadZero, &NumericKeypadZero},
         {SDL2::Keys::NumericKeypadOne, &NumericKeypadOne},
         {SDL2::Keys::NumericKeypadTwo, &NumericKeypadTwo},
         {SDL2::Keys::NumericKeypadThree, &NumericKeypadThree},
         {SDL2::Keys::NumericKeypadFour, &NumericKeypadFour},
         {SDL2::Keys::NumericKeypadFive, &NumericKeypadFive},
         {SDL2::Keys::NumericKeypadSix, &NumericKeypadSix},
         {SDL2::Keys::NumericKeypadSeven, &NumericKeypadSeven},
         {SDL2::Keys::NumericKeypadEight, &NumericKeypadEight},
         {SDL2::Keys::NumericKeypadNine, &NumericKeypadNine},
         {SDL2::Keys::NumericKeypadDECIMAL, &NumericKeypadDECIMAL},
         {SDL2::Keys::NumericKeypadDIVIDE, &NumericKeypadDIVIDE},
         {SDL2::Keys::NumericKeypadMULTIPLY, &NumericKeypadMULTIPLY},
         {SDL2::Keys::NumericKeypadSUBTRACT, &NumericKeypadSUBTRACT},
         {SDL2::Keys::NumericKeypadADD, &NumericKeypadADD},
         {SDL2::Keys::NumericKeypadENTER, &NumericKeypadENTER},
         {SDL2::Keys::NumericKeypadEQUAL, &NumericKeypadEQUAL},
         {SDL2::Keys::LEFT_SHIFT, &LEFT_SHIFT},
         {SDL2::Keys::LEFT_CONTROL, &LEFT_CONTROL},
         {SDL2::Keys::LEFT_ALT, &LEFT_ALT},
         {SDL2::Keys::LEFT_SUPER, &LEFT_SUPER},
         {SDL2::Keys::RIGHT_SHIFT, &RIGHT_SHIFT},
         {SDL2::Keys::RIGHT_CONTROL, &RIGHT_CONTROL},
         {SDL2::Keys::RIGHT_ALT, &RIGHT_ALT},
         {SDL2::Keys::RIGHT_SUPER, &RIGHT_SUPER},
         {SDL2::Keys::MENU, &MENU}} {}

const Key &Keyboard::operator[](unsigned int id) {
    auto it = keys.find(id);
    if (it == keys.end())
        return UNKNOWN;
    return *it->second;
}

std::list<KeyboardEvents *> KeyboardEvents::subscribers;
std::list<KeyboardEvents2 *> KeyboardEvents2::subscribers;
std::list<MouseEvents *> MouseEvents::subscribers;

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
// Controller::Controller(size_t num) :
//     name(SDL2::Window::joystickName[num]),
//     connected(SDL2::Window::joystickConnected[num]),
//     buttonsCount(SDL2::Window::joystickButtonsCount[num]),
//     buttons(SDL2::Window::joystickButtons[num]),
//     joystickAxesCount(SDL2::Window::joystickAxesCount[num]),
//     joystickAxes(SDL2::Window::joystickAxes[num]) {}
} // namespace Blob
