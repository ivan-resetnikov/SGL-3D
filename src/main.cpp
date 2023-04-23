#include "SGL3D/sgl.hpp"

using namespace sgl;


int main() {
	render::Window window(1280, 720, "SGL window");

	float vertices[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f
	};

	render::Object triangle(vertices, "default", "default");


	while (window.opened()) {
		window.clear();

		triangle.render(window);

		window.update();
	}

	window.terminate();

	return 0;
}