#include <Blob/ViewTransform.hpp>

#include <glm/ext/matrix_transform.inl>
#include <glm/gtc/type_ptr.inl>
#include <iostream>

namespace Blob {
ViewTransform::ViewTransform()
    : cameraPosition(1, 0, 1), cameraLookAt(0, 0, 0), cameraUp(0, 0, 1), viewMatrix(glm::lookAt(cameraPosition, cameraLookAt, cameraUp)),
      transform(glm::value_ptr(viewMatrix)) {}

void ViewTransform::setPosition(float x, float y, float z) {
    cameraPosition = glm::vec3(x, y, z);

    viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
}

void ViewTransform::setLookAt(float x, float y, float z) {
    cameraLookAt = glm::vec3(x, y, z);

    viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
}

std::ostream &operator<<(std::ostream &out, const ViewTransform &vec) {
    out << "cameraPosition: " << std::endl;
    out << vec.cameraPosition.x << " " << vec.cameraPosition.y << " " << vec.cameraPosition.z << std::endl;

    out << "cameraLookAt: " << std::endl;
    out << vec.cameraLookAt.x << " " << vec.cameraLookAt.y << " " << vec.cameraLookAt.z << std::endl;

    out << "cameraUp: " << std::endl;
    out << vec.cameraUp.x << " " << vec.cameraUp.y << " " << vec.cameraUp.z << std::endl;

    out << "viewMatrix: " << std::endl;
    for (int i = 0; i < 4; i++)
        out << vec.viewMatrix[i].x << " " << vec.viewMatrix[i].y << " " << vec.viewMatrix[i].z << " " << vec.viewMatrix[i].w << std::endl;

    return out;
}
} // namespace Blob