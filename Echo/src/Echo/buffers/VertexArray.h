#pragma once

#include "VertexLayout.h"
#include "VertexBuffer.h"

class VertexArray
{
private:
	unsigned int id;
public:
	VertexArray(VertexLayout& vl, VertexBuffer& vb);

	void Bind();
	void Unbind();

	~VertexArray();
};