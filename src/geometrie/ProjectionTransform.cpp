#include <Blob/ProjectionTransform.hpp>

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.inl>

#include <iostream>

namespace Blob {

ProjectionTransform::ProjectionTransform(float cameraAngle, unsigned int width, unsigned int height, float closeRange, float longRange)
    : cameraAngle(cameraAngle), ratio(width / (float) height), closeRange(closeRange), longRange(longRange) {
    *(static_cast<glm::mat4 *>(this)) = glm::perspective(cameraAngle, ratio, closeRange, longRange);
    // projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
}

void ProjectionTransform::setRange(float _longRange, float _closeRrange) {
    longRange = _longRange;
    closeRange = _closeRrange;

    *(static_cast<glm::mat4 *>(this)) = glm::perspective(cameraAngle, ratio, closeRange, longRange);
    // projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
}

void ProjectionTransform::setAngle(float _cameraAngle) {
    cameraAngle = _cameraAngle;
    *(static_cast<glm::mat4 *>(this)) = glm::perspective(cameraAngle, ratio, closeRange, longRange);
    // projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
}

void ProjectionTransform::setRatio(unsigned int width, unsigned int height) {
    ratio = width / (float) height;
    *(static_cast<glm::mat4 *>(this)) = glm::perspective(cameraAngle, ratio, closeRange, longRange);
    // projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
}

void ProjectionTransform::setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar) {
    *(static_cast<glm::mat4 *>(this)) = glm::ortho(left, right, bottom, top, zNear, zFar);
    // projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
}

std::ostream &operator<<(std::ostream &out, const ProjectionTransform &vec) {
    out << "cameraAngle: " << vec.cameraAngle << std::endl;

    out << "ratio: " << vec.ratio << std::endl;

    out << "closeRange: " << vec.closeRange << std::endl;

    out << "longRange: " << vec.longRange << std::endl;

    out << "viewMatrix:" << std::endl;
    for (int i = 0; i < 4; i++)
        out << vec[i].x << " " << vec[i].y << " " << vec[i].z << " " << vec[i].w << std::endl;

    return out;
}
} // namespace Blob
