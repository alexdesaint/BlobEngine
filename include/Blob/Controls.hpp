#pragma once

#include <Blob/Context.hpp>
#include <cstddef>
#include <functional>
#include <list>
#include <string>
#include <unordered_map>

namespace Blob {

typedef int MouseKey;
struct MouseKeys {
    static const MouseKey LEFT;
    static const MouseKey MIDDLE;
    static const MouseKey RIGHT;
    static const MouseKey X1;
    static const MouseKey X2;
    static const MouseKey X3;
    static const MouseKey X4;
    static const MouseKey X5;
};

typedef int Key;
struct Keys {
    static const Key UNKNOWN;
    static const Key SPACE;
    static const Key APOSTROPHE;
    static const Key COMMA;
    static const Key MINUS;
    static const Key PERIOD;
    static const Key SLASH;
    static const Key Zero;
    static const Key One;
    static const Key Two;
    static const Key Three;
    static const Key Four;
    static const Key Five;
    static const Key Six;
    static const Key Seven;
    static const Key Eight;
    static const Key Nine;
    static const Key SEMICOLON;
    static const Key EQUAL;
    static const Key A;
    static const Key B;
    static const Key C;
    static const Key D;
    static const Key E;
    static const Key F;
    static const Key G;
    static const Key H;
    static const Key I;
    static const Key J;
    static const Key K;
    static const Key L;
    static const Key M;
    static const Key N;
    static const Key O;
    static const Key P;
    static const Key Q;
    static const Key R;
    static const Key S;
    static const Key T;
    static const Key U;
    static const Key V;
    static const Key W;
    static const Key X;
    static const Key Y;
    static const Key Z;
    static const Key LEFT_BRACKET;
    static const Key BACKSLASH;
    static const Key RIGHT_BRACKET;
    static const Key GRAVE_ACCENT;
    static const Key ESCAPE;
    static const Key ENTER;
    static const Key TAB;
    static const Key BACKSPACE;
    static const Key INSERT;
    static const Key DEL;
    static const Key RIGHT;
    static const Key LEFT;
    static const Key DOWN;
    static const Key UP;
    static const Key PAGE_UP;
    static const Key PAGE_DOWN;
    static const Key HOME;
    static const Key END;
    static const Key CAPS_LOCK;
    static const Key SCROLL_LOCK;
    static const Key NUM_LOCK;
    static const Key PRINT_SCREEN;
    static const Key PAUSE;
    static const Key F1;
    static const Key F2;
    static const Key F3;
    static const Key F4;
    static const Key F5;
    static const Key F6;
    static const Key F7;
    static const Key F8;
    static const Key F9;
    static const Key F10;
    static const Key F11;
    static const Key F12;
    static const Key F13;
    static const Key F14;
    static const Key F15;
    static const Key F16;
    static const Key F17;
    static const Key F18;
    static const Key F19;
    static const Key F20;
    static const Key F21;
    static const Key F22;
    static const Key F23;
    static const Key F24;
    static const Key NumericKeypadZero;
    static const Key NumericKeypadOne;
    static const Key NumericKeypadTwo;
    static const Key NumericKeypadThree;
    static const Key NumericKeypadFour;
    static const Key NumericKeypadFive;
    static const Key NumericKeypadSix;
    static const Key NumericKeypadSeven;
    static const Key NumericKeypadEight;
    static const Key NumericKeypadNine;
    static const Key NumericKeypadDECIMAL;
    static const Key NumericKeypadDIVIDE;
    static const Key NumericKeypadMULTIPLY;
    static const Key NumericKeypadSUBTRACT;
    static const Key NumericKeypadADD;
    static const Key NumericKeypadENTER;
    static const Key NumericKeypadEQUAL;
    static const Key LEFT_SHIFT;
    static const Key LEFT_CONTROL;
    static const Key LEFT_ALT;
    static const Key LEFT_SUPER;
    static const Key RIGHT_SHIFT;
    static const Key RIGHT_CONTROL;
    static const Key RIGHT_ALT;
    static const Key RIGHT_SUPER;
    static const Key MENU;
};

typedef int GamepadKey;
struct GamepadKeys {
    static const GamepadKey A;
    static const GamepadKey B;
    static const GamepadKey X;
    static const GamepadKey Y;
    static const GamepadKey LEFT_BUMPER;
    static const GamepadKey RIGHT_BUMPER;
    static const GamepadKey BACK;
    static const GamepadKey START;
    static const GamepadKey GUIDE;
    static const GamepadKey LEFT_THUMB;
    static const GamepadKey RIGHT_THUMB;
    static const GamepadKey DPAD_UP;
    static const GamepadKey DPAD_RIGHT;
    static const GamepadKey DPAD_DOWN;
    static const GamepadKey DPAD_LEFT;
    static const GamepadKey CROSS;
    static const GamepadKey CIRCLE;
    static const GamepadKey SQUARE;
    static const GamepadKey TRIANGLE;
};

struct GamepadAxis {
    static const GamepadKey leftX;
    static const GamepadKey leftY;
    static const GamepadKey rightX;
    static const GamepadKey rightY;
    static const GamepadKey leftTRIGGER;
    static const GamepadKey rightTRIGGER;
};

class KeyboardEvents {
private:
    friend class Window;
    Context &context;

protected:
    KeyboardEvents(Context &context) : context(context) {
        context.keyboardEventsSubscribers.emplace(this);
    }

    ~KeyboardEvents() { context.keyboardEventsSubscribers.erase(this); }

    virtual void keyUpdate(const Key &key, const bool &state){};

public:
    KeyboardEvents(const KeyboardEvents &) = delete;
    KeyboardEvents(KeyboardEvents &&) = delete;
};

class MouseEvents {
private:
    friend class Window;
    Context &context;

protected:
    MouseEvents(Context &context) : context(context) {
        context.mouseEventsSubscribers.emplace(this);
    }

    ~MouseEvents() { context.mouseEventsSubscribers.erase(this); }

    virtual void mouseButtonUpdate(int button, bool pressed) {}

    virtual void cursorPosUpdate(const Vec2<> &screenPosition, const Vec2<> &cameraPosition) {}

    virtual void scrollUpdate(double xoffset, double yoffset) {}

public:
    MouseEvents(const MouseEvents &) = delete;
    MouseEvents(MouseEvents &&) = delete;
};

class Mouse {
public:
    const Blob::Vec2<> &position;
    const bool (&buttons)[5];
    const float &scrollOffsetW, &scrollOffsetH;

    Mouse(const Vec2<> &position,
          const float &scrollOffsetW,
          const float &scrollOffsetH,
          const bool (&buttons)[5]) :
        position(position),
        scrollOffsetW(scrollOffsetW),
        scrollOffsetH(scrollOffsetH),
        buttons(buttons) {}

    Mouse(const Mouse &) = delete;
    Mouse(Mouse &&) = delete;
};

class Controller {
public:
    std::string name;
    bool connected;

    int buttonsCount;
    const unsigned char *buttons;

    int joystickAxesCount;
    const float *joystickAxes;
};

} // namespace Blob
