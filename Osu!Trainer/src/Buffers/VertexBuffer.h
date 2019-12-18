#pragma once
#include <GL/glew.h>

class VertexBuffer
{
private:
	unsigned int vertexID;
public:
	VertexBuffer(const void* data, unsigned int size, GLenum flag = GL_DYNAMIC_DRAW);

	void Update(const void* data, unsigned int size, GLenum flag = GL_DYNAMIC_DRAW);
	void Bind() const;
	void Unbind() const;

	~VertexBuffer();
};
