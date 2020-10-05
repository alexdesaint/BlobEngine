#include <Blob/ModelTransform.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Blob::Maths {
using namespace glm;

void ModelTransform::setModelMatrix(const std::array<float, 16> &mat) {
    *(static_cast<glm::mat4 *>(this)) = glm::make_mat4(mat.data());
}

void ModelTransform::setPosition(float x, float y, float z) {
    translateMatrix = translate(mat4(1.0f), vec3(x, y, z));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}

void ModelTransform::setPosition(const Maths::Vec2f &xy, float z) {
    translateMatrix = translate(mat4(1.0f), vec3(xy.x, xy.y, z));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}

void ModelTransform::move(float x, float y, float z) {
    translateMatrix = translate(translateMatrix, vec3(x, y, z));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}

void ModelTransform::setRotation(float r, float x, float y, float z) {
    rotateMatrix = glm::rotate(mat4(1.0f), r, vec3(x, y, z));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}

void ModelTransform::rotate(float r, float x, float y, float z) {
    rotateMatrix = glm::rotate(rotateMatrix, r, vec3(x, y, z));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}

void ModelTransform::setScale(float xyz) {
    scaleMatrix = scale(mat4(1.0f), vec3(xyz, xyz, xyz));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}

void ModelTransform::setScale(float x, float y, float z) {
    scaleMatrix = scale(mat4(1.0f), vec3(x, y, z));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}

void ModelTransform::rescale(float xyz) {
    scaleMatrix = scale(scaleMatrix, vec3(xyz, xyz, xyz));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}

void ModelTransform::rescale(float x, float y, float z) {
    scaleMatrix = scale(scaleMatrix, vec3(x, y, z));
    *(static_cast<glm::mat4 *>(this)) = translateMatrix * rotateMatrix * scaleMatrix;
}
} // namespace Blob