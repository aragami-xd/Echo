#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class ECHO_DLL Renderer
{
private:
	Renderer() = default;
public:
	static inline void Render(VertexArray* va, IndexBuffer* ib, GLenum flag = GL_TRIANGLES)
	{
		va->Bind();
		ib->Bind();
		glDrawElements(flag, ib->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	static inline void Render(VertexArray* va, int count, GLenum flag = GL_TRIANGLES)
	{
		va->Bind();
		glDrawArrays(flag, 0, count);
	}

	static inline void StrokeWeight(int weight)
	{
		glLineWidth(weight);
	}
};