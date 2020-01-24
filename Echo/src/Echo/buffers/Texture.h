#pragma once

#include <EchoHeader.h>
#include <EchoCore.h>

namespace Echo
{
	class ECHO_DLL Texture
	{
	private:
		unsigned int tex;
		int width, height, channel;
		unsigned char* data;
	public:
		Texture(const std::string& path);
		void Bind();
		void UnBind();
		~Texture();
	};
}