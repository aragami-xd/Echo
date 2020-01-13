#include "Circle.h"
#include "CircleComponent.h"
#include "CircleRenderElement.h"
using namespace std;

Circle::Circle(float cx, float cy, int beatTime) :
	Object(cx, cy), beat(beatTime)
{
	startTime = beatTime - approachTime;
	endTime = beatTime + score50;
}

int Circle::GetScore(int time)
{
	time = abs(beat - time);
	if (time < score300)
		return 300;
	else if (time < score100)
		return 100;
	else if (time < score50)
		return 50;
	else
		return 0;	// 0 score is a miss
}

float Circle::GetApproachScale(int time)
{
	return abs(beat - time) / (float)approachTime;
}