#pragma once

#include <Blob/Maths.inl>
#include <string>

namespace Blob::SDL2 {

enum MouseCursor {
    Arrow = 0,
    TextInput,
    ResizeAll,
    ResizeNS,
    ResizeEW,
    ResizeNESW,
    ResizeNWSE,
    Hand,
    NotAllowed,
    COUNT
};

class Window {
private:
    // The default imputs data storage
    bool keysData[512]{false};
    bool mouseButtonData[5]{false};
    Vec2<> cursorPositionData;
    float scrollOffsetWData{0}, scrollOffsetHData{0};

    // Window info data
    Vec2<unsigned int> windowSizeData;
    Vec2<unsigned int> framebufferSizeData;
    Vec2<> contentScaleData;
    bool fullScreenData = false;
    bool windowFocusedData = true;

protected:
    // key control to update
    const bool (&keys)[512] = {keysData};

    // Mouse Cursor
    const bool (&mouseButton)[5] = mouseButtonData;
    const Vec2<> &cursorPosition = cursorPositionData;
    const float &scrollOffsetW = scrollOffsetWData;
    const float &scrollOffsetH = scrollOffsetHData;

    void *cursors[MouseCursor::COUNT];

    virtual void windowResized() {}
    virtual void framebufferResized() {}

    /// Keyboard
    virtual void characterInput(unsigned int c) {}
    virtual void keyboardUpdate(int key, bool pressed) {}

    /// Mouse
    virtual void mouseButtonUpdate(int button, bool pressed) {}
    virtual void cursorPositionUpdate(double xpos, double ypos) {}
    virtual void scrollUpdate(double xoffset, double yoffset) {}
    // virtual void joystick_callback(int joy, int event) {}

public:
    void *window = nullptr;

    // Window info
    const Vec2<unsigned int> &windowSize = windowSizeData;
    const Vec2<unsigned int> &framebufferSize = framebufferSizeData;
    const Vec2<> &contentScale = contentScaleData;
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

    Window(const Vec2<unsigned int> &windowSize, int GLmajor, int GLminor);
    explicit Window(const Vec2<unsigned int> &windowSize);

    ~Window();

    bool isOpen() const;

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
} // namespace Blob::SDL2
