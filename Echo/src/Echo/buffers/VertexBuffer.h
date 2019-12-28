#pragma once

#include <glad/glad.h>

class VertexBuffer
{
private:
	unsigned int id;

public:
	VertexBuffer(float* data, int count, GLenum flag = GL_STATIC_DRAW);

	void Bind();
	void Unbind();

	~VertexBuffer();
};