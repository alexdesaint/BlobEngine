#pragma once

#include <glm/mat4x4.hpp>

namespace Blob {
    class ProjectionTransform {
	protected:
		float cameraAngle, ratio, closeRange, longRange;
		float *projectionPtr;
		glm::mat4 projectionMatrix;

		ProjectionTransform(float cameraAngle, unsigned int width, unsigned int height, float closeRange,
							float longRange);

		void setRange(float _longRange, float _closeRrange);

		void setAngle(float _cameraAngle);

		void setRatio(unsigned int width, unsigned int height);

		void setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar);
    };
}
