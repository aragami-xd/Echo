#pragma once

#include "Renderer.h"

class VertexBuffer
{
private:
	unsigned int vertexID;
public:
	VertexBuffer(const void* data, unsigned int);
	void Bind();
	void Unbind();
	~VertexBuffer();
};
