#pragma once

// BlobEngine
#include <Blob/Renderable.hpp>
#include <Blob/ProjectionTransform.hpp>
#include <Blob/Camera.hpp>
#include <Blob/WindowCore.hpp>

// std
#include <chrono>
#include <ostream>

namespace Blob {

	class Window : public WindowCore, ProjectionTransform {
	private:
		Blob::Camera &camera;

		// time counting
		std::chrono::high_resolution_clock::time_point lastFrameTime;
		std::chrono::duration<float> fpsCouner{0};
		static float timeF;

	public:
		Window(Blob::Camera &camera, bool fullScreen, unsigned int w = 600, unsigned int h = 400);

		~Window();

		void draw(const Renderable &renderable);

		void setCamera(Camera &camera);

		float display();

		std::array<float, 3> getWorldPosition();

		void resize(unsigned int width, unsigned int height) final;
	};
}
