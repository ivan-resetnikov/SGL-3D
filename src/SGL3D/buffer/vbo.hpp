/*
The MIT License (MIT)

Copyright © 2023 LowRezCat (Ivan Resetnikov)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
*/

#ifndef VBO_CLASS_HPP
#define VBO_CLASS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>



namespace sgl { namespace buffer {


class VBO {
	public:
		GLuint ID;
		VBO(GLfloat* vertices, GLsizeiptr size);

		void Bind();
		void Unbind();
		void Delete();
};


VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}


void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}


void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}

}}

#endif