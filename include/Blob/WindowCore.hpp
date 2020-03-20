#pragma once

#include <Blob/Geometrie.hpp>
#include <string>

namespace Blob {
class WindowCore {
private:
    void *window = nullptr;

    static void framebuffer_size_callback(void *window, int w, int h);

    static void GLFWErrorCallback(int error, const char *description);

protected:
    unsigned int width, height;
    bool quit = false;
    bool fullScreen;

    WindowCore(bool fullScreen, unsigned int width, unsigned int height);

    ~WindowCore();

public:
    [[nodiscard]] bool isOpen() const;

    Blob::Vec2f getSize() { return {(float) width, (float) height}; }

    Blob::Vec2f getFrameBufferSize();

    void setTitle(const std::string &name);

    virtual void resize(unsigned int w, unsigned int h);

    void close();

    void swapBuffers();
};
} // namespace Blob