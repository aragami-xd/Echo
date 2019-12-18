#pragma once

#include <Engine/Object.h>
#include <string>
#include <vector>

class Slider : public Object
{
private:
	// when the slider start appears on the screen
	int startTime;
	// when the beat of the slider starts
	int beatStartTime{ 0 };
	// when the beat of the circle ends
	int beatEndTime{ 0 };
	// the ticks of the slider
	std::vector<int> beatTickTime{ };
	// when the slider disappear
	int endTime;

	// equation elements: how to construct the curve
	std::string equation;
	std::vector<int> constant;
	std::vector<int> exponent;

	// function breaks down equation string into constant and exponants
	void EquationParser();

public:
	Slider(float x, float y, int beatStart, int beatEnd, std::vector<int> beatTick, std::string equation, float AR, float CS, float OD);

	virtual void Draw(int time);
};