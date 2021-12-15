#pragma once

#include <Blob/GL/Texture.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/GLFW.hpp>
#include <Blob/Maths.inl>
#include <ostream>

namespace Blob::GL {

class Window : public GLFW::Window {
private:
public:
    static const int GLmajor = 4;
    static const int GLminor = 5;

    Window(const Vec2<unsigned int> &windowSize,
           int GLmajor = Window::GLmajor,
           int GLminor = Window::GLminor);
    ~Window();

    void setVAO(const VertexArrayObject &vao) const;
    void setVAO(const VertexArrayObject *vao) const;
    void drawArrays(int32_t count, uint32_t offset = 0) const;
    void drawArraysInstanced(int32_t count,
                             uint32_t offset,
                             int32_t instances) const;
    void drawIndex(const void *indices,
                   int32_t numOfIndices,
                   uint32_t indicesType) const;
    template<typename T>
    void drawIndex(const void *indices, int32_t numOfIndices) const;
    void drawIndexInstanced(const void *indices,
                            int32_t numOfIndices,
                            uint32_t indicesType,
                            int32_t instances) const;
    template<typename T>
    void drawIndexInstanced(const void *indices,
                            int32_t numOfIndices,
                            int32_t instances) const;
    float readPixel(const Vec2<int> &pos) const;
    void setViewport(const Vec2<unsigned int> &framebufferSize) const;
    void clear() const;
    void enableSRGB(bool enable);

    friend std::ostream &operator<<(std::ostream &s, const Window &a);
};

template<>
void Window::drawIndex<uint8_t>(const void *indices,
                                int32_t numOfIndices) const;

template<>
void Window::drawIndex<uint16_t>(const void *indices,
                                 int32_t numOfIndices) const;

template<>
void Window::drawIndex<uint32_t>(const void *indices,
                                 int32_t numOfIndices) const;

template<>
void Window::drawIndexInstanced<uint8_t>(const void *indices,
                                         int32_t numOfIndices,
                                         int32_t instances) const;

template<>
void Window::drawIndexInstanced<uint16_t>(const void *indices,
                                          int32_t numOfIndices,
                                          int32_t instances) const;

template<>
void Window::drawIndexInstanced<uint32_t>(const void *indices,
                                          int32_t numOfIndices,
                                          int32_t instances) const;

} // namespace Blob::GL
