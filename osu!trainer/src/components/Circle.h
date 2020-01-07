#pragma once

#include <Echo.h>

class Circle : public Object
{
private:
	int beat;
public:
	Circle(float cx, float cy, int beatTime);

	virtual int GetScore(int time);
	virtual float GetApproachScale(int time);

	~Circle() = default;
};

// circle parsing function
ObjectComponent* CircleParser(std::stringstream& ss);