#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class ECHO_DLL Renderer
{
private:
	Renderer() = default;
public:
	// render using vertex array and index array
	static void Render(VertexArray* va, IndexBuffer* ib, GLenum flag = GL_LINE_LOOP, int weight = 1);

	// render using vertex array only
	static void Render(VertexArray* va, int count, GLenum flag = GL_LINE_LOOP, int weight = 1);
};