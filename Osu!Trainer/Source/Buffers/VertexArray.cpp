#include "VertexArray.h"
#include "Macro.h"

using namespace std;

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &elementID);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& vbl) 
{
	Bind();
	vb.Bind();

	// get vbl elements
	const auto& elements = vbl.GetElement();
	unsigned int offset = 0;

	// add each element of vbl into the vao
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		glEnableVertexAttribArray(i);

		glVertexAttribPointer(
			i,
			elements[i].Count,
			elements[i].Type,
			elements[i].Normalized,
			vbl.GetStride(),
			(const void*)offset
		);

		// increment to the next offset
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
	GLCall(glDeleteVertexArrays(1, &elementID));
}