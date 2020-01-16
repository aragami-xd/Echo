#pragma once

#include <Echo/buffers/Renderer.h>
#include <glm/glm.hpp>

/* providing buffers for ease of usage only, each element will use them differently */
class ECHO_DLL RenderElement
{
protected:
	// buffers
	VertexLayout* vl;
	VertexArray* va;
	VertexBuffer* vb;
	IndexBuffer* ib;
public:
	RenderElement();

	VertexArray* GetVertexArray() { return va; }
	IndexBuffer* GetIndexBuffer() { return ib; }

	// all elements must be able to return x and y when needed
	virtual float GetX(int time) = 0;
	virtual float GetY(int time) = 0;

	~RenderElement();
};