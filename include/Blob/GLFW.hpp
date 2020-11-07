#pragma once

#include <Blob/Controls.hpp>
#include <Blob/Maths.inl>
#include <string>

namespace Blob::GLFW {

struct Keys {
    static const unsigned int UNKNOWN;
    static const unsigned int SPACE;
    static const unsigned int APOSTROPHE;
    static const unsigned int COMMA;
    static const unsigned int MINUS;
    static const unsigned int PERIOD;
    static const unsigned int SLASH;
    static const unsigned int Zero;
    static const unsigned int One;
    static const unsigned int Two;
    static const unsigned int Three;
    static const unsigned int Four;
    static const unsigned int Five;
    static const unsigned int Six;
    static const unsigned int Seven;
    static const unsigned int Eight;
    static const unsigned int Nine;
    static const unsigned int SEMICOLON;
    static const unsigned int EQUAL;
    static const unsigned int A;
    static const unsigned int B;
    static const unsigned int C;
    static const unsigned int D;
    static const unsigned int E;
    static const unsigned int F;
    static const unsigned int G;
    static const unsigned int H;
    static const unsigned int I;
    static const unsigned int J;
    static const unsigned int K;
    static const unsigned int L;
    static const unsigned int M;
    static const unsigned int N;
    static const unsigned int O;
    static const unsigned int P;
    static const unsigned int Q;
    static const unsigned int R;
    static const unsigned int S;
    static const unsigned int T;
    static const unsigned int U;
    static const unsigned int V;
    static const unsigned int W;
    static const unsigned int X;
    static const unsigned int Y;
    static const unsigned int Z;
    static const unsigned int LEFT_BRACKET;
    static const unsigned int BACKSLASH;
    static const unsigned int RIGHT_BRACKET;
    static const unsigned int GRAVE_ACCENT;
    static const unsigned int WORLD_1;
    static const unsigned int WORLD_2;
    static const unsigned int ESCAPE;
    static const unsigned int ENTER;
    static const unsigned int TAB;
    static const unsigned int BACKSPACE;
    static const unsigned int INSERT;
    static const unsigned int DELETE;
    static const unsigned int RIGHT;
    static const unsigned int LEFT;
    static const unsigned int DOWN;
    static const unsigned int UP;
    static const unsigned int PAGE_UP;
    static const unsigned int PAGE_DOWN;
    static const unsigned int HOME;
    static const unsigned int END;
    static const unsigned int CAPS_LOCK;
    static const unsigned int SCROLL_LOCK;
    static const unsigned int NUM_LOCK;
    static const unsigned int PRINT_SCREEN;
    static const unsigned int PAUSE;
    static const unsigned int F1;
    static const unsigned int F2;
    static const unsigned int F3;
    static const unsigned int F4;
    static const unsigned int F5;
    static const unsigned int F6;
    static const unsigned int F7;
    static const unsigned int F8;
    static const unsigned int F9;
    static const unsigned int F10;
    static const unsigned int F11;
    static const unsigned int F12;
    static const unsigned int F13;
    static const unsigned int F14;
    static const unsigned int F15;
    static const unsigned int F16;
    static const unsigned int F17;
    static const unsigned int F18;
    static const unsigned int F19;
    static const unsigned int F20;
    static const unsigned int F21;
    static const unsigned int F22;
    static const unsigned int F23;
    static const unsigned int F24;
    static const unsigned int F25;
    static const unsigned int NumericKeypadZero;
    static const unsigned int NumericKeypadOne;
    static const unsigned int NumericKeypadTwo;
    static const unsigned int NumericKeypadThree;
    static const unsigned int NumericKeypadFour;
    static const unsigned int NumericKeypadFive;
    static const unsigned int NumericKeypadSix;
    static const unsigned int NumericKeypadSeven;
    static const unsigned int NumericKeypadEight;
    static const unsigned int NumericKeypadNine;
    static const unsigned int NumericKeypadDECIMAL;
    static const unsigned int NumericKeypadDIVIDE;
    static const unsigned int NumericKeypadMULTIPLY;
    static const unsigned int NumericKeypadSUBTRACT;
    static const unsigned int NumericKeypadADD;
    static const unsigned int NumericKeypadENTER;
    static const unsigned int NumericKeypadEQUAL;
    static const unsigned int LEFT_SHIFT;
    static const unsigned int LEFT_CONTROL;
    static const unsigned int LEFT_ALT;
    static const unsigned int LEFT_SUPER;
    static const unsigned int RIGHT_SHIFT;
    static const unsigned int RIGHT_CONTROL;
    static const unsigned int RIGHT_ALT;
    static const unsigned int RIGHT_SUPER;
    static const unsigned int MENU;
};

enum MouseCursor { Arrow = 0, TextInput, ResizeAll, ResizeNS, ResizeEW, ResizeNESW, ResizeNWSE, Hand, NotAllowed, COUNT };

class Window {
private:
    void *window = nullptr;

    // Window callback
    static void errorCallback(int error, const char *description);
    static void framebufferSizeCallback(void *window, int w, int h);
    static void windowSizeCallback(void *window, int w, int h);
    static void contentScaleCallback(void *window, float w, float h);
    static void keyCallback(void *window, int key, int scancode, int action, int mods);
    static void mouseButtonCallback(void *window, int button, int action, int mods);
    static void cursorPosCallback(void *window, double xpos, double ypos);
    static void scrollCallback(void *window, double xoffset, double yoffset);
    static void charCallback(void *window, unsigned int c);
    static void joystick_callback(int joy, int event);

    // The default imputs data storage
    bool keysData[512]{false};
    bool keyCtrlData{false}, keyShiftData{false}, keyAltData{false}, keySuperData{false};

    bool mouseButtonData[5]{false};
    Maths::Vec2<float> cursorPositionData;
    float scrollOffsetWData{false}, scrollOffsetHData{false};

    // Window info data
    Maths::Vec2<int> windowSizeData;
    Maths::Vec2<int> framebufferSizeData;
    Maths::Vec2<float> contentScaleData;
    bool fullScreenData;

protected:
    // key control to update
    bool (*keys)[512] = &keysData;
    bool *keyCtrl = &keyCtrlData;
    bool *keyShift = &keyShiftData;
    bool *keyAlt = &keyAltData;
    bool *keySuper = &keySuperData;

    // Mouse Cursor
    bool (*mouseButton)[5] = &mouseButtonData;
    Maths::Vec2<float> *cursorPosition = &cursorPositionData;
    float *scrollOffsetW = &scrollOffsetWData, *scrollOffsetH = &scrollOffsetHData;

    void *cursors[MouseCursor::COUNT];

    // Controllers
    static bool joystickConnected[16];
    static const char *joystickName[16];
    static int joystickButtonsCount[16];
    static const unsigned char *joystickButtons[16];
    static int joystickAxesCount[16];
    static const float *joystickAxes[16];

    virtual void windowResized() {}

    virtual void framebufferResized() {}

    virtual void characterInput(unsigned int c) {}

    virtual void keyboardUpdate(int key, bool pressed) {};

    virtual void mouseButtonUpdate(int button, bool pressed) {};

    virtual void cursorPositionUpdate(double xpos, double ypos) {};

    virtual void scrollUpdate(double xoffset, double yoffset) {};

    // virtual void joystick_callback(int joy, int event) {};

public:
    // Window info
    const Maths::Vec2<int> &windowSize = windowSizeData;
    const Maths::Vec2<int> &framebufferSize = framebufferSizeData;
    const Maths::Vec2<float> &contentScale = contentScaleData;
    const bool &fullScreen = fullScreenData;

    Window(bool fullScreen, const Maths::Vec2<int> &windowSize, int GLmajor, int GLminor);

    ~Window();

    [[nodiscard]] bool isOpen() const;

    // [[nodiscard]] Maths::Vec2<int> getSize() const { return {width, height}; }

    Maths::Vec2<int> getFrameBufferSize();

    void setTitle(const std::string &name);

    void close();

    void swapBuffers();

    std::string getClipboardText();

    void setClipboardText(const std::string &text);

    static void updateInputs();

    static void (*getProcAddress(const char *procname))();

    static double getTime();

    void hideMouseCursor(bool hide);

    void setMouseCursor(MouseCursor mouseCursor);
};
} // namespace Blob::GLFW