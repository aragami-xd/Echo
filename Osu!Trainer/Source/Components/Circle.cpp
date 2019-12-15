#include "Circle.h"
#include "../Buffers/Renderer.h"
#include <cmath>
#include <iostream>

using namespace std;

constexpr double PI = 3.14;

// constructor
Circle::Circle(float cx, float cy, int cbeat)
{
	x = cx;
	y = cy;
	beatTime = cbeat;

	startTime = beatTime - animationLength;
	endTime = beatTime + fifty;

	// calculate the dots on the circle and the initial ring
	float angle = 0;
	float baseX = 0, baseY = 0;
	for (int i = 0; i <= ::DotCount; i++)
	{
		angle = 2 * PI * i / ::DotCount;
		baseX = objectRadius * cos(angle) * ::HeightDivWidth;
		baseY = objectRadius * sin(angle);

		circleDot.push_back(x + baseX);
		ringDot.push_back(x + baseX * 2);

		circleDot.push_back(y + baseY);
		ringDot.push_back(y + baseY * 2);
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
float* Circle::GetRingDot(int timeStamp)
{
	// calculate the dots on the ring again, based on the timestamp
	float remaining = (abs((beatTime - timeStamp)) / (float)animationLength) + 1;

	float angle = 0;
	for (int i = 0; i < ringDot.size(); i+=2)
	{
		angle = 2 * PI * i / ::DotCount;

		ringDot[i] = x + objectRadius * cos(angle) * ::HeightDivWidth * remaining;
		ringDot[i + 1] = y + objectRadius * sin(angle) * remaining;
	}

	return ringDot.data();
}

void Circle::Draw(int time)
{
	VertexBufferLayout vbl;
	vbl.Push<float>(2);

	VertexArray vaCircle;
	VertexBuffer vbCircle(GetCircleDot(), sizeof(float) * circleDot.size(), GL_STATIC_DRAW);
	vaCircle.AddBuffer(vbCircle, vbl);

	glDrawArrays(GL_LINE_LOOP, 0, ::DotCount);

	if (time < beatTime)
	{
		VertexArray vaRing;
		VertexBuffer vbRing(GetRingDot(time), sizeof(float) * ringDot.size(), GL_STATIC_DRAW);
		vaRing.AddBuffer(vbRing, vbl);

		glDrawArrays(GL_LINE_LOOP, 0, ::DotCount);
	}
}