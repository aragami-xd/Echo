#pragma once

#include <Echo/buffers/Renderer.h>
#include <glm/glm.hpp>

namespace Echo
{
	/* providing buffers for ease of usage only, each element will use them differently */
	class ECHO_DLL RenderElement
	{
	protected:
		RenderElement();

		// buffers
		VertexLayout* vl;
		VertexArray* va;
		VertexBuffer* vb;
		IndexBuffer* ib;
	public:
		// get the buffers (vertex layout and vertex buffer are not needed)
		VertexArray* GetVertexArray() { return va; }
		IndexBuffer* GetIndexBuffer() { return ib; }

		// all elements must be able to return x and y when needed
		// for moving objects, time is needed to calculate the coordinates
		virtual float GetX(float time) = 0;
		virtual float GetY(float time) = 0;

		~RenderElement();
	};
}