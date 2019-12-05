#pragma once

#include "Renderer.h"

class IndexBuffer
{
private:
	unsigned int vertexID;
	unsigned int count;
public:
	IndexBuffer(const unsigned int* data, unsigned int indexCount);
	void Bind();
	void Unbind();
	~IndexBuffer();
};