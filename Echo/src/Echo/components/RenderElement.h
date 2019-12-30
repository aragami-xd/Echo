#pragma once

#include <Echo/buffers/Renderer.h>

class RenderElement
{
protected:
	VertexLayout* vl;
	VertexArray* va;
	VertexBuffer* vb;
	IndexBuffer* ib;

	float x;
	float y;

public:
	RenderElement();

	~RenderElement();
};