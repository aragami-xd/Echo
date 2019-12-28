#pragma once

#include <Echo/components/Object.h>

class Circle : public Object
{
private:
public:
	Circle(float cx, float cy, int beatTime);

	virtual int GetScore();
};