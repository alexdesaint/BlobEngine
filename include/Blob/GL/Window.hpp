#pragma once

#include <Blob/GL/Texture.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/Maths.inl>
#include <ostream>

namespace Blob::GL {

// TODO: Rename Window
class Window {
private:
public:
    static const int GLmajor = 4;
    static const int GLminor = 5;

    Window(void *glfwGetProcAddress, const Maths::Vec2<int> &size);
    ~Window();

    void setVAO(const VertexArrayObject &vao) const;
    void drawIndex(const void *indices, int32_t numOfIndices, uint32_t indicesType) const;
    template<typename T>
    void drawIndex(const void *indices, int32_t numOfIndices) const;
    float readPixel(const Maths::Vec2<int>& pos) const;
    void setViewport(const Maths::Vec2<int> &framebufferSize) const;
    void clear() const;

    friend std::ostream &operator<<(std::ostream &s, const Window &a);
};

template<>
void Window::drawIndex<uint8_t>(const void *indices, int32_t numOfIndices) const;

template<>
void Window::drawIndex<uint16_t>(const void *indices, int32_t numOfIndices) const;

template<>
void Window::drawIndex<uint32_t>(const void *indices, int32_t numOfIndices) const;

} // namespace Blob::GL