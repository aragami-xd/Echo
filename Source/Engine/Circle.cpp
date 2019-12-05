#include "Circle.h"
#include <math.h>
#include <iostream>
#include <GL/glew.h>
using namespace std;

#define PI 3.14

const int Circle::scaleAR = 5000;
const float Circle::scaleCS = 0.5f;

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

// setup the actual circle
void Circle::CreateCircle()
{
	// timestamps
	animationLength = scaleAR / approachRate;
	threeHundred = animationLength / (3 * overallDifficulty);
	oneHundred = threeHundred * 3;
	fifty = threeHundred * 6;

	animationTime = beatTime - animationLength;
	endTime = beatTime + fifty;

	// circle size
	circleRadius = scaleCS / circleSize;
	ringRadius = circleRadius * 2;

	// setup the dots on the circle
	double angle = 0;
	for (int i = 0; i < dotCount; i += 2)
	{
		angle = 2 * PI * i / dotCount;
		circleDot[i] = x + circleRadius * cos(angle) * ratio;
		circleDot[i + 1] = y + circleRadius * sin(angle);
	}
}

// get the ringDot array at a certain time
float* Circle::GetRingDot(int timeStamp)
{
	double angle = 0;
	float remaining = abs((beatTime - timeStamp) / animationLength);
	for (int i = 0; i < dotCount; i += 2)
	{
		angle = 2 * PI * i / dotCount;
		ringDot[i] = (x + ringRadius * cos(angle) * ratio ) * remaining;
		ringDot[i + 1] = (y + ringRadius * sin(angle)) * remaining;
	}
	return ringDot;
}

// for testing purposes: drawing the circle using legacy opengl
void Circle::GenCircle()
{
	glBegin(GL_LINE_LOOP);
	double angle = 0;
	for (int i = 0; i < dotCount; i += 2)
	{
		angle = 2 * PI * i / dotCount;
		glVertex2d(x + circleRadius * cos(angle) * ratio, y + circleRadius * sin(angle));
	}
	glEnd();
}