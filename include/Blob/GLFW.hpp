#pragma once

#include <Blob/Core/Controls.hpp>
#include <Blob/Maths.inl>
#include <string>

namespace Blob::GLFW {

struct Keys {
    static const int UNKNOWN;
    static const int SPACE;
    static const int APOSTROPHE;
    static const int COMMA;
    static const int MINUS;
    static const int PERIOD;
    static const int SLASH;
    static const int Zero;
    static const int One;
    static const int Two;
    static const int Three;
    static const int Four;
    static const int Five;
    static const int Six;
    static const int Seven;
    static const int Eight;
    static const int Nine;
    static const int SEMICOLON;
    static const int EQUAL;
    static const int A;
    static const int B;
    static const int C;
    static const int D;
    static const int E;
    static const int F;
    static const int G;
    static const int H;
    static const int I;
    static const int J;
    static const int K;
    static const int L;
    static const int M;
    static const int N;
    static const int O;
    static const int P;
    static const int Q;
    static const int R;
    static const int S;
    static const int T;
    static const int U;
    static const int V;
    static const int W;
    static const int X;
    static const int Y;
    static const int Z;
    static const int LEFT_BRACKET;
    static const int BACKSLASH;
    static const int RIGHT_BRACKET;
    static const int GRAVE_ACCENT;
    static const int WORLD_1;
    static const int WORLD_2;
    static const int ESCAPE;
    static const int ENTER;
    static const int TAB;
    static const int BACKSPACE;
    static const int INSERT;
    static const int DEL;
    static const int RIGHT;
    static const int LEFT;
    static const int DOWN;
    static const int UP;
    static const int PAGE_UP;
    static const int PAGE_DOWN;
    static const int HOME;
    static const int END;
    static const int CAPS_LOCK;
    static const int SCROLL_LOCK;
    static const int NUM_LOCK;
    static const int PRINT_SCREEN;
    static const int PAUSE;
    static const int F1;
    static const int F2;
    static const int F3;
    static const int F4;
    static const int F5;
    static const int F6;
    static const int F7;
    static const int F8;
    static const int F9;
    static const int F10;
    static const int F11;
    static const int F12;
    static const int F13;
    static const int F14;
    static const int F15;
    static const int F16;
    static const int F17;
    static const int F18;
    static const int F19;
    static const int F20;
    static const int F21;
    static const int F22;
    static const int F23;
    static const int F24;
    static const int F25;
    static const int NumericKeypadZero;
    static const int NumericKeypadOne;
    static const int NumericKeypadTwo;
    static const int NumericKeypadThree;
    static const int NumericKeypadFour;
    static const int NumericKeypadFive;
    static const int NumericKeypadSix;
    static const int NumericKeypadSeven;
    static const int NumericKeypadEight;
    static const int NumericKeypadNine;
    static const int NumericKeypadDECIMAL;
    static const int NumericKeypadDIVIDE;
    static const int NumericKeypadMULTIPLY;
    static const int NumericKeypadSUBTRACT;
    static const int NumericKeypadADD;
    static const int NumericKeypadENTER;
    static const int NumericKeypadEQUAL;
    static const int LEFT_SHIFT;
    static const int LEFT_CONTROL;
    static const int LEFT_ALT;
    static const int LEFT_SUPER;
    static const int RIGHT_SHIFT;
    static const int RIGHT_CONTROL;
    static const int RIGHT_ALT;
    static const int RIGHT_SUPER;
    static const int MENU;
};

enum MouseCursor { Arrow = 0, TextInput, ResizeAll, ResizeNS, ResizeEW, ResizeNESW, ResizeNWSE, Hand, NotAllowed, COUNT };

class Window {
private:
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
    float scrollOffsetWData{0}, scrollOffsetHData{0};

    // Window info data
    Maths::Vec2<unsigned int> windowSizeData;
    Maths::Vec2<unsigned int> framebufferSizeData;
    Maths::Vec2<float> contentScaleData;
    bool fullScreenData;

    void initInputs();

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

    virtual void windowResized() {}

    virtual void framebufferResized() {}

    /// Keyboard
    virtual void characterInput(unsigned int c) {}
    virtual void keyboardUpdate(int key, bool pressed){};

    /// Mouse
    virtual void mouseButtonUpdate(int button, bool pressed){};
    virtual void cursorPositionUpdate(double xpos, double ypos){};
    virtual void scrollUpdate(double xoffset, double yoffset){};

    // virtual void joystick_callback(int joy, int event) {};
public:
    void *window = nullptr;

    // Window info
    const Maths::Vec2<unsigned int> &windowSize = windowSizeData;
    const Maths::Vec2<unsigned int> &framebufferSize = framebufferSizeData;
    const Maths::Vec2<float> &contentScale = contentScaleData;
    const bool &fullScreen = fullScreenData;

    // Controllers
    static const size_t joystickCount;
    static bool joystickConnected[];
    static const char *joystickName[];
    static int joystickButtonsCount[];
    static const unsigned char *joystickButtons[];
    static int joystickAxesCount[];
    static const float *joystickAxes[];

    static double totalTimeFlow;

    Window(const Maths::Vec2<unsigned int> &windowSize, int GLmajor, int GLminor);
    Window(const Maths::Vec2<unsigned int> &windowSize);

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

    enum CursorState { CURSOR_HIDDEN, CURSOR_NORMAL, CURSOR_DISABLED };
    void setCursorState(CursorState cursorState);

    void setMouseCursor(MouseCursor mouseCursor);
};
} // namespace Blob::GLFW