#include <Blob/GLFW.hpp>

// OpenGL
#include <glad/glad.h>

// glfw3
#include <GLFW/glfw3.h>

// Blob
#include <Blob/Controls.hpp>
#include <Blob/Exception.hpp>

// std
#include <iostream>

namespace Blob::GLFW {

const unsigned int Keys::UNKNOWN = GLFW_KEY_UNKNOWN + 1;
const unsigned int Keys::SPACE = GLFW_KEY_SPACE + 1;
const unsigned int Keys::APOSTROPHE = GLFW_KEY_APOSTROPHE + 1;
const unsigned int Keys::COMMA = GLFW_KEY_COMMA + 1;
const unsigned int Keys::MINUS = GLFW_KEY_MINUS + 1;
const unsigned int Keys::PERIOD = GLFW_KEY_PERIOD + 1;
const unsigned int Keys::SLASH = GLFW_KEY_SLASH + 1;
const unsigned int Keys::Zero = GLFW_KEY_0 + 1;
const unsigned int Keys::One = GLFW_KEY_1 + 1;
const unsigned int Keys::Two = GLFW_KEY_2 + 1;
const unsigned int Keys::Three = GLFW_KEY_3 + 1;
const unsigned int Keys::Four = GLFW_KEY_4 + 1;
const unsigned int Keys::Five = GLFW_KEY_5 + 1;
const unsigned int Keys::Six = GLFW_KEY_6 + 1;
const unsigned int Keys::Seven = GLFW_KEY_7 + 1;
const unsigned int Keys::Eight = GLFW_KEY_8 + 1;
const unsigned int Keys::Nine = GLFW_KEY_9 + 1;
const unsigned int Keys::SEMICOLON = GLFW_KEY_SEMICOLON + 1;
const unsigned int Keys::EQUAL = GLFW_KEY_EQUAL + 1;
const unsigned int Keys::A = GLFW_KEY_A + 1;
const unsigned int Keys::B = GLFW_KEY_B + 1;
const unsigned int Keys::C = GLFW_KEY_C + 1;
const unsigned int Keys::D = GLFW_KEY_D + 1;
const unsigned int Keys::E = GLFW_KEY_E + 1;
const unsigned int Keys::F = GLFW_KEY_F + 1;
const unsigned int Keys::G = GLFW_KEY_G + 1;
const unsigned int Keys::H = GLFW_KEY_H + 1;
const unsigned int Keys::I = GLFW_KEY_I + 1;
const unsigned int Keys::J = GLFW_KEY_J + 1;
const unsigned int Keys::K = GLFW_KEY_K + 1;
const unsigned int Keys::L = GLFW_KEY_L + 1;
const unsigned int Keys::M = GLFW_KEY_M + 1;
const unsigned int Keys::N = GLFW_KEY_N + 1;
const unsigned int Keys::O = GLFW_KEY_O + 1;
const unsigned int Keys::P = GLFW_KEY_P + 1;
const unsigned int Keys::Q = GLFW_KEY_Q + 1;
const unsigned int Keys::R = GLFW_KEY_R + 1;
const unsigned int Keys::S = GLFW_KEY_S + 1;
const unsigned int Keys::T = GLFW_KEY_T + 1;
const unsigned int Keys::U = GLFW_KEY_U + 1;
const unsigned int Keys::V = GLFW_KEY_V + 1;
const unsigned int Keys::W = GLFW_KEY_W + 1;
const unsigned int Keys::X = GLFW_KEY_X + 1;
const unsigned int Keys::Y = GLFW_KEY_Y + 1;
const unsigned int Keys::Z = GLFW_KEY_Z + 1;
const unsigned int Keys::LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET + 1;
const unsigned int Keys::BACKSLASH = GLFW_KEY_BACKSLASH + 1;
const unsigned int Keys::RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET + 1;
const unsigned int Keys::GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT + 1;
const unsigned int Keys::WORLD_1 = GLFW_KEY_WORLD_1 + 1;
const unsigned int Keys::WORLD_2 = GLFW_KEY_WORLD_2 + 1;
const unsigned int Keys::ESCAPE = GLFW_KEY_ESCAPE + 1;
const unsigned int Keys::ENTER = GLFW_KEY_ENTER + 1;
const unsigned int Keys::TAB = GLFW_KEY_TAB + 1;
const unsigned int Keys::BACKSPACE = GLFW_KEY_BACKSPACE + 1;
const unsigned int Keys::INSERT = GLFW_KEY_INSERT + 1;
const unsigned int Keys::DELETE = GLFW_KEY_DELETE + 1;
const unsigned int Keys::RIGHT = GLFW_KEY_RIGHT + 1;
const unsigned int Keys::LEFT = GLFW_KEY_LEFT + 1;
const unsigned int Keys::DOWN = GLFW_KEY_DOWN + 1;
const unsigned int Keys::UP = GLFW_KEY_UP + 1;
const unsigned int Keys::PAGE_UP = GLFW_KEY_PAGE_UP + 1;
const unsigned int Keys::PAGE_DOWN = GLFW_KEY_PAGE_DOWN + 1;
const unsigned int Keys::HOME = GLFW_KEY_HOME + 1;
const unsigned int Keys::END = GLFW_KEY_END + 1;
const unsigned int Keys::CAPS_LOCK = GLFW_KEY_CAPS_LOCK + 1;
const unsigned int Keys::SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK + 1;
const unsigned int Keys::NUM_LOCK = GLFW_KEY_NUM_LOCK + 1;
const unsigned int Keys::PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN + 1;
const unsigned int Keys::PAUSE = GLFW_KEY_PAUSE + 1;
const unsigned int Keys::F1 = GLFW_KEY_F1 + 1;
const unsigned int Keys::F2 = GLFW_KEY_F2 + 1;
const unsigned int Keys::F3 = GLFW_KEY_F3 + 1;
const unsigned int Keys::F4 = GLFW_KEY_F4 + 1;
const unsigned int Keys::F5 = GLFW_KEY_F5 + 1;
const unsigned int Keys::F6 = GLFW_KEY_F6 + 1;
const unsigned int Keys::F7 = GLFW_KEY_F7 + 1;
const unsigned int Keys::F8 = GLFW_KEY_F8 + 1;
const unsigned int Keys::F9 = GLFW_KEY_F9 + 1;
const unsigned int Keys::F10 = GLFW_KEY_F10 + 1;
const unsigned int Keys::F11 = GLFW_KEY_F11 + 1;
const unsigned int Keys::F12 = GLFW_KEY_F12 + 1;
const unsigned int Keys::F13 = GLFW_KEY_F13 + 1;
const unsigned int Keys::F14 = GLFW_KEY_F14 + 1;
const unsigned int Keys::F15 = GLFW_KEY_F15 + 1;
const unsigned int Keys::F16 = GLFW_KEY_F16 + 1;
const unsigned int Keys::F17 = GLFW_KEY_F17 + 1;
const unsigned int Keys::F18 = GLFW_KEY_F18 + 1;
const unsigned int Keys::F19 = GLFW_KEY_F19 + 1;
const unsigned int Keys::F20 = GLFW_KEY_F20 + 1;
const unsigned int Keys::F21 = GLFW_KEY_F21 + 1;
const unsigned int Keys::F22 = GLFW_KEY_F22 + 1;
const unsigned int Keys::F23 = GLFW_KEY_F23 + 1;
const unsigned int Keys::F24 = GLFW_KEY_F24 + 1;
const unsigned int Keys::F25 = GLFW_KEY_F25 + 1;
const unsigned int Keys::NumericKeypadZero = GLFW_KEY_KP_0 + 1;
const unsigned int Keys::NumericKeypadOne = GLFW_KEY_KP_1 + 1;
const unsigned int Keys::NumericKeypadTwo = GLFW_KEY_KP_2 + 1;
const unsigned int Keys::NumericKeypadThree = GLFW_KEY_KP_3 + 1;
const unsigned int Keys::NumericKeypadFour = GLFW_KEY_KP_4 + 1;
const unsigned int Keys::NumericKeypadFive = GLFW_KEY_KP_5 + 1;
const unsigned int Keys::NumericKeypadSix = GLFW_KEY_KP_6 + 1;
const unsigned int Keys::NumericKeypadSeven = GLFW_KEY_KP_7 + 1;
const unsigned int Keys::NumericKeypadEight = GLFW_KEY_KP_8 + 1;
const unsigned int Keys::NumericKeypadNine = GLFW_KEY_KP_9 + 1;
const unsigned int Keys::NumericKeypadDECIMAL = GLFW_KEY_KP_DECIMAL + 1;
const unsigned int Keys::NumericKeypadDIVIDE = GLFW_KEY_KP_DIVIDE + 1;
const unsigned int Keys::NumericKeypadMULTIPLY = GLFW_KEY_KP_MULTIPLY + 1;
const unsigned int Keys::NumericKeypadSUBTRACT = GLFW_KEY_KP_SUBTRACT + 1;
const unsigned int Keys::NumericKeypadADD = GLFW_KEY_KP_ADD + 1;
const unsigned int Keys::NumericKeypadENTER = GLFW_KEY_KP_ENTER + 1;
const unsigned int Keys::NumericKeypadEQUAL = GLFW_KEY_KP_EQUAL + 1;
const unsigned int Keys::LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT + 1;
const unsigned int Keys::LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL + 1;
const unsigned int Keys::LEFT_ALT = GLFW_KEY_LEFT_ALT + 1;
const unsigned int Keys::LEFT_SUPER = GLFW_KEY_LEFT_SUPER + 1;
const unsigned int Keys::RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT + 1;
const unsigned int Keys::RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL + 1;
const unsigned int Keys::RIGHT_ALT = GLFW_KEY_RIGHT_ALT + 1;
const unsigned int Keys::RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER + 1;
const unsigned int Keys::MENU = GLFW_KEY_MENU + 1;

bool Window::joystickConnected[GLFW_JOYSTICK_LAST + 1];
const char *Window::joystickName[GLFW_JOYSTICK_LAST + 1];
int Window::joystickButtonsCount[GLFW_JOYSTICK_LAST + 1];
const unsigned char *Window::joystickButtons[GLFW_JOYSTICK_LAST + 1];
int Window::joystickAxesCount[GLFW_JOYSTICK_LAST + 1];
const float *Window::joystickAxes[GLFW_JOYSTICK_LAST + 1];

Window::Window(bool fullScreen, const Maths::Vec2<int> &windowSize, int GLmajor, int GLminor) {
    // The OpenGL window build
    std::cout << "init Window" << std::endl;
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
        throw Core::Exception("Can't init Window");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLmajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLminor);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    glfwWindowHint(GLFW_SAMPLES, 8);

    if (fullScreen) {
        const auto *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

        window = glfwCreateWindow(windowSize.x, windowSize.y, "My Title", glfwGetPrimaryMonitor(), nullptr);
    } else
        window = glfwCreateWindow(windowSize.x, windowSize.y, "My Title", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        throw Blob::Core::Exception("Can't create window");
    }

    {
        // Framebuffer size
        int w, h;
        glfwGetFramebufferSize((GLFWwindow *) window, &w, &h);
        framebufferSizeData = {w, h};
        glfwGetWindowSize((GLFWwindow *) window, &w, &h);
        windowSizeData = {w, h};
        float fw, fh;
        glfwGetWindowContentScale((GLFWwindow *) window, &fw, &fh);
        contentScaleData = {fw, fh};
    }

    // Callback init
    glfwSetWindowUserPointer((GLFWwindow *) window, this);
    glfwSetFramebufferSizeCallback((GLFWwindow *) window, (GLFWframebuffersizefun) framebufferSizeCallback);
    glfwSetWindowSizeCallback((GLFWwindow *) window, (GLFWwindowsizefun) windowSizeCallback);
    glfwMakeContextCurrent((GLFWwindow *) window);
    glfwSwapInterval(1);

    // Cursor init
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
    glfwSetKeyCallback((GLFWwindow *) window, (GLFWkeyfun) keyCallback);
    glfwSetCharCallback((GLFWwindow *) window, (GLFWcharfun) charCallback);

    // Controller init
    glfwSetJoystickCallback(joystick_callback);

    for (int i = 0; i < GLFW_JOYSTICK_LAST + 1; i++) {
        if (glfwJoystickPresent(i))
            joystick_callback(i, GLFW_CONNECTED);
    }
}

void Window::errorCallback(int error, const char *description) {
    std::cout << "Window Error " << error << " : " << description;
}

void Window::framebufferSizeCallback(void *window, int width, int height) {
    Window &w = *reinterpret_cast<Window *>(glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.framebufferSizeData.x = width;
    w.framebufferSizeData.y = height;
    w.framebufferResized();
}

void Window::windowSizeCallback(void *window, int width, int height) {
    Window &w = *reinterpret_cast<Window *>(glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.windowSizeData.x = width;
    w.windowSizeData.y = height;
    w.windowResized();
}

void Window::contentScaleCallback(void *window, float width, float height) {
    Window &w = *reinterpret_cast<Window *>(glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.contentScaleData.x = width;
    w.contentScaleData.y = height;
}

void Window::keyCallback(void *window, int key, int scancode, int action, int mods) {
    Window &w = *reinterpret_cast<Window *>(glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    if (action != 2)
        (*w.keys)[key + 1] = action == GLFW_PRESS;

    *w.keyCtrl = (*w.keys)[Keys::LEFT_CONTROL] || (*w.keys)[Keys::RIGHT_CONTROL];
    *w.keyShift = (*w.keys)[Keys::LEFT_SHIFT] || (*w.keys)[Keys::RIGHT_SHIFT];
    *w.keyAlt = (*w.keys)[Keys::LEFT_ALT] || (*w.keys)[Keys::RIGHT_ALT];
    *w.keySuper = (*w.keys)[Keys::LEFT_SUPER] || (*w.keys)[Keys::RIGHT_SUPER];

    w.keyboardUpdate(key + 1, action == GLFW_PRESS);
}

void Window::mouseButtonCallback(void *window, int button, int action, int mods) {
    Window &w = *reinterpret_cast<Window *>(glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    if (button < 5)
        (*w.mouseButton)[button] = action != GLFW_RELEASE;

    w.mouseButtonUpdate(button, action == GLFW_PRESS);
}

void Window::cursorPosCallback(void *window, double xpos, double ypos) {
    Window &w = *reinterpret_cast<Window *>(glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.cursorPosition->x = (float) xpos;
    w.cursorPosition->y = (float) ypos;

    w.cursorPositionUpdate(xpos, ypos);
}

void Window::scrollCallback(void *window, double xoffset, double yoffset) {
    Window &w = *reinterpret_cast<Window *>(glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    *w.scrollOffsetH = (float) xoffset;
    *w.scrollOffsetW = (float) yoffset;

    w.scrollUpdate(xoffset, yoffset);
}

void Window::charCallback(void *window, unsigned int c) {
    Window &w = *reinterpret_cast<Window *>(glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.characterInput(c);
}

void Window::joystick_callback(int joy, int event) {
    if (event == GLFW_CONNECTED) {
        joystickConnected[joy] = true;
        joystickName[joy] = glfwGetJoystickName(joy);
    } else if (event == GLFW_DISCONNECTED)
        joystickConnected[joy] = false;
}

bool Window::isOpen() const {
    return !glfwWindowShouldClose((GLFWwindow *) window);
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

Maths::Vec2<int> Window::getFrameBufferSize() {
    int display_w, display_h;
    glfwGetFramebufferSize((GLFWwindow *) window, &display_w, &display_h);
    return {display_w, display_h};
}

void Window::close() {
    glfwSetWindowShouldClose((GLFWwindow *) window, GLFW_TRUE);
}

void Window::swapBuffers() {
    glfwSwapBuffers((GLFWwindow *) window);
}

std::string Window::getClipboardText() {
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
}

double Window::getTime() {
    return glfwGetTime();
}

void Window::setMouseCursor(MouseCursor mouseCursor) {
    // glfwSetInputMode((GLFWwindow *) window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetCursor((GLFWwindow *) window, (GLFWcursor *) cursors[mouseCursor]);
}

void Window::hideMouseCursor(bool hide) {
    if (hide)
        glfwSetInputMode((GLFWwindow *) window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    else
        glfwSetInputMode((GLFWwindow *) window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void (*Window::getProcAddress(const char *procname))() {
    return glfwGetProcAddress(procname);
}

} // namespace Blob::GLFW