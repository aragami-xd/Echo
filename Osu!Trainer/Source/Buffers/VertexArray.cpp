#include "VertexArray.h"
#include "Macro.h"

using namespace std;

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &elementID));
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
		GLCall(glVertexAttribPointer(i, elements[i].Count, elements[i].Type,
			elements[i].Normalized, vbl.GetStride(), (const void*)offset);
		offset += elements[i].Count * VertexBufferElement::GetSizeOfType(elements[i].Type));
	}
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(elementID));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &elementID));
}