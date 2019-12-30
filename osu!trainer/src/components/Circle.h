#pragma once

#include <Echo/components/Object.h>

class Circle : public Object
{
private:
	int beat;
public:
	Circle(float cx, float cy, int beatTime);

	virtual int GetScore(int time);

	~Circle() = default;
};

Object* CircleParser(std::stringstream& ss);