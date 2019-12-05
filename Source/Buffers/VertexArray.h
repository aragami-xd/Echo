#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int elementID;

public:
	VertexArray();

	void AddBuffer(VertexBuffer& vb, VertexBufferLayout& vbl);
	void Bind();
	void Unbind();

	~VertexArray();
};