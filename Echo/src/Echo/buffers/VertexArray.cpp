#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &id);
}

void VertexArray::AddBuffer(VertexLayout& vl, VertexBuffer& vb)
{
	glBindVertexArray(id);
	vb.Bind();

	const auto& element = vl.GetVertexElement();
	unsigned int offset = 0;

	for (int i = 0; i < element.size(); i++)
	{
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(
			i,
			element[i].count,
			element[i].type,
			element[i].normalized,
			vl.GetStride(),
			(const void*)offset
		);
		offset += element[i].count * element[i].byte;
	}
}

void VertexArray::Bind()
{
	glBindVertexArray(id);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &id);
}