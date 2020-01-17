#include "Circle.h"
#include "CircleComponent.h"
#include <components/element/CircleRenderElement.h>
using namespace std;

Circle::Circle(int beat) :
	Object({ beat })
{
	startTime = beat - approachTime;
	endTime = beat + score50;
}

int Circle::GetScore(int time)
{
	time = abs(beats.front() - time);
	if (time < score300)
		return 300;
	else if (time < score100)
		return 100;
	else if (time < score50)
		return 50;
	else
		return 0;	// 0 score is a miss
}