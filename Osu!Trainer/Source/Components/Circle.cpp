#include "Circle.h"
#include "../Buffers/Renderer.h"
#include <cmath>

using namespace std;

constexpr double PI = 3.14;

// constructor
Circle::Circle(float cx, float cy, int cbeat)
{
	x = cx;
	y = cy;
	beatTime = cbeat;

	animationTime = beatTime - animationLength;
	endTime = beatTime + fifty;

	// calculate the dots on the circle and the initial ring
	double angle = 0;
	for (int i = 0; i < ::DotCount; i++)
	{
		angle = 2 * PI * i / ::DotCount;

		circleDot.push_back(objectRadius * cos(angle) * ::HeightDivWidth);
		ringDot.push_back(x + circleDot.back() * 2);

		circleDot.push_back(objectRadius * sin(angle));
		ringDot.push_back(y + circleDot.back() * 2);
	}
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

// get the ringDot array at a certain time
vector<float> Circle::GetRingDot(int timeStamp)
{
	// calculate the dots on the ring again, based on the timestamp
	float remaining = abs((beatTime - timeStamp)) / (float)animationLength + 1;

	for (float i = 2; i < 2 * PI; i += 2 * PI / ::DotCount)
	{
		ringDot[i] = x + objectRadius * cos(i) * ::HeightDivWidth * remaining;
		ringDot[i + 1] = y + objectRadius * sin(i) * remaining;
	}

	return ringDot;
}