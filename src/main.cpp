/*
The MIT License (MIT)

Copyright © 2023 LowRezCat (Ivan Resetnikov)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
*/

#include "SGL3D/sgl.hpp"

using namespace sgl;


int main() {
	render::Window window(1280, 720, "SGL window");

	float vertices[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f
	};

	float indices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	object::Model3D triangle(vertices, indices, "default", "default");


	while (window.opened()) {
		window.clear();

		triangle.render(window);

		window.update();
	}

	triangle.terminate();

	window.terminate();

	return 0;
}