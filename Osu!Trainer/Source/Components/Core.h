#pragma once

#include "Circle.h"
#include "Slider.h"
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

	// program shader
	Shader* shader;

	// all the circle and slider parsed from the map
	// since the program costantly loop through the elements, it's better to use
	// array (vector) than list for better cache hit
	std::vector<Circle*> allCircle;
	std::vector<Slider*> allSlider;
	// index of the circle and slider
	unsigned int circleIndex{ 0 }, sliderIndex{ 0 };

	// metadata - song setup
	float approachRate{ 9.0f };
	float circleSize{ 5.0f };
	float overallDifficulty{ 9.0f };
	float hpDrain{ 6.0f };

	// color list
	std::vector<Color> colorList{ COLOR_WHITE, COLOR_LIGHT_BLUE, COLOR_LIGHT_YELLOW };

	// function draws individual circle at a time
	void DrawOneCircle(Circle* circle);

	// function draws individual slider at a time
	void DrawOneSlider(Slider* slider);

	// function handles which circle or slider to be drawn
	void DrawAllObject();

public:
	Core();

	// initialize the map
	void MapInit(std::string path);

	// draw everything on the screen
	void Draw();

	~Core();
};