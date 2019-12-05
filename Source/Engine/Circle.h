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
	float approachRate{ 9.0f };
	// CS determines how large the circle will be
	// scaling with the static CS variable
	// generally, CS4 - CS5 is the sweet spot
	float circleSize{ 5.0f };
	// OD determines how tight you have to press to hit the circle
	// you can only tap in the 50 score range (best if 300), higher OD means this range is tighter
	// generally, OD9 - OD 9.5 is the sweet spot
	float overallDifficulty{ 9.0f };

	/* static variables for AR and CS scaling */
	// reference approach rate duration for scaling
	static const int scaleAR;
	// reference circle size for scaling
	static const float scaleCS;

	// animationLength is the duration from when the circle appears on the screen
	// till the ring touches the circle and dissapear (circle not yet dissapear)
	int animationLength;
	// 300 score (best score) =  +- (animationLength / 30)
	int threeHundred;
	// 100 score (a bit worse) = +- (animationLength / 10)
	int oneHundred;
	// 50 score (worst) = +- (animationLength / 5)
	// outside of this range will be a miss (i.e. way too soon or early)
	int fifty;

	// when the circle appears on the screen
	int animationTime;
	// when the beat of the circle is mapped to (i.e. animation ends)
	int beatTime{ 0 };
	// when the circle disappears
	int endTime;

	// at the start of the animation, ring will have float the radius of the circle
	float circleRadius;
	float ringRadius;

	// color of the circle
	Color circleColor{ 1.0f, 1.0f, 1.0f, 1.0f };

	// screen aspect ratio (height / width)
	double ratio{ 0.5625 };
	// points on the surface of the circle, used to draw the circle later on
	static const int dotCount = 240;
	float circleDot[dotCount];
	float ringDot[dotCount];

public:
	// set and get (x,y)
	inline void SetX(float x) {
		this->x = x;
	}
	inline float GetX() {
		return x;
	}
	inline void SetY(float y) {
		this->y = y;
	}
	inline float GetY() {
		return y;
	}

	// set and getColor (set based on 4 attributes or a pre-made color)
	inline void CreateColor(float r, float g, float b, float a) {
		circleColor = { r,g,b,a };
	}
	inline void SetColor(Color color) {
		circleColor = color;
	}
	inline Color GetColor() {
		return circleColor;
	}

	// set and get AR
	inline void SetAR(float AR) {
		approachRate = AR;
	}
	inline float GetAR() {
		return approachRate;
	}
	// set and get CS
	inline void SetCS(float CS) {
		circleSize = CS;
	}
	inline float GetCS() {
		return circleSize;
	}
	// set and get OD
	inline void SetOD(float OD) {
		overallDifficulty = OD;
	}
	inline float GetOD() {
		return overallDifficulty;
	}

	// set the beat time for the circle
	inline void SetBeatTime(int timestamp) {
		beatTime = timestamp;
	}

	// get beat time, animation time and end time
	inline int GetBeatTime() {
		return beatTime;
	}
	inline int GetAnimationTime() {
		return animationTime;
	}
	inline int GetEndTime() {
		return endTime;
	}

	// set screen ratio
	inline void SetRatio(double ratio) {
		this->ratio = ratio;
	}

	// get the circle dot and ring dot arrays to draw the circle
	inline float* GetCircleDot() {
		return circleDot;
	}

	// getScore will return the score when the circle is tapped at a certain moment
	int GetScore(int timestamp);

	// time is the timestamp of the beatmap, as the ring gets smaller and smaller
	float* GetRingDot(int timestamp);

	// use the attributes above to create the actual circle
	void CreateCircle();

	// for testing purposes
	void GenCircle();
};