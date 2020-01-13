#include "Slider.h"
using namespace std;

Slider::Slider(float xs, float ys, vector<int> beat) :
	Object(xs, ys), beats(beat), beatIndex(0)
{
	startTime = beats.front() - approachTime;
	endTime = beats.back() + score50;
}

int Slider::GetScore(int time)
{
	return 0;
}

float Slider::GetApproachScale(int time)
{
	return abs(beats.front() - time) / (float)approachTime;
}

