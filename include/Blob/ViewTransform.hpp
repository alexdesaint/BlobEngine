#pragma once

#include <glm/ext/matrix_transform.inl>
#include <glm/gtc/type_ptr.inl>

namespace Blob {
    class ViewTransform {
    private:
        glm::mat4 viewMatrix;

        glm::vec3 cameraPosition; /// Camera position in World Space
        glm::vec3 cameraLookAt; /// and looks at the origin
        glm::vec3 cameraUp;  /// Head is up (set to 0,-1,0 to look upside-down)
    public:
        float *transform;

        ViewTransform() :
                cameraPosition(0, 0, 2),
                cameraLookAt(0, 0, 0),
                cameraUp(0, 0, 1),
                viewMatrix(glm::lookAt(cameraPosition, cameraLookAt, cameraUp)),
                transform(glm::value_ptr(viewMatrix)) {}


        void setPosition(float x, float y, float z) {
            cameraPosition = glm::vec3(x, y, z);

            viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
        }

        void setLookAt(float x, float y, float z) {
            cameraLookAt = glm::vec3(x, y, z);

            viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
        }
    };
}
