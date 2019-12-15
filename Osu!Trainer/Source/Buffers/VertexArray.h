#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int elementID;

public:
	VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& vbl);
	void Bind() const;
	void Unbind() const;

	~VertexArray();
};