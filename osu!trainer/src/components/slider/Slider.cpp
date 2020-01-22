#include "Slider.h"

OsuTrainer::Slider::Slider(std::vector<int> beat) :
	Object(beat)
{
	startTime = beats.front() - approachTime;
	endTime = beats.back();
}

int OsuTrainer::Slider::GetScore(int time)
{
	return 0;
}

float OsuTrainer::Slider::GetApproachScale(int time)
{
	if (time < beats.front())
		return abs(beats.front() - time) / (float)approachTime;
	else
		return 0;
}

float OsuTrainer::Slider::GetBeatScale(int time)
{
	if (time < beats.front())
		return 0;

	time = time - beats.front();
	return time / (float)(beats.back() - beats.front());
}