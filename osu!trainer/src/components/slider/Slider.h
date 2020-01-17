#pragma once

#include <Echo.h>

class Slider : public Object
{
public:
	Slider(std::vector<int> beat);
	virtual int GetScore(int time);
	virtual float GetApproachScale(int time);
	virtual float GetBeatScale(int time);
	~Slider() = default;
};