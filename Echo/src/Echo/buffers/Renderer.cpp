#include "Renderer.h"

void Renderer::Render(VertexArray* va, IndexBuffer* ib, GLenum flag, int weight)
{
	glLineWidth(weight);
	va->Bind();
	ib->Bind();
	glDrawElements(flag, ib->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Render(VertexArray* va, int count, GLenum flag, int weight)
{
	glLineWidth(weight);
	va->Bind();
	glDrawArrays(flag, 0, count);
}