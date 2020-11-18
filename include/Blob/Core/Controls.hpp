#pragma once

#include <list>
#include <string>

namespace Blob::Core {

class Key {
public:
    const unsigned int id;
    const bool &pressed;
    explicit Key(unsigned int id, bool (&keys)[512]) : id(id), pressed(keys[id]) {}

    operator bool() const { return pressed; }

    [[nodiscard]] std::string getName() const;
};

class Keyboard {
public:
    const Key UNKNOWN;
    const Key SPACE;
    const Key APOSTROPHE;
    const Key COMMA;
    const Key MINUS;
    const Key PERIOD;
    const Key SLASH;
    const Key Zero;
    const Key One;
    const Key Two;
    const Key Three;
    const Key Four;
    const Key Five;
    const Key Six;
    const Key Seven;
    const Key Eight;
    const Key Nine;
    const Key SEMICOLON;
    const Key EQUAL;
    const Key A;
    const Key B;
    const Key C;
    const Key D;
    const Key E;
    const Key F;
    const Key G;
    const Key H;
    const Key I;
    const Key J;
    const Key K;
    const Key L;
    const Key M;
    const Key N;
    const Key O;
    const Key P;
    const Key Q;
    const Key R;
    const Key S;
    const Key T;
    const Key U;
    const Key V;
    const Key W;
    const Key X;
    const Key Y;
    const Key Z;
    const Key LEFT_BRACKET;
    const Key BACKSLASH;
    const Key RIGHT_BRACKET;
    const Key GRAVE_ACCENT;
    const Key WORLD_1;
    const Key WORLD_2;
    const Key ESCAPE;
    const Key ENTER;
    const Key TAB;
    const Key BACKSPACE;
    const Key INSERT;
    const Key DELETE;
    const Key RIGHT;
    const Key LEFT;
    const Key DOWN;
    const Key UP;
    const Key PAGE_UP;
    const Key PAGE_DOWN;
    const Key HOME;
    const Key END;
    const Key CAPS_LOCK;
    const Key SCROLL_LOCK;
    const Key NUM_LOCK;
    const Key PRINT_SCREEN;
    const Key PAUSE;
    const Key F1;
    const Key F2;
    const Key F3;
    const Key F4;
    const Key F5;
    const Key F6;
    const Key F7;
    const Key F8;
    const Key F9;
    const Key F10;
    const Key F11;
    const Key F12;
    const Key F13;
    const Key F14;
    const Key F15;
    const Key F16;
    const Key F17;
    const Key F18;
    const Key F19;
    const Key F20;
    const Key F21;
    const Key F22;
    const Key F23;
    const Key F24;
    const Key F25;
    const Key NumericKeypadZero;
    const Key NumericKeypadOne;
    const Key NumericKeypadTwo;
    const Key NumericKeypadThree;
    const Key NumericKeypadFour;
    const Key NumericKeypadFive;
    const Key NumericKeypadSix;
    const Key NumericKeypadSeven;
    const Key NumericKeypadEight;
    const Key NumericKeypadNine;
    const Key NumericKeypadDECIMAL;
    const Key NumericKeypadDIVIDE;
    const Key NumericKeypadMULTIPLY;
    const Key NumericKeypadSUBTRACT;
    const Key NumericKeypadADD;
    const Key NumericKeypadENTER;
    const Key NumericKeypadEQUAL;
    const Key LEFT_SHIFT;
    const Key LEFT_CONTROL;
    const Key LEFT_ALT;
    const Key LEFT_SUPER;
    const Key RIGHT_SHIFT;
    const Key RIGHT_CONTROL;
    const Key RIGHT_ALT;
    const Key RIGHT_SUPER;
    const Key MENU;

    explicit Keyboard(bool (&keys)[512]);
};

class Window;

class KeyboardEvents {
    friend Window;
private:
    static std::list<KeyboardEvents *> keyUpdates;

protected:
    KeyboardEvents() { keyUpdates.push_back(this); }

    ~KeyboardEvents() { keyUpdates.remove(this); }

    virtual void keyboardUpdate(const Keyboard &keyboard) = 0;

public:
    KeyboardEvents(const KeyboardEvents &) = delete;
};

class Controller {
public:
    std::string name;
    bool connected = false;

    int buttonsCount = 0;
    const unsigned char *buttons = nullptr;

    int joystickAxesCount = 0;
    const float *joystickAxes = nullptr;

    void controllerOut() const;
};

template <unsigned int N>
class ControllerEvents {
private:
protected:
};

} // namespace Blob::Core