#pragma once

#include "Circle.h"
#include "Slider.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/Shader.h"
#include "../Buffers/Texture.h"

#include <list>
#include <vector>

class Core
{
private:
	// all the circle and slider parsed from the map
	std::list<Circle*> allCircle;
	std::list<Slider*> allSlider;

	// metadata - song setup
	float approachRate{ 9.5f };
	float circleSize{ 5.0f };
	float overallDifficulty{ 9.0f };
	float hpDrain{ 6.0f };

	// color list
	std::vector<Color> colorList{ COLOR_WHITE, COLOR_LIGHT_BLUE, COLOR_LIGHT_YELLOW };

	// function draws individual circle at a time
	void DrawOneCircle(Circle* circle);

	// function draws individual slider at a time
	void DrawOneSlider(Slider* slider);

	// function handles which circle to be drawn
	void DrawAllObject();

public:
	Core();

	// initialize the map
	void MapInit(std::string path);

	// draw everything on the screen
	void Draw();

	~Core();
};