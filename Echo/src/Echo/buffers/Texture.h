#pragma once

#include <EchoHeader.h>
#include <Core.h>

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