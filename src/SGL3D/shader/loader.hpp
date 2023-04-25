/*
The MIT License (MIT)

Copyright © 2023 LowRezCat (Ivan Resetnikov)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
*/

#include <fstream>

#include "../error.hpp"



namespace sgl { namespace shader {


std::string defaultVertexShader = "#version 460 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";


std::string defaultFragmentShader = "#version 460 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
	"}\n\0";


std::string readFile (const char* filename) {
	std::string content;

	std::ifstream file(filename);

	if (file.is_open()) {
		while (file) {
			content += file.get();
		}
	}
	else {
		//sgl::error::throwError("[!] [SHADER::FILE] Couldn't open file \"" << filename << "\"\n");
	}

	return content;
}


}}