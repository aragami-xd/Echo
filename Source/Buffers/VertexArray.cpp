#include "VertexArray.h"

using namespace std;

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &elementID);
}

void VertexArray::AddBuffer(VertexBuffer& vb, VertexBufferLayout& vbl)
{
	Bind();
	vb.Bind();
	const auto& elements = vbl.GetElement();
	unsigned int offset = 0;

	for (int i = 0; i < elements.size(); i++)
	{
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(i, elements[i].Count, elements[i].Type,
			elements[i].Normalized, vbl.GetStride(), (const void*)offset);
		offset += elements[i].Count * VertexBufferElement::GetSizeOfType(elements[i].Type);
	}
}

void VertexArray::Bind() const
{
	glBindVertexArray(elementID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &elementID);
}