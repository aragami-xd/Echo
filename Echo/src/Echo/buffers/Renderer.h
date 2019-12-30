#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class ECHO_DLL Renderer
{
private:
	Renderer() = default;
public:
	static inline void Render(VertexArray& va, IndexBuffer& ib, Shader& shader, GLenum flag = GL_STATIC_DRAW)
	{
		va.Bind();
		ib.Bind();
		shader.Bind();

		glDrawElements(flag, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	static inline void Render(VertexArray& va, int count, Shader& shader, GLenum flag = GL_STATIC_DRAW)
	{
		va.Bind();
		shader.Bind();

		glDrawArrays(flag, 0, count);
	}
};