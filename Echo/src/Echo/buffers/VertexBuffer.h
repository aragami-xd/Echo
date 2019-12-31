#pragma once

#include <Core.h>
#include <glad/glad.h>

class ECHO_DLL VertexBuffer
{
private:
	unsigned int id;

public:
	VertexBuffer(float* data, int count, GLenum flag = GL_STATIC_DRAW);

	void Bind();
	void Unbind();

	~VertexBuffer();
};