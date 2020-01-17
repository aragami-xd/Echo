#include "Slider.h"
using namespace std;

Slider::Slider(vector<int> beat) :
	Object(beat)
{
	startTime = beats.front() - approachTime;
	endTime = beats.back();
}

int Slider::GetScore(int time)
{
	return 0;
}

float Slider::GetApproachScale(int time)
{
	if (time < beats.front())
		return abs(beats.front() - time) / (float)approachTime;
	else
		return 0;
}

float Slider::GetBeatScale(int time)
{
	if (time < beats.front())
		return 0;

	time = time - beats.front();
	return time / (float)(beats.back() - beats.front());
}