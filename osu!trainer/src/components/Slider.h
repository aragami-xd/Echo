#pragma once

#include <Echo.h>

class Slider : public Object
{
private:
	std::vector<int> beats;
	int beatIndex;
public:
	Slider(float xs, float ys, std::vector<int> beat);
	
	virtual int GetScore(int time);
	virtual float GetApproachScale(int time);

	~Slider() = default;
};