#include "VertexBuffer.h"
using namespace std;

VertexBuffer::VertexBuffer(float* data, int size, GLenum flag) :
	id(0)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, data, flag);
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &id);
}