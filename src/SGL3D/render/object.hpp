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

#include "../shader/shader.hpp"
#include "../buffer/vao.hpp"
#include "../buffer/vbo.hpp"
#include "../buffer/ebo.hpp"



namespace sgl { namespace Model3D {


class Model3D {
	public:
		Model3D(float* vertices, float* indices, std::string vertexShaderPath, std::string fragmentShaderPath);

		void render(sgl::render::Window);
		void terminate();
};


Model3D::Model3D(float* vertices, float* indices, std::string vertexShaderPath, std::string fragmentShaderPath) {
	sgl::shader::Shader mShaderProgram(vertexShaderPath, fragmentShaderPath);

	sgl::buffer::VAO mVAO;
	mVAO.Bind();

	sgl::buffer::VBO mVBO(vertices, sizeof(vertices));
	// sgl::buffer::EBO mEBO(indices, sizeof(indices));


	mVAO.LinkVBO(mVBO, 0);

	mVAO.Unbind();
	mVBO.Unbind();
	// mEBO.Unbind();
}


void Model3D::render(sgl::render::Window) {
	mShaderProgram.Activate();
	mVAO.Bind();

	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
}

void Model3D::terminate() {
	mVAO.Delete();
	mVBO.Delete();
	// mEBO.Delete();
	mShaderProgram.Delete();
}


}}