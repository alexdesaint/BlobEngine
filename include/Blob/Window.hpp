#pragma once

// BlobEngine
#include <Blob/Renderable.hpp>
#include <Blob/ProjectionTransform.hpp>
#include <Blob/ImGUI.hpp>

// std
#include <chrono>
#include <ostream>

namespace Blob {

    class Window : ProjectionTransform {
    private:

        bool quit = false;
        void *window;

        unsigned int width, height;

        ImGUI imGui;

        // time counting
        std::chrono::high_resolution_clock::time_point lastFrameTime;
        std::chrono::duration<float> fpsCouner{0};
        static float timeF;

        static void framebuffer_size_callback(void *window, int w, int h);

        static void GLFWErrorCallback(int error, const char *description);

        static void enableDebugCallBack();

    public:
        Window(bool fullScreen, unsigned int w, unsigned int h);

        ~Window();

        void clear();

        float display();

        void resize(unsigned int w, unsigned int h);

        Blob::Vec2f getSize() { return {(float) width, (float) height}; }

        void setTitle(const std::string &name);

        void draw(const Renderable &renderable, glm::mat4 shapeModel = glm::mat4(1.0));

        void
        draw(const Renderable &renderable, int numOfElements, uint64_t offset, glm::mat4 shapeModel = glm::mat4(1.0));

        friend std::ostream &operator<<(std::ostream &s, const Window &a);

        [[nodiscard]] bool isOpen() const;

        std::array<float, 3> getWorldPosition();

        Blob::Vec2f getFrameBufferSize();

        void close();
    };
}
