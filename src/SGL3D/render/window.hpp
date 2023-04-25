/*
The MIT License (MIT)

Copyright © 2023 LowRezCat (Ivan Resetnikov)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
*/

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>



namespace sgl { namespace render {


class Window {
	private:
		int mWidth, mHeight;
		const char* mTitle;

		GLFWwindow* mWindow;

		void create();

	public :
		Window(int width, int height, const char* title);

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


void Window::create() {
	// init GLFW
	if (glfwInit()) {
		// init window
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
		
		if (mWindow) {
			glfwMakeContextCurrent(mWindow);
			glewInit();

			glViewport(0, 0, mWidth, mHeight);
		}
		else {
			throw "[!] [SGL3D::RENDER::WINDOW] Failed to create context window";
		}
	}
	else {
		throw "[!] [SGL3D::GLFW] Failed to initialize GLFW";
	}
}


void Window::close() {
	glfwSetWindowShouldClose(mWindow, true);
}


void Window::terminate() {
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}


void Window::update() {
	glfwPollEvents();

	glfwGetFramebufferSize(mWindow, &mWidth, &mHeight);

	glfwSwapBuffers(mWindow);
}


bool Window::opened() {
	return !glfwWindowShouldClose(mWindow);
}


void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


}}