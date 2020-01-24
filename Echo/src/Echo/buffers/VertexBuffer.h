#pragma once

#include <EchoCore.h>
#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace Echo
{
	class ECHO_DLL VertexBuffer
	{
	private:
		unsigned int id;

	public:
		VertexBuffer(float* data, int size, GLenum flag = GL_STATIC_DRAW);

		void Bind();
		void Unbind();

		~VertexBuffer();
	};
}