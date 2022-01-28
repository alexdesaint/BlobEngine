#include <Blob/Exception.hpp>
#include <Blob/SDL2/Window.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

namespace Blob::SDL2 {

Window::Window(const Vec2<unsigned int> &windowSize, std::string windowName) :
    windowSizeData(windowSize) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw Exception(std::string("SDL could not initialize! SDL_Error: ") +
                        SDL_GetError());

    window = SDL_CreateWindow(windowName.c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              windowSize.x,
                              windowSize.y,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        throw Exception(
            std::string("SDL could not create window! SDL_Error: ") +
            SDL_GetError());
    }
}

Window::~Window() {
    SDL_DestroyWindow((SDL_Window *) window);
    SDL_Quit();
}

void *Window::getNativeWindowHandle() {
    SDL_SysWMinfo wmi;
    SDL_VERSION(&wmi.version);
    if (!SDL_GetWindowWMInfo((SDL_Window *) window, &wmi)) {
        return nullptr;
    }
#if SDL_VIDEO_DRIVER_X11
    return (void *) wmi.info.x11.window;
#elif SDL_VIDEO_DRIVER_WAYLAND
    return wmi.info.wl.surface;
#elif SDL_VIDEO_DRIVER_COCOA
    return wmi.info.cocoa.window;
#elif SDL_VIDEO_DRIVER_WINDOWS
    return wmi.info.win.window;
#elif SDL_VIDEO_DRIVER_ANDROID
    return wmi.info.android.window;
#else
    return nullptr;
#endif
}

void *Window::getNativeDisplayType() {
    SDL_SysWMinfo wmi;
    SDL_VERSION(&wmi.version);
    if (!SDL_GetWindowWMInfo((SDL_Window *) window, &wmi)) {
        return nullptr;
    }
#if SDL_VIDEO_DRIVER_X11
    return wmi.info.x11.display;
#elif SDL_VIDEO_DRIVER_WAYLAND
    return wmi.info.wl.display;
#else
    return nullptr;
#endif
}

void Window::setTitle(const std::string &name) {}

void Window::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            isOpenData = false;
        } else if (event.type == SDL_WINDOWEVENT) {
            switch (event.window.event) {
            case SDL_WINDOWEVENT_SHOWN:
                SDL_Log("Window %d shown", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_HIDDEN:
                SDL_Log("Window %d hidden", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_EXPOSED:
                SDL_Log("Window %d exposed", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_MOVED:
                SDL_Log("Window %d moved to %d,%d",
                        event.window.windowID,
                        event.window.data1,
                        event.window.data2);
                break;
            case SDL_WINDOWEVENT_RESIZED:
                SDL_Log("Window %d resized to %dx%d",
                        event.window.windowID,
                        event.window.data1,
                        event.window.data2);
                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                SDL_Log("Window %d size changed to %dx%d",
                        event.window.windowID,
                        event.window.data1,
                        event.window.data2);
                windowSizeData.x = event.window.data1;
                windowSizeData.y = event.window.data2;
                windowResized();
                break;
            case SDL_WINDOWEVENT_MINIMIZED:
                SDL_Log("Window %d minimized", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_MAXIMIZED:
                SDL_Log("Window %d maximized", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_RESTORED:
                SDL_Log("Window %d restored", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_ENTER:
                SDL_Log("Mouse entered window %d", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_LEAVE:
                SDL_Log("Mouse left window %d", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:
                SDL_Log("Window %d gained keyboard focus",
                        event.window.windowID);
                break;
            case SDL_WINDOWEVENT_FOCUS_LOST:
                SDL_Log("Window %d lost keyboard focus", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_CLOSE:
                SDL_Log("Window %d closed", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_TAKE_FOCUS:
                SDL_Log("Window %d is offered a focus", event.window.windowID);
                break;
            case SDL_WINDOWEVENT_HIT_TEST:
                SDL_Log("Window %d has a special hit test",
                        event.window.windowID);
                break;
            default:
                SDL_Log("Window %d got unknown event %d",
                        event.window.windowID,
                        event.window.event);
                break;
            }
        }
    }
}

std::string Window::getClipboardText() {
    return "";
}

void Window::setClipboardText(const std::string &text) {}

double Window::getTime() {
    return 0;
}

void Window::setCursorState(CursorState cursorState) {}

void Window::setMouseCursor(MouseCursor mouseCursor) {}

} // namespace Blob::SDL2
