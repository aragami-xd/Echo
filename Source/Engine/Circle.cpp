#include "Circle.h"
#include <iostream>
#include <math.h>
#include <GL/glew.h>

#define PI 3.1415

using namespace std;

// static variables
int Circle::scaleAR = 5000;
int Circle::scaleCS = 500;

// setters and getters
// *
// set x
void Circle::SetX(float x)
{
	this->x = x;
}
// get x
float Circle::GetX()
{
	return x;
}

// set y
void Circle::SetY(float y)
{
	this->y = y;
}
// get y
float Circle::GetY()
{
	return y;
}

// create color
void Circle::CreateColor(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f)
{
	circleColor = { r,g,b,a };
}
// set color
void Circle::SetColor(Color color)
{
	circleColor = color;
}
// get color
Color Circle::GetColor()
{
	return circleColor;
}

// set AR
// setAR will also set animationLength, 300, 100 and 50
void Circle::SetAR(float AR)
{
	// set the AR scale value
	approachRate = AR;
	// set the actual animation length
	animationLength = (int)(scaleAR / approachRate);
}
// get AR
float Circle::GetAR()
{
	return approachRate;
}

// set CS
void Circle::SetCS(float CS)
{
	// set the CS scale value
	circleSize = CS;
	// set the actual cirle and ring radius
	circleRadius = (int)(scaleCS / circleSize);
	ringRadius = circleRadius * 2;
	// generate the vertices to draw the circle
	GenCircle();
}
// get CS
float Circle::GetCS()
{
	return circleSize;
}

// set OD
// set OD will also set the timestamps
void Circle::SetOD(float OD)
{
	// set the OD value
	overallDifficulty = OD;
	// set the timestamps
	threeHundred = (int)(animationLength / (3 * OD));
	oneHundred = threeHundred * 3;
	fifty = oneHundred * 2;
}
// getOD
float Circle::GetOD()
{
	return overallDifficulty;
}

//// animation length
//int Circle::GetAnimationLength()
//{
//	return animationLength;
//}
// circle radius
int Circle::GetCircleRadius()
{
	return circleRadius;
}

// set beat time
// set beat time will also set animation start time and end time
void Circle::setBeatTime(int time)
{
	beatTime = time;

	// animation time needs to be set up before calling this function
	if (animationLength < 0)
	{
		std::cout << "AR must be set before setting beat time" << std::endl;
		throw std::exception();
	}

	animationTime = time - animationLength;
	endTime = time + fifty;
}
// get beat time
int Circle::getBeatTime()
{
	return beatTime;
}
// get animation time
int Circle::getAnimationTime()
{
	return animationTime;
}
// get end time
int Circle::getEndTime()
{
	return endTime;
}

// get score will return the score based on the time stamp
// time here will be the timestamp of the beatmap
int Circle::GetScore(int timestamp)
{
	// since time is the timestamp into the map, we'll have to convert it into remaining time to the beat
	timestamp = beatTime - timestamp;

	// difference between time of tapping and perfect animation finished
	int diff = abs(animationLength - timestamp);

	// compare against time checkpoints
	if (diff > fifty)
		// too early or too late, 0 score (miss)
		return 0;
	else if (diff > oneHundred)
		// 50 scores
		return 50;
	else if (diff > threeHundred)
		// 100 scores
		return 100;
	else
		// 300 scores
		return 300;
}
// ring radius
int Circle::GetRingRadius(int timestamp)
{
	// see how much time is remaining in the animation as scaling
	timestamp = beatTime - timestamp;
	return ringRadius * (timestamp / approachRate);
}


/* helper functions */
void Circle::GenCircle()
{

}

std::vector<float> Circle::GetCircleVertices()
{
	return vertices;
}