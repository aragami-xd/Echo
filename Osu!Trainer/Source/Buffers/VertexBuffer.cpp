#include "VertexBuffer.h"

using namespace std;

VertexBuffer::VertexBuffer(const void* data, unsigned int size, GLenum flag /* = GL_DYNAMIC_DRAW*/)
{
	glGenBuffers(1, &vertexID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexID);
	glBufferData(GL_ARRAY_BUFFER, size, data, flag);
}

void VertexBuffer::Update(const void* data, unsigned int size, GLenum flag /* = GL_DYNAMIC_DRAW*/)
{
	glBufferData(GL_ARRAY_BUFFER, size, data, flag);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, vertexID);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &vertexID);
}