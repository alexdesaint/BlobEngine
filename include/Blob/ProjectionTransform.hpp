#pragma once

#include <glm/mat4x4.hpp>

namespace Blob {
    class ProjectionTransform {
    private:
        glm::mat4 projectionMatrix;
        float cameraAngle, ratio, closeRange, longRange;
    protected:
        float *transform;

        ProjectionTransform(float cameraAngle, float ratio, float closeRange, float longRange);

        void setRange(float _longRange, float _closeRrange);

        void setAngle(float _cameraAngle);

        void setRatio(float _ratio);

        void setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar);
    };
}
