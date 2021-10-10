#include <Blob/GLFW.hpp>

// glfw3
#include <GLFW/glfw3.h>

// Blob
//#include <Blob/Controls.hpp>
#include <Blob/Core/Exception.hpp>

// std
#include <iostream>

namespace Blob::GLFW {

const int Keys::UNKNOWN = GLFW_KEY_UNKNOWN;
const int Keys::SPACE = GLFW_KEY_SPACE;
const int Keys::APOSTROPHE = GLFW_KEY_APOSTROPHE;
const int Keys::COMMA = GLFW_KEY_COMMA;
const int Keys::MINUS = GLFW_KEY_MINUS;
const int Keys::PERIOD = GLFW_KEY_PERIOD;
const int Keys::SLASH = GLFW_KEY_SLASH;
const int Keys::Zero = GLFW_KEY_0;
const int Keys::One = GLFW_KEY_1;
const int Keys::Two = GLFW_KEY_2;
const int Keys::Three = GLFW_KEY_3;
const int Keys::Four = GLFW_KEY_4;
const int Keys::Five = GLFW_KEY_5;
const int Keys::Six = GLFW_KEY_6;
const int Keys::Seven = GLFW_KEY_7;
const int Keys::Eight = GLFW_KEY_8;
const int Keys::Nine = GLFW_KEY_9;
const int Keys::SEMICOLON = GLFW_KEY_SEMICOLON;
const int Keys::EQUAL = GLFW_KEY_EQUAL;
const int Keys::A = GLFW_KEY_A;
const int Keys::B = GLFW_KEY_B;
const int Keys::C = GLFW_KEY_C;
const int Keys::D = GLFW_KEY_D;
const int Keys::E = GLFW_KEY_E;
const int Keys::F = GLFW_KEY_F;
const int Keys::G = GLFW_KEY_G;
const int Keys::H = GLFW_KEY_H;
const int Keys::I = GLFW_KEY_I;
const int Keys::J = GLFW_KEY_J;
const int Keys::K = GLFW_KEY_K;
const int Keys::L = GLFW_KEY_L;
const int Keys::M = GLFW_KEY_M;
const int Keys::N = GLFW_KEY_N;
const int Keys::O = GLFW_KEY_O;
const int Keys::P = GLFW_KEY_P;
const int Keys::Q = GLFW_KEY_Q;
const int Keys::R = GLFW_KEY_R;
const int Keys::S = GLFW_KEY_S;
const int Keys::T = GLFW_KEY_T;
const int Keys::U = GLFW_KEY_U;
const int Keys::V = GLFW_KEY_V;
const int Keys::W = GLFW_KEY_W;
const int Keys::X = GLFW_KEY_X;
const int Keys::Y = GLFW_KEY_Y;
const int Keys::Z = GLFW_KEY_Z;
const int Keys::LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET;
const int Keys::BACKSLASH = GLFW_KEY_BACKSLASH;
const int Keys::RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET;
const int Keys::GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT;
const int Keys::WORLD_1 = GLFW_KEY_WORLD_1;
const int Keys::WORLD_2 = GLFW_KEY_WORLD_2;
const int Keys::ESCAPE = GLFW_KEY_ESCAPE;
const int Keys::ENTER = GLFW_KEY_ENTER;
const int Keys::TAB = GLFW_KEY_TAB;
const int Keys::BACKSPACE = GLFW_KEY_BACKSPACE;
const int Keys::INSERT = GLFW_KEY_INSERT;
const int Keys::DEL = GLFW_KEY_DELETE;
const int Keys::RIGHT = GLFW_KEY_RIGHT;
const int Keys::LEFT = GLFW_KEY_LEFT;
const int Keys::DOWN = GLFW_KEY_DOWN;
const int Keys::UP = GLFW_KEY_UP;
const int Keys::PAGE_UP = GLFW_KEY_PAGE_UP;
const int Keys::PAGE_DOWN = GLFW_KEY_PAGE_DOWN;
const int Keys::HOME = GLFW_KEY_HOME;
const int Keys::END = GLFW_KEY_END;
const int Keys::CAPS_LOCK = GLFW_KEY_CAPS_LOCK;
const int Keys::SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK;
const int Keys::NUM_LOCK = GLFW_KEY_NUM_LOCK;
const int Keys::PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN;
const int Keys::PAUSE = GLFW_KEY_PAUSE;
const int Keys::F1 = GLFW_KEY_F1;
const int Keys::F2 = GLFW_KEY_F2;
const int Keys::F3 = GLFW_KEY_F3;
const int Keys::F4 = GLFW_KEY_F4;
const int Keys::F5 = GLFW_KEY_F5;
const int Keys::F6 = GLFW_KEY_F6;
const int Keys::F7 = GLFW_KEY_F7;
const int Keys::F8 = GLFW_KEY_F8;
const int Keys::F9 = GLFW_KEY_F9;
const int Keys::F10 = GLFW_KEY_F10;
const int Keys::F11 = GLFW_KEY_F11;
const int Keys::F12 = GLFW_KEY_F12;
const int Keys::F13 = GLFW_KEY_F13;
const int Keys::F14 = GLFW_KEY_F14;
const int Keys::F15 = GLFW_KEY_F15;
const int Keys::F16 = GLFW_KEY_F16;
const int Keys::F17 = GLFW_KEY_F17;
const int Keys::F18 = GLFW_KEY_F18;
const int Keys::F19 = GLFW_KEY_F19;
const int Keys::F20 = GLFW_KEY_F20;
const int Keys::F21 = GLFW_KEY_F21;
const int Keys::F22 = GLFW_KEY_F22;
const int Keys::F23 = GLFW_KEY_F23;
const int Keys::F24 = GLFW_KEY_F24;
const int Keys::F25 = GLFW_KEY_F25;
const int Keys::NumericKeypadZero = GLFW_KEY_KP_0;
const int Keys::NumericKeypadOne = GLFW_KEY_KP_1;
const int Keys::NumericKeypadTwo = GLFW_KEY_KP_2;
const int Keys::NumericKeypadThree = GLFW_KEY_KP_3;
const int Keys::NumericKeypadFour = GLFW_KEY_KP_4;
const int Keys::NumericKeypadFive = GLFW_KEY_KP_5;
const int Keys::NumericKeypadSix = GLFW_KEY_KP_6;
const int Keys::NumericKeypadSeven = GLFW_KEY_KP_7;
const int Keys::NumericKeypadEight = GLFW_KEY_KP_8;
const int Keys::NumericKeypadNine = GLFW_KEY_KP_9;
const int Keys::NumericKeypadDECIMAL = GLFW_KEY_KP_DECIMAL;
const int Keys::NumericKeypadDIVIDE = GLFW_KEY_KP_DIVIDE;
const int Keys::NumericKeypadMULTIPLY = GLFW_KEY_KP_MULTIPLY;
const int Keys::NumericKeypadSUBTRACT = GLFW_KEY_KP_SUBTRACT;
const int Keys::NumericKeypadADD = GLFW_KEY_KP_ADD;
const int Keys::NumericKeypadENTER = GLFW_KEY_KP_ENTER;
const int Keys::NumericKeypadEQUAL = GLFW_KEY_KP_EQUAL;
const int Keys::LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
const int Keys::LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
const int Keys::LEFT_ALT = GLFW_KEY_LEFT_ALT;
const int Keys::LEFT_SUPER = GLFW_KEY_LEFT_SUPER;
const int Keys::RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
const int Keys::RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
const int Keys::RIGHT_ALT = GLFW_KEY_RIGHT_ALT;
const int Keys::RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER;
const int Keys::MENU = GLFW_KEY_MENU;

const size_t Window::joystickCount = GLFW_JOYSTICK_LAST + 1;
bool Window::joystickConnected[joystickCount];
const char *Window::joystickName[joystickCount];
int Window::joystickButtonsCount[joystickCount];
const unsigned char *Window::joystickButtons[joystickCount];
int Window::joystickAxesCount[joystickCount];
const float *Window::joystickAxes[joystickCount];

double Window::totalTimeFlow = 0;

Window::Window(const Vec2<unsigned int> &windowSize, int GLmajor, int GLminor) {
    // The OpenGL window build
    std::cout << "init OpenGl Window" << std::endl;
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
        throw Exception("Can't init Window");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLmajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLminor);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    glfwWindowHint(GLFW_SAMPLES, 8);

    if (fullScreen) {
        const auto *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

        window = glfwCreateWindow(windowSize.x,
                                  windowSize.y,
                                  "My Title",
                                  glfwGetPrimaryMonitor(),
                                  nullptr);
    } else
        window = glfwCreateWindow(windowSize.x,
                                  windowSize.y,
                                  "My Title",
                                  nullptr,
                                  nullptr);

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

    glfwMakeContextCurrent((GLFWwindow *) window);
    glfwSwapInterval(1);

    initInputs();
}

Window::Window(const Vec2<unsigned int> &windowSize) {
    std::cout << "init Vulkan Window" << std::endl;
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
        throw Exception("Can't init Window");

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window =
        glfwCreateWindow(windowSize.x, windowSize.y, "My Title", NULL, NULL);

    if (!window) {
        glfwTerminate();
        throw Blob::Exception("Can't create window");
    }

    initInputs();
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

void Window::keyCallback(void *window,
                         int key,
                         int scancode,
                         int action,
                         int mods) {
    if (action == GLFW_REPEAT)
        return;

    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    (*w.keys)[key] = action;

    *w.keyCtrl =
        (*w.keys)[Keys::LEFT_CONTROL] || (*w.keys)[Keys::RIGHT_CONTROL];
    *w.keyShift = (*w.keys)[Keys::LEFT_SHIFT] || (*w.keys)[Keys::RIGHT_SHIFT];
    *w.keyAlt = (*w.keys)[Keys::LEFT_ALT] || (*w.keys)[Keys::RIGHT_ALT];
    *w.keySuper = (*w.keys)[Keys::LEFT_SUPER] || (*w.keys)[Keys::RIGHT_SUPER];

    w.keyboardUpdate(key, action);
}

void Window::mouseButtonCallback(void *window,
                                 int button,
                                 int action,
                                 int mods) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    if (button < 5)
        (*w.mouseButton)[button] = action != GLFW_RELEASE;

    w.mouseButtonUpdate(button, action == GLFW_PRESS);
}

void Window::cursorPosCallback(void *window, double xpos, double ypos) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    w.cursorPosition->x = (float) xpos;
    w.cursorPosition->y = (float) ypos;

    w.cursorPositionUpdate(xpos, ypos);
}

void Window::scrollCallback(void *window, double xoffset, double yoffset) {
    Window &w = *reinterpret_cast<Window *>(
        glfwGetWindowUserPointer(reinterpret_cast<GLFWwindow *>(window)));

    *w.scrollOffsetH = (float) xoffset;
    *w.scrollOffsetW = (float) yoffset;

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
    w.windowFocused = c == GLFW_TRUE;
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

Vec2<int> Window::getFrameBufferSize() {
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
        joystickButtons[i] =
            glfwGetJoystickButtons(i, &joystickButtonsCount[i]);
        joystickAxes[i] = glfwGetJoystickAxes(i, &joystickAxesCount[i]);
    }

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
        glfwSetInputMode((GLFWwindow *) window,
                         GLFW_CURSOR,
                         GLFW_CURSOR_HIDDEN);
        break;
    case CURSOR_DISABLED:
        glfwSetInputMode((GLFWwindow *) window,
                         GLFW_CURSOR,
                         GLFW_CURSOR_DISABLED);
        break;
    default:
        glfwSetInputMode((GLFWwindow *) window,
                         GLFW_CURSOR,
                         GLFW_CURSOR_NORMAL);
        break;
    }
}
void Window::initInputs() {
    // Callback init
    glfwSetWindowUserPointer((GLFWwindow *) window, this);
    glfwSetFramebufferSizeCallback(
        (GLFWwindow *) window,
        (GLFWframebuffersizefun) framebufferSizeCallback);
    glfwSetWindowSizeCallback((GLFWwindow *) window,
                              (GLFWwindowsizefun) windowSizeCallback);

    // Cursor init
    if (glfwRawMouseMotionSupported())
        glfwSetInputMode((GLFWwindow *) window,
                         GLFW_RAW_MOUSE_MOTION,
                         GLFW_TRUE);
    GLFWerrorfun prev_error_callback = glfwSetErrorCallback(nullptr);
    cursors[MouseCursor::Arrow] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    cursors[MouseCursor::TextInput] =
        glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
    cursors[MouseCursor::ResizeNS] =
        glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
    cursors[MouseCursor::ResizeEW] =
        glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
    cursors[MouseCursor::Hand] = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
    cursors[MouseCursor::ResizeAll] =
        glfwCreateStandardCursor(GLFW_RESIZE_ALL_CURSOR);
    cursors[MouseCursor::ResizeNESW] =
        glfwCreateStandardCursor(GLFW_RESIZE_NESW_CURSOR);
    cursors[MouseCursor::ResizeNWSE] =
        glfwCreateStandardCursor(GLFW_RESIZE_NWSE_CURSOR);
    cursors[MouseCursor::NotAllowed] =
        glfwCreateStandardCursor(GLFW_NOT_ALLOWED_CURSOR);
    glfwSetErrorCallback(prev_error_callback);
    glfwSetMouseButtonCallback((GLFWwindow *) window,
                               (GLFWmousebuttonfun) mouseButtonCallback);
    glfwSetScrollCallback((GLFWwindow *) window,
                          (GLFWscrollfun) scrollCallback);
    glfwSetCursorPosCallback((GLFWwindow *) window,
                             (GLFWcursorposfun) cursorPosCallback);

    // Keyboard init
    // glfwSetInputMode((GLFWwindow *) window, GLFW_STICKY_KEYS, GLFW_TRUE);
    glfwSetKeyCallback((GLFWwindow *) window, (GLFWkeyfun) keyCallback);
    glfwSetCharCallback((GLFWwindow *) window, (GLFWcharfun) charCallback);

    // Controller init
    glfwSetJoystickCallback(joystick_callback);

    glfwSetWindowFocusCallback((GLFWwindow *) window,
                               (GLFWwindowfocusfun) windowFocusCallback);

    for (int i = 0; i < GLFW_JOYSTICK_LAST + 1; i++) {
        if (glfwJoystickPresent(i))
            joystick_callback(i, GLFW_CONNECTED);
        joystickButtons[i] =
            glfwGetJoystickButtons(i, &joystickButtonsCount[i]);
        joystickAxes[i] = glfwGetJoystickAxes(i, &joystickAxesCount[i]);
    }
}

/*const char** Window::GetRequiredInstanceExtensions(unsigned int &count) {
    return glfwGetRequiredInstanceExtensions(&count);
}*/

void (*Window::getProcAddress(const char *procname))() {
    return glfwGetProcAddress(procname);
}

} // namespace Blob::GLFW
