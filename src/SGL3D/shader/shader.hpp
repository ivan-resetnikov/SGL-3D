/*
The MIT License (MIT)

Copyright © 2023 LowRezCat (Ivan Resetnikov)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "loader.hpp"



namespace sgl { namespace shader {


class Shader {
	public:
		unsigned int ID;
		
		Shader(std::string vertexShaderPath, std::string fragmentShaderPath);

		void Activate();
		void Delete();

};


Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	// if (vertexShaderPath == "default") {
	// 	const char* vertexShaderSource = defaultVertexShader;
		
	// }
	// else {
	// 	std::string vertexShaderCode = sgl::shader::readFile(vertexShaderPath);

	// 	const char* vertexShaderSource = vertexShaderCode.c_str();
	// }

	// if (vertexShaderPath != "default") {
	// 	const char* fragmentShaderSource = defaultFragmentShader;
	// }
	// else {
	// 	std::string fragmentShaderCode = sgl::shader::readFile(fragmentShaderPath);

	// 	const char* fragmentShaderSource = fragmentShaderCode.c_str();
	// }

	const char* vertexShaderSource = defaultVertexShader;
	const char* fragmentShaderSource = defaultFragmentShader;

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);


	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);


	ID = glCreateProgram(); // TODO: fix VAO & VBO linking

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}


void Shader::Activate()
{
	glUseProgram(ID);
}


void Shader::Delete()
{
	glDeleteProgram(ID);
}

}}