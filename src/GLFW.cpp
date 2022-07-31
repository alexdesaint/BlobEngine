#include <Blob/GLFW.hpp>

//#define ENTRY_CONFIG_USE_WAYLAND 1

// glfw3
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#if __linux__ || __FreeBSD__ || __FreeBSD_kernel__ || __NetBSD__ || __OpenBSD__ || __DragonFly__
#if ENTRY_CONFIG_USE_WAYLAND
#include <wayland-egl.h>
#define GLFW_EXPOSE_NATIVE_WAYLAND
#else
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#endif
#elif __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
#define GLFW_EXPOSE_NATIVE_COCOA
#define GLFW_EXPOSE_NATIVE_NSGL
#elif _WIN32 || _WIN64
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#endif
#include <GLFW/glfw3native.h>

// Blob
#include <Blob/Exception.hpp>

// std
#include <iostream>

namespace Blob::GLFW {

const size_t Window::joystickCount = GLFW_JOYSTICK_LAST + 1;
bool Window::joystickConnected[joystickCount];
const char *Window::joystickName[joystickCount];
int Window::joystickButtonsCount[joystickCount];
const unsigned char *Window::joystickButtons[joystickCount];
int Window::joystickAxesCount[joystickCount];
const float *Window::joystickAxes[joystickCount];

double Window::totalTimeFlow = 0;

Window::Window(Vec2<unsigned int> windowSize, std::string windowName) : windowSizeData(windowSize) {
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
        throw Exception("Can't init Window");

    if (windowSize.isNull()) {
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
        windowSize = {1366, 768};
    }

    window = glfwCreateWindow(windowSize.x, windowSize.y, windowName.c_str(), nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        throw Blob::Exception("Can't create window");
    }

    {
        // Framebuffer size
        int w, h;
        glfwGetFramebufferSize((GLFWwindow *) window, &w, &h);
        framebufferSizeData = {(unsigned int) w, (unsigned int) h};
        glfwGetWindowSize((GLFWwindow *) window, &w, &h);
        windowSizeData = {(unsigned int) w, (unsigned int) h};
        float fw, fh;
        glfwGetWindowContentScale((GLFWwindow *) window, &fw, &fh);
        contentScaleData = {fw, fh};
    }

    // Callback init
    glfwSetWindowUserPointer((GLFWwindow *) window, this);
    glfwSetFramebufferSizeCallback((GLFWwindow *) window,
                                   (GLFWframebuffersizefun) framebufferSizeCallback);
    glfwSetWindowSizeCallback((GLFWwindow *) window, (GLFWwindowsizefun) windowSizeCallback);

    // Cursor init
    if (glfwRawMouseMotionSupported())
        glfwSetInputMode((GLFWwindow *) window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    GLFWerrorfun prev_error_callback = glfwSetErrorCallback(nullptr);
    cursors[MouseCursor::Arrow] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    cursors[MouseCursor::TextInput] = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
    cursors[MouseCursor::ResizeNS] = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
    cursors[MouseCursor::ResizeEW] = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
    cursors[MouseCursor::Hand] = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
    cursors[MouseCursor::ResizeAll] = glfwCreateStandardCursor(GLFW_RESIZE_ALL_CURSOR);
    cursors[MouseCursor::ResizeNESW] = glfwCreateStandardCursor(GLFW_RESIZE_NESW_CURSOR);
    cursors[MouseCursor::ResizeNWSE] = glfwCreateStandardCursor(GLFW_RESIZE_NWSE_CURSOR);
    cursors[MouseCursor::NotAllowed] = glfwCreateStandardCursor(GLFW_NOT_ALLOWED_CURSOR);
    glfwSetErrorCallback(prev_error_callback);
    glfwSetMouseButtonCallback((GLFWwindow *) window, (GLFWmousebuttonfun) mouseButtonCallback);
    glfwSetScrollCallback((GLFWwindow *) window, (GLFWscrollfun) scrollCallback);
    glfwSetCursorPosCallback((GLFWwindow *) window, (GLFWcursorposfun) cursorPosCallback);

    // Keyboard init
    // glfwSetInputMode((GLFWwindow *) window, GLFW_STICKY_KEYS, GLFW_TRUE);
    glfwSetKeyCallback((GLFWwindow *) window, (GLFWkeyfun) keyCallback);
    glfwSetCharCallback((GLFWwindow *) window, (GLFWcharfun) charCallback);

    // Controller init
    glfwSetJoystickCallback(joystick_callback);

    glfwSetWindowFocusCallback((GLFWwindow *) window, (GLFWwindowfocusfun) windowFocusCallback);

    for (int i = 0; i < GLFW_JOYSTICK_LAST + 1; i++) {
        if (glfwJoystickPresent(i))
            joystick_callback(i, GLFW_CONNECTED);
        joystickButtons[i] = glfwGetJoystickButtons(i, &joystickButtonsCount[i]);
        joystickAxes[i] = glfwGetJoystickAxes(i, &joystickAxesCount[i]);
    }
}

void Window::errorCallback(int error, const char *description) {
    std::cout << "Window Error " << error << " : " << description;
}

void Window::framebufferSizeCallback(void *window, int width, int height) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.framebufferSizeData.x = width;
    w.framebufferSizeData.y = height;
    w.framebufferResized();
}

void Window::windowSizeCallback(void *window, int width, int height) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.windowSizeData.x = width;
    w.windowSizeData.y = height;
    w.windowResized();
}

void Window::contentScaleCallback(void *window, float width, float height) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.contentScaleData.x = width;
    w.contentScaleData.y = height;
}

void Window::keyCallback(void *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_REPEAT)
        return;

    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.keysData[key] = action;

    w.keyboardUpdate(key, action);
}

void Window::mouseButtonCallback(void *window, int button, int action, int mods) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    if (button < 5)
        w.mouseButtonData[button] = action != GLFW_RELEASE;

    w.mouseButtonUpdate(button, action == GLFW_PRESS);
}

void Window::cursorPosCallback(void *window, double xpos, double ypos) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.cursorPositionData.x = (float) xpos;
    w.cursorPositionData.y = (float) ypos;

    w.cursorPositionUpdate(xpos, ypos);
}

void Window::scrollCallback(void *window, double xoffset, double yoffset) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.scrollOffsetHData = (float) xoffset;
    w.scrollOffsetWData = (float) yoffset;

    w.scrollUpdate(xoffset, yoffset);
}

void Window::charCallback(void *window, unsigned int c) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.characterInput(c);
}

void Window::joystick_callback(int joy, int event) {
    if (event == GLFW_CONNECTED) {
        joystickConnected[joy] = true;
        joystickName[joy] = glfwGetJoystickName(joy);
    } else if (event == GLFW_DISCONNECTED)
        joystickConnected[joy] = false;
}

void Window::windowFocusCallback(void *window, int c) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));
    w.windowFocusedData = c == GLFW_TRUE;
}

Window::~Window() {
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::Arrow]);
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::TextInput]);
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::ResizeNS]);
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::ResizeEW]);
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::Hand]);
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::ResizeAll]);
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::ResizeNESW]);
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::ResizeNWSE]);
    glfwDestroyCursor((GLFWcursor *) cursors[MouseCursor::NotAllowed]);

    std::cout << "destroy Window" << std::endl;
    glfwDestroyWindow((GLFWwindow *) window);
    glfwTerminate();
}

void Window::setTitle(const std::string &name) {
    glfwSetWindowTitle((GLFWwindow *) window, name.c_str());
}

void Window::close() {
    glfwSetWindowShouldClose((GLFWwindow *) window, GLFW_TRUE);
}

const char *Window::getClipboardText() {
    return glfwGetClipboardString((GLFWwindow *) window);
}

void Window::setClipboardText(const std::string &text) {
    glfwSetClipboardString((GLFWwindow *) window, text.c_str());
}

void Window::updateInputs() {
    glfwPollEvents();

    for (int i = 0; i < GLFW_JOYSTICK_LAST + 1; i++) {
        joystickButtons[i] = glfwGetJoystickButtons(i, &joystickButtonsCount[i]);
        joystickAxes[i] = glfwGetJoystickAxes(i, &joystickAxesCount[i]);
    }

    isOpenData = !glfwWindowShouldClose((GLFWwindow *) window);
    totalTimeFlow = glfwGetTime();
}

double Window::getTime() {
    return glfwGetTime();
}

void Window::setMouseCursor(MouseCursor mouseCursor) {
    glfwSetCursor((GLFWwindow *) window, (GLFWcursor *) cursors[mouseCursor]);
}

void Window::setCursorState(CursorState cursorState) {
    switch (cursorState) {
    case CURSOR_HIDDEN:
        glfwSetInputMode((GLFWwindow *) window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        break;
    case CURSOR_DISABLED:
        glfwSetInputMode((GLFWwindow *) window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        break;
    default:
        glfwSetInputMode((GLFWwindow *) window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        break;
    }
}

void *Window::getNativeDisplayType() {
#if __linux__ || __FreeBSD__ || __FreeBSD_kernel__ || __NetBSD__ || __OpenBSD__ || __DragonFly__
#if ENTRY_CONFIG_USE_WAYLAND
    return glfwGetWaylandDisplay();
#else
    return glfwGetX11Display();
#endif
#endif
    return nullptr;
}

void *Window::getNativeWindowHandle() {
#if __linux__ || __FreeBSD__ || __FreeBSD_kernel__ || __NetBSD__ || __OpenBSD__ || __DragonFly__
#if ENTRY_CONFIG_USE_WAYLAND
    wl_egl_window *win_impl = (wl_egl_window *) glfwGetWindowUserPointer((GLFWwindow *) window);
    if (!win_impl) {
        int width, height;
        glfwGetWindowSize((GLFWwindow *) window, &width, &height);
        struct wl_surface *surface =
            (struct wl_surface *) glfwGetWaylandWindow((GLFWwindow *) window);
        if (!surface)
            return nullptr;
        win_impl = wl_egl_window_create(surface, width, height);
        glfwSetWindowUserPointer((GLFWwindow *) window, (void *) (uintptr_t) win_impl);
    }
    return (void *) (uintptr_t) win_impl;
#else
    return (void *) (uintptr_t) glfwGetX11Window((GLFWwindow *) window);
#endif
#elif BX_PLATFORM_OSX
    return glfwGetCocoaWindow((GLFWwindow *) window);
#elif BX_PLATFORM_WINDOWS
    return glfwGetWin32Window((GLFWwindow *) window);
#endif
}

} // namespace Blob::GLFW
