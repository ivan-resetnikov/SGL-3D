/*
The MIT License (MIT)

Copyright © 2023 LowRezCat (Ivan Resetnikov)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
*/

#ifndef VAO_CLASS_HPP
#define VAO_CLASS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "vbo.hpp"



namespace sgl { namespace buffer {


class VAO {
	public:
		GLuint ID;
		VAO();

		void LinkVBO(sgl::buffer::VBO& VBO1, GLuint layout);
		void Bind();
		void Unbind();
		void Delete();
};


VAO::VAO() {
	glGenVertexArrays(1, &ID);
}


void VAO::LinkVBO(sgl::buffer::VBO& VBO1, GLuint layout) {
	VBO1.Bind();

	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(layout);

	VBO1.Unbind();
}


void VAO::Bind() {
	glBindVertexArray(ID);
}


void VAO::Unbind() {
	glBindVertexArray(0);
}


void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}


}}

#endif