#pragma once

#include <ostream>
#include <glm/mat4x4.hpp>

namespace Blob {
class Window;

class ViewTransform {
    friend Window;

public:
    glm::vec3 cameraPosition; /// Camera position in World Space
    glm::vec3 cameraLookAt;   /// and looks at the origin
    glm::vec3 cameraUp;       /// Head is up (set to 0,-1,0 to look upside-down)

    glm::mat4 viewMatrix;

    const float *transform;

    ViewTransform();

    void setPosition(float x, float y, float z);

    void setLookAt(float x, float y, float z);

    friend std::ostream &operator<<(std::ostream &out, const ViewTransform &vec);
};
} // namespace Blob
