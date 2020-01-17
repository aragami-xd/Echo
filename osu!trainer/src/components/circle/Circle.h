#pragma once

#include <Echo.h>

class Circle : public Object
{
public:
	Circle(int beat);
	virtual int GetScore(int time);
	inline virtual float GetBeatScale(int time) final override { return 1; }
	~Circle() = default;
};