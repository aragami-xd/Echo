#include "VertexBuffer.h"
#include "Macro.h"
#include <GL/glew.h>

using namespace std;

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &vertexID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vertexID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
}

void VertexBuffer::Update(const void* data, unsigned int size)
{
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vertexID));
}

void VertexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &vertexID));
}