#pragma once

#include "Renderer.h"
#include <string>

class Texture
{
private:
	unsigned int id;
	std::string path;
	unsigned char* localBuffer;
	int width, height, bpp;

public:
	Texture(const std::string& file);
	void Bind(unsigned int slot = 0) const ;
	void Unbind() const;

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }

	~Texture();
};