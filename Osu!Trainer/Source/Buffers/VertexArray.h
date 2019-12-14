#pragma once

#include "VertexBuffer.h"
#include "VertexBufferObject.h"

class VertexArray
{
private:
	unsigned int elementID;

public:
	VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferObject& vbo);
	void Bind() const;
	void Unbind() const;

	~VertexArray();
};