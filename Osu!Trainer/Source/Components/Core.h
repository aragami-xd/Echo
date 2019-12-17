#pragma once

#include "Circle.h"
#include "Slider.h"
#include "ShaderList.h"
#include "../Engine/Color.h"

#include <vector>
#include <ctime>

class Core
{
private:
	// time attributes
	int start;		// game start
	int time;		// current time
	int prevFrame;	// previous frame

	//shader
	ShaderList shader;

	// all the circle and slider parsed from the map
	std::vector<Circle*> allCircle;
	std::vector<Slider*> allSlider;
	// current index of the circle and slider
	int circleIndex{ 0 }, sliderIndex{ 0 };

	// metadata - song setup
	float approachRate{ 9.0f };
	float circleSize{ 5.0f };
	float overallDifficulty{ 9.0f };
	float hpDrain{ 6.0f };

	// color list
	std::vector<Color> colorList{ COLOR_WHITE, COLOR_LIGHT_BLUE, COLOR_LIGHT_YELLOW };

	// initialize the map
	void MapInit(std::string path);

	// function draws individual circle at a time
	void DrawOneCircle(Circle* circle);

	// function draws individual slider at a time
	void DrawOneSlider(Slider* slider);

	// function handles which circle or slider to be drawn
	void DrawAllObject();

public:
	Core(std::string path, ShaderList shader);

	// draw everything on the screen
	void Draw();

	~Core();
};