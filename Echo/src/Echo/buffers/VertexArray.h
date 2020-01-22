#pragma once

#include "VertexLayout.h"
#include "VertexBuffer.h"

namespace Echo
{
	class ECHO_DLL VertexArray
	{
	private:
		unsigned int id;
	public:
		VertexArray();

		void AddBuffer(VertexLayout& vl, VertexBuffer& vb);
		void Bind();
		void Unbind();

		~VertexArray();
	};
}