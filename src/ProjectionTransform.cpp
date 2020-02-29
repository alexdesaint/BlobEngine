#include <Blob/ProjectionTransform.hpp>

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Blob {

    ProjectionTransform::ProjectionTransform(float cameraAngle, unsigned int width, unsigned int height,
											 float closeRange, float longRange) :
			cameraAngle(cameraAngle),
			ratio(width / (float) height),
			closeRange(closeRange),
			longRange(longRange),
			projectionMatrix(glm::perspective(cameraAngle, ratio, closeRange, longRange)),
			projectionPtr(glm::value_ptr(projectionMatrix)) {}

    void ProjectionTransform::setRange(float _longRange, float _closeRrange) {
        longRange = _longRange;
		closeRange = _closeRrange;

		projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
	}

	void ProjectionTransform::setAngle(float _cameraAngle) {
		cameraAngle = _cameraAngle;
		projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
	}

	void ProjectionTransform::setRatio(unsigned int width, unsigned int height) {
		ratio = width / (float) height;
		projectionMatrix = glm::perspective(cameraAngle, ratio, closeRange, longRange);
	}

	void
	ProjectionTransform::setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar) {
		projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
	}
}
