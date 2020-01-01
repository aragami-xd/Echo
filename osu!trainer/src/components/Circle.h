#pragma once

#include <Echo/components/ObjectComponent.h>

class Circle : public Object
{
private:
	int beat;
public:
	Circle(float cx, float cy, int beatTime);

	virtual int GetScore(int time);

	~Circle() = default;
};

// circle parsing function
ObjectComponent* CircleParser(std::stringstream& ss);