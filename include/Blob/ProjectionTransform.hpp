#pragma once

#include <glm/mat4x4.hpp>
#include <ostream>

namespace Blob::Maths {
class ProjectionTransform : public glm::mat4 {
private:
    float cameraAngle, ratio, closeRange, longRange;
    // glm::mat4 projectionMatrix;

public:

    ProjectionTransform(float cameraAngle, unsigned int width, unsigned int height, float closeRange, float longRange);

    void setRange(float _longRange, float _closeRrange);

    void setAngle(float _cameraAngle);

    void setRatio(unsigned int width, unsigned int height);

    void setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar);

    friend std::ostream &operator<<(std::ostream &out, const ProjectionTransform &vec);
};
} // namespace Blob
