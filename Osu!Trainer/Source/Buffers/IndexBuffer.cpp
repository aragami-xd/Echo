#include "IndexBuffer.h"
#include "Macro.h"

using namespace std;

IndexBuffer::IndexBuffer(unsigned int* data, unsigned int indexCount) :
	count(indexCount), vertexID(0)
{
	GLCall(glGenBuffers(1, &vertexID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_DYNAMIC_DRAW));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexID));
}

void IndexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &vertexID));
}