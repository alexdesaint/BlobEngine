#pragma once

#include <Blob/Maths.hpp>
#include <string>

namespace Blob::GLFW {

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
    static void windowFocusCallback(void *window, int event);

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
    bool isOpenData = true;

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

    void *window = nullptr;

    // Window info
    const Vec2<unsigned int> &windowSize = windowSizeData;
    const Vec2<unsigned int> &framebufferSize = framebufferSizeData;
    const Vec2<> &contentScale = contentScaleData;
    const bool &fullScreen = fullScreenData;
    const bool &isOpen = isOpenData;

    // Controllers
    static const size_t joystickCount;
    static bool joystickConnected[];
    static const char *joystickName[];
    static int joystickButtonsCount[];
    static const unsigned char *joystickButtons[];
    static int joystickAxesCount[];
    static const float *joystickAxes[];

    static double totalTimeFlow;

    Window(Vec2<unsigned int> windowSize, std::string windowName = "BlobEngine");
    ~Window();

    void updateInputs();

    void *getNativeDisplayType();
    void *getNativeWindowHandle();

public:
    void setTitle(const std::string &name);
    static double getTime();
    const char *getClipboardText();
    void setClipboardText(const std::string &text);
    void close();

    enum CursorState { CURSOR_HIDDEN, CURSOR_NORMAL, CURSOR_DISABLED };
    void setCursorState(CursorState cursorState);
    void setMouseCursor(MouseCursor mouseCursor);
};

} // namespace Blob::GLFW
