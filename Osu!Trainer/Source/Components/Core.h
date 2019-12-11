#pragma once

#include "Circle.h"
#include "../Engine/Color.h"
#include "../Buffers/Macro.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/Shader.h"
#include "../Buffers/Texture.h"

#include <list>
#include <fstream>

class Core
{
private:
	// the map itself
	std::ifstream map;

	// all the circle parsed from the map
	std::list<Circle*> allCircle;

public:
	Core();

	void MapInit(std::string path);
	void Draw();

	~Core();
};