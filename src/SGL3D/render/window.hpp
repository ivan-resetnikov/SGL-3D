#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>



namespace sgl { namespace render {

class Window{
	private:
		int mWidth, mHeight;
		const char* mTitle;

		GLFWwindow* mWindow;

		void create();

	public :
		Window(int width, int height, const char* title);
		~Window();

		void close();
		void terminate();

		bool opened();
		void update();

		void clear();
		void resize();
};



Window::Window(int width, int height, const char* title) {
	mWidth = width;
	mHeight = height;
	mTitle = title;
	create();
}


Window::~Window() {

}


void Window::create () {
	// init GLFW
	if (glfwInit()) {
		// init window
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
		
		if (mWindow) {
			glfwMakeContextCurrent(mWindow);
			glfwSetWindowSizeCallback(mWindow, resize);

			glewInit();

			glViewport(0, 0, mWidth, mHeight);
		}
		else {
			throw "";
		}
	}
	else {
		throw "";
	}
}


void Window::close () {
	glfwSetWindowShouldClose(mWindow, true);
}


void Window::terminate () {
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}


void Window::update () {
	glfwPollEvents();

	glfwGetFramebufferSize(mWindow, &mWidth, &mHeight);
	

	glfwSwapBuffers(mWindow);
}


bool Window::opened () {
	return !glfwWindowShouldClose(mWindow);
}


void Window::clear () {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


}}