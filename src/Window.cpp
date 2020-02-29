#include <Blob/Window.hpp>

// Blob
#include <Blob/Exception.hpp>
#include <iostream>
#include <Blob/Shapes.hpp>
#include <Blob/Controls.hpp>
#include <Blob/GL/Core.hpp>

namespace Blob {

	Window::Window(Camera &camera, bool fullScreen, unsigned int w, unsigned int h) :
			WindowCore(fullScreen, w, h),
			imGui((Shapes::init(), w), h),
			camera(camera),
			ProjectionTransform(PI / 4, w, h, 1, 100) {
		Blob::Controls::init(window);
		lastFrameTime = std::chrono::high_resolution_clock::now();
	}

	Window::~Window() {
		std::cout << "delete Shapes" << std::endl;
		Shapes::destroy();
	}

	float Window::timeF = 0;

	float Window::display() {
		GL::Core::clear();

		swapBuffers();

		auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> diff = now - lastFrameTime;
		ImGui::GetIO().DeltaTime = diff.count();
		fpsCouner = fpsCouner + diff;
		lastFrameTime = now;

		Controls::update();

		timeF = diff.count();
		return timeF;
	}

	void Window::resize(unsigned int width, unsigned int height) {
		setRatio(width, height);

		imGui.setWindowSize(width, height);

		Blob::GL::Core::setlViewport(width, height);

		WindowCore::resize(width, height);

		ImGuiIO &io = ImGui::GetIO();
		io.DisplayFramebufferScale = getFrameBufferSize() / getSize();
		io.DisplaySize = getSize();
	}

	std::array<float, 3> Window::getWorldPosition() {
		ImGuiIO &io = ImGui::GetIO();

		Vec2f mousePos = io.MousePos;
		mousePos = mousePos / getSize() * 2;
		mousePos.x = mousePos.x - 1;
		mousePos.y = 1 - mousePos.y;

		/*//Look at test
		glm::vec4 posCamera(50, 50, 15, 1);

		ImGui::Text("World pos : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
		posCamera = (projectionMatrix * viewMatrix) * posCamera;
		ImGui::Text("camera pos : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
		posCamera = posCamera / posCamera.w;
		ImGui::Text("camera rerange : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, (posCamera.z + 1) / 2);
		posCamera = glm::inverse(projectionMatrix * viewMatrix) * posCamera;
		ImGui::Text("inverse : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
		posCamera = posCamera / posCamera.w;
		ImGui::Text("inverse rerange : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
		//
		*/

		float z = Blob::Core::readPixel(Vec2f(0, -width) + io.MousePos);

		z = (z * 2) - 1;

		glm::vec4 pos(mousePos.x, mousePos.y, z, 1);

		pos = glm::inverse(projectionMatrix * camera.viewMatrix) * pos;
		pos = pos / pos.w;

		return {pos.x, pos.y, pos.z};
	}

	void Window::setCamera(Camera &camera_) {
		camera = camera_;
	}

	void Window::draw(const Renderable &renderable) {
		Core::draw(renderable.renderOptions, renderable.shaderProgram, renderable.vertexArrayObject, renderable.texture,
				   projectionPtr, camera.transform, glm::value_ptr(renderable.getModelMatrix()));
	}
}
