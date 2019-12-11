#pragma once

#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

// renderer class
class Renderer
{
public:
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};