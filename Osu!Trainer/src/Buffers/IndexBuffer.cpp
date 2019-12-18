#include "IndexBuffer.h"
#include "Macro.h"

using namespace std;

IndexBuffer::IndexBuffer(unsigned int* data, unsigned int indexCount, GLenum flag /* = GL_DYNAMIC_DRAW*/) :
	count(indexCount), vertexID(0)
{
	glGenBuffers(1, &vertexID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, flag);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &vertexID);
}