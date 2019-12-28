#include "VertexArray.h"

VertexArray::VertexArray(VertexLayout& vl, VertexBuffer& vb)
{
	glGenVertexArrays(1, &id);

	glBindVertexArray(id);
	vb.Bind();

	const auto& element = vl.GetVertexElement();
	unsigned int offset;

	for (int i = 0; i < element.size(); i++)
	{
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(
			i,
			element[i].count,
			element[i].type,
			element[i].normalized,
			vl.GetStride(),
			(void*)offset
		);
		offset += element[i].count * element[i].size;
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