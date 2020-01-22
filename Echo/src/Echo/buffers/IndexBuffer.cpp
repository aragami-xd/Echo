#include "IndexBuffer.h"

Echo::IndexBuffer::IndexBuffer(unsigned int* data, int verticesCount, GLenum flag) :
	id(0), count(verticesCount)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, data, flag);
}

void Echo::IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void Echo::IndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Echo::IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &id);
}