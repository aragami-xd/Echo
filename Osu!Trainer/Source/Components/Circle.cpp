#include "Circle.h"
#include "../Buffers/Renderer.h"
#include <cmath>
#include <iostream>

using namespace std;

// constructor
Circle::Circle(float x, float y, int beat, float AR, float CS, float OD) :
	Object(x, y, AR, CS, OD)
{
	beatTime = beat;
	startTime = beatTime - animationLength;
	endTime = beatTime + fifty;

	renderer = new CircleRenderer(x, y, objectRadius);
}

// get score will return the score based on the time stamp
int Circle::GetScore(int timestamp)
{
	// since time is the timestamp into the map, we'll have to convert it into remaining time to the beat
	timestamp = beatTime - timestamp;
	int diff = abs(animationLength - timestamp);

	// compare against time checkpoints
	if (diff > fifty)
		return 0;
	else if (diff > oneHundred)
		return 50;
	else if (diff > threeHundred)
		return 100;
	else
		return 300;
}

void Circle::Draw(int time)
{
	renderer->DrawCircleDep();
	if (time < beatTime)
		renderer->DrawRingDep(time, beatTime, animationLength);
}

Circle::~Circle()
{
	delete renderer;
}