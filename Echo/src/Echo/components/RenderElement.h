#pragma once

#include <Echo/buffers/Renderer.h>
#include <glm/glm.hpp>

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

	~RenderElement();
};