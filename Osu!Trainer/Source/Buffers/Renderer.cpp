#include "Renderer.h"
#include <iostream>

using namespace std;

// draw function
void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	ib.Bind();
	va.Bind();
	shader.Bind();

	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}