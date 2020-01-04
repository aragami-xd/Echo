#pragma once

#include <Echo/buffers/Renderer.h>
#include <glm/glm.hpp>

class ECHO_DLL RenderElement
{
protected:
	RenderElement(glm::vec4 objectColor);

	// buffers
	VertexLayout* vl;
	VertexArray* va;
	VertexBuffer* vb;
	IndexBuffer* ib;

	// element base color
	glm::vec4 color;
public:
	VertexArray* GetVertexArray() { return va; }
	IndexBuffer* GetIndexBuffer() { return ib; }

	~RenderElement();
};