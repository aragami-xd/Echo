#include "Circle.h"
#include <math.h>
#include <iostream>
#include <GL/glew.h>

using namespace std;

constexpr double PI = 3.14;

const int Circle::scaleAR = 5000;
const float Circle::scaleCS = 0.5f;

// constructor
Circle::Circle(float cx, float cy, float cAR, float cCS, float cOD, int cbeat, Color ccolor)
{
	x = cx;
	y = cy;
	approachRate = cAR;
	overallDifficulty = cOD;
	beatTime = cbeat;
	circleColor = ccolor;

	// timestamps: animationLength, 300, 100, 50, animationTime, endTime
	animationLength = scaleAR / approachRate;
	threeHundred = animationLength / (3 * overallDifficulty);
	oneHundred = threeHundred * 1.1;
	fifty = threeHundred * 1.3;

	animationTime = beatTime - animationLength;
	endTime = beatTime + fifty;

	// circle size
	objectRadius = scaleCS / circleSize;

	// setup the dots on the circle and the initial ring
	circleDot[0] = x;
	circleDot[1] = y;
	ringDot[0] = x;
	ringDot[1] = y;
	// calculate the dots on the circle and the initial ring
	float angle = 0;
	for (int i = 2; i < ::DotCount * 2 + 2; i += 2)
	{
		angle = 2 * PI * i / ::DotCount;

		circleDot[i] = x + objectRadius * cos(angle) * ::HeightDivWidth;
		circleDot[i + 1] = y + objectRadius * sin(angle);

		ringDot[i] = circleDot[i] * 2;
		ringDot[i + 1] = circleDot[i + 1] * 2;
	}

	// create the buffers
	vbCircle = new VertexBuffer(circleDot, sizeof(circleDot));
	vbRing = new VertexBuffer(ringDot, sizeof(ringDot));
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
VertexBuffer* Circle::GetRingBuffer(int timeStamp)
{
	// calculate the dots on the ring again, based on the timestamp
	float angle = 0;
	float remaining = abs((beatTime - timeStamp) / (float)animationLength) + 1;
	for (int i = 2; i < ::DotCount * 2 + 2; i += 2)
	{
		angle = 2 * PI * i / ::DotCount;
		ringDot[i] = x + objectRadius * cos(angle) * ::HeightDivWidth * remaining;
		ringDot[i + 1] = y + objectRadius * sin(angle) * remaining;
	}

	// set the data to the buffer
	vbRing->Update(ringDot, sizeof(ringDot));
	return vbRing;
}

// delete the buffers in the destructor
Circle::~Circle()
{
	delete vbCircle;
	delete vbRing;
}