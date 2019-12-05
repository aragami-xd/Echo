#pragma once

#include "Color.h"
#include <vector>

class Circle
{
private:
	// location of the circle
	float x{ 0.0f };
	float y{ 0.0f };

	/* approach rate (AR) and circle size (CS) (used for scaling) and overal difficulty (OD) */
	// AR determines how fast (how long) the circle will show on the screen
	// scaling with the static AR variable
	// generally, AR9 - AR9.5 is the sweet spot
	float approachRate{ 0.0f };
	// CS determines how large the circle will be
	// scaling with the static CS variable
	// generally, CS4 - CS5 is the sweet spot
	float circleSize{ 0.0f };
	// OD determines how tight you have to press to hit the circle
	// you can only tap in the 50 score range (best if 300), higher OD means this range is tighter
	// generally, OD9 - OD 9.5 is the sweet spot
	float overallDifficulty{ 0.0f };

	/* static variables for AR and CS scaling */
	// reference approach rate duration for scaling
	// default to 4500ms
	static int scaleAR;
	// reference circle size for scaling
	// the game area will be a grid of 512x384
	// default scaling will be a circle with radius half of the height of the area
	static int scaleCS;

	/* timestamp checkpoint variables */
	// animationLength is the duration from when the circle appears on the screen
	// till the ring touches the circle and dissapear (circle not yet dissapear)
	int animationLength{ -1 };

	// 300 score is the time range that tapping within that time will give maximum
	// +- (animationLength / 30)
	int threeHundred{ -1 };
	// 100 score (a bit worse)
	// +- (animationLength / 10) (until 300 score)
	int oneHundred{ -1 };
	// 50 score (worst)
	// +- (animationLength / 5)
	// outside of this range will be a miss (i.e. way too soon or early)
	int fifty{ -1 };

	// when the circle appears on the screen
	int animationTime{ -1 };
	// when the beat of the circle is mapped to (i.e. animation ends)
	int beatTime{ -1 };
	// when the circle disappears
	int endTime{ -1 };

	/* size of the actual circle and outer ring */
	// at the start of the animation, ring will have float the radius of the circle
	int circleRadius{ -1 };
	int ringRadius{ -1 };

	// color of the circle
	Color circleColor{ 0.0f, 0.0f, 0.0f, 0.0f };

public:
	// set and get (x,y)
	void SetX(float x);
	float GetX();
	void SetY(float y);
	float GetY();

	// set and getColor (set based on 4 attributes or a pre-made color)
	void CreateColor(float r, float g, float b, float a);
	void SetColor(Color color);
	Color GetColor();

	/* set and get (AR, CS, OD) */
	// set AR will also set animationLength
	void SetAR(float AR);
	float GetAR();
	// set CS will also set the circle and ring radius
	void SetCS(float CS);
	float GetCS();
	// set OD will also set the 300, 100 and 50
	void SetOD(float OD);
	float GetOD();

	// set() and get() the beat time for the circle
	void setBeatTime(int time);
	int getAnimationTime();
	int getBeatTime();
	int getEndTime();

	// animationLength will return the amount of time the animation will last
	// maybe removed later since it's probably not necessary
	// int GetAnimationLength();
	// circleRadius will return the size of the circle on the screen
	int GetCircleRadius();

	// getScore will return the score when the circle is tapped at a certain moment
	int GetScore(int time);
	// ringRadius will return the size of the ring at the start of the animation
	int GetRingRadius(int time);
};