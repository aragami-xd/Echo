#pragma once

#include "Object.h"
#include <string>
#include <vector>

class Slider : public Object
{
private:
	// when the slider start appears on the screen
	int animationTime;
	// when the beat of the slider starts
	int beatStartTime{ 0 };
	// when the beat of the circle ends
	int beatEndTime{ 0 };
	// the ticks of the slider
	std::vector<int> beatTickTime{ };
	// when the slider disappear
	int endTime;

	// color of the slider and the slider ball
	Color sliderColor{ COLOR_LIGHT_BLUE };
	Color sliderBallColor{ COLOR_LIGHT_BLUE };

	// equation elements: how to construct the curve
	std::string equation;	// example equations: "1x^-2", "2x^3-5x^2+1"...
	std::vector<int> constant;
	std::vector<int> exponant;

	// function breaks down equation string into constant and exponants
	void EquationParser();

public:
	Slider(float x, float y, float AR, float CS, float OD, int beatStart, int beatEnd,
		std::vector<int> beatTick, Color sliderColor, Color sliderBallColor);
};