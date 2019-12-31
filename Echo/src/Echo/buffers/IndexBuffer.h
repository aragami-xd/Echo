#pragma once

#include <Core.h>
#include <glad/glad.h>

class ECHO_DLL IndexBuffer
{
private:
	unsigned int id;
	unsigned int count;
public:
	IndexBuffer(unsigned int* data, int count, GLenum flag = GL_STATIC_DRAW);

	void Bind();
	void Unbind();

	inline unsigned int GetCount() { return count; }

	~IndexBuffer();
};