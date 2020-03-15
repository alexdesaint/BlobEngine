#pragma once

#include <Blob/Geometrie.hpp>
#include <glm/mat4x4.hpp>

namespace Blob {

class ModelTransform {
private:
    glm::mat4 modelMatrix = glm::mat4(1.f);
    glm::mat4 translateMatrix = glm::mat4(1.f); // TODO: remove to get less memory impact
    glm::mat4 rotateMatrix = glm::mat4(1.f);    // TODO: remove to get less memory impact
    glm::mat4 scaleMatrix = glm::mat4(1.f);     // TODO: remove to get less memory impact

public:
    float *model;

    ModelTransform();

    [[nodiscard]] glm::mat4 getModelMatrix() const; // TODO: get ptr instead
    void setModelMatrix(const std::array<float, 16> &mat);

    void setPosition(float x, float y, float z);
    void setPosition(const Vec2f &xy, float z);
    void move(float x, float y, float z);

    void setRotation(float r, float x, float y, float z);
    void rotate(float r, float x, float y, float z);

    void setScale(float xyz);
    void setScale(float x, float y, float z);
    void rescale(float xyz);
    void rescale(float x, float y, float z);
};
} // namespace Blob
