#include "VertexBuffer.h"

Echo::VertexBuffer::VertexBuffer(float* data, int size, GLenum flag) :
	id(0)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, data, flag);
}

void Echo::VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void Echo::VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Echo::VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &id);
}