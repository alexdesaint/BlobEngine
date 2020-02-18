#include <Blob/ProjectionTransform.hpp>

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Blob {

    ProjectionTransform::ProjectionTransform(float cameraAngle, float ratio, float closeRange, float longRange) :
            cameraAngle(cameraAngle),
            ratio(ratio),
            closeRange(closeRange),
            longRange(longRange),
            projectionMatrix(glm::perspective(cameraAngle, ratio, closeRange, longRange)),
            transform(glm::value_ptr(projectionMatrix)) {}

    void ProjectionTransform::setRange(float _longRange, float _closeRrange) {
        longRange = _longRange;
        closeRange = _closeRrange;

        projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
    }

    void ProjectionTransform::setAngle(float _cameraAngle) {
        cameraAngle = _cameraAngle;
        projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
    }

    void ProjectionTransform::setRatio(float _ratio) {
        ratio = _ratio;
        projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
    }

    void
    ProjectionTransform::setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar) {
        projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
    }
}
