#pragma once

#include <Blob/Maths.inl>
#include <functional>
#include <list>
#include <string>
#include <unordered_map>

namespace Blob {

class Key {
public:
    const int id;
    const bool &pressed;

    explicit Key(int id, const bool (&keys)[512]) : id(id), pressed(keys[id]) {}

    explicit operator bool() const { return pressed; }
    bool operator==(const int &i) const { return i == id; }

    std::string getName() const;
};

class Keyboard {
private:
    const std::unordered_map<unsigned int, const Key *> keys;

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

    explicit Keyboard(const bool (&keys)[512]);

    const Key &operator[](unsigned int id);
};

class Window;

class KeyboardEvents {
    friend Window;

private:
    static std::list<KeyboardEvents *> subscribers;

protected:
    KeyboardEvents() { subscribers.push_back(this); }

    ~KeyboardEvents() { subscribers.remove(this); }

    virtual void keyboardUpdate(const Key &key) = 0;

public:
    KeyboardEvents(const KeyboardEvents &) = delete;
};

class KeyboardEvents2 { // TODO: move this to the Window class
    friend Window;

private:
    static std::list<KeyboardEvents2 *> subscribers;
    std::unordered_map<int, std::function<void(bool)>> callbacks;

public:
    explicit KeyboardEvents2(
        std::unordered_map<int, std::function<void(bool)>> &&callbacks) :
        callbacks(callbacks) {
        subscribers.push_back(this);
    }

    ~KeyboardEvents2() { subscribers.remove(this); }
};

class MouseEvents {
    friend Window;

private:
    static std::list<MouseEvents *> subscribers;

protected:
    MouseEvents() { subscribers.push_back(this); }

    ~MouseEvents() { subscribers.remove(this); }

    virtual void mouseButtonUpdate(int button, bool pressed) {}

    virtual void cursorPosUpdate(double xpos, double ypos) {}

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
    const char *&name;
    bool &connected;

    int &buttonsCount;
    const unsigned char *&buttons;

    int &joystickAxesCount;
    const float *&joystickAxes;

    // void controllerOut() const;
    Controller(size_t num);
};

template<unsigned int N>
class ControllerEvents {
private:
protected:
};

} // namespace Blob
