#include <Blob/SDL2.hpp>

#include <SDL2/SDL.h>

namespace Blob::SDL2 {

Window::Window(const Vec2<unsigned int> &windowSize, int GLmajor, int GLminor) {
    window = SDL_CreateWindow("My Title",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              windowSize.x,
                              windowSize.y,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return;
    }
}

Window::Window(const Vec2<unsigned int> &windowSize) {
    window = SDL_CreateWindow("My Title",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              windowSize.x,
                              windowSize.y,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return;
    }
}

Window::~Window() {}

bool Window::isOpen() const {}

void Window::setTitle(const std::string &name) {}

void Window::close() {}

void Window::swapBuffers() {}

std::string Window::getClipboardText() {}

void Window::setClipboardText(const std::string &text) {}

void Window::updateInputs() {}

void (*Window::getProcAddress(const char *procname))() {}

double Window::getTime() {
    return 0;
}

void Window::setCursorState(CursorState cursorState) {}

void Window::setMouseCursor(MouseCursor mouseCursor) {}
} // namespace Blob::SDL2
