#pragma once

#include <EchoCore.h>
#include <glad/glad.h>

namespace Echo
{
	class ECHO_DLL IndexBuffer
	{
	private:
		unsigned int id;
		unsigned int count;
	public:
		IndexBuffer(unsigned int* data, int count, GLenum flag = GL_STATIC_DRAW);

		void Bind();
		void Unbind();

		inline unsigned int GetCount() { return count; }

		~IndexBuffer();
	};
}