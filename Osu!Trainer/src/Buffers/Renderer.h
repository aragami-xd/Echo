#pragma once

#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

// renderer class
class Renderer
{
public:
	static void DrawIb(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, GLenum flag = GL_LINE_LOOP)
	{
		ib.Bind();
		va.Bind();
		shader.Bind();

		glDrawElements(flag, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
	}
};