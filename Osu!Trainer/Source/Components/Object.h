#pragma once

#include "../Engine/Color.h"
#include "../Engine/Attribute.h"

/* object class is the gameplay object that will be drawn on the screen */
class Object
{
protected:
	// x and y of the object on the screen
	// for sliders, it will be the start of the slider
	float x{ 0.0f };
	float y{ 0.0f };

	/* approach rate (AR) and circle size (CS) (used for scaling) and overal difficulty (OD) */
	// AR determines how fast (how long) the object will show on the screen before you have to click it
	// scaling with the static AR variable
	// generally, AR9 - AR9.5 is the sweet spot
	float approachRate{ 9.0f };
	// CS determines how large the object will be
	// scaling with the static CS variable
	// generally, CS4 - CS5 is the sweet spot
	float circleSize{ 5.0f };
	// OD determines how "accurate" you have to press to hit the circle
	// you can only tap in the 50 score range (best if 300), higher OD means this range is tighter
	// generally, OD9 - OD 9.5 is the sweet spot
	float overallDifficulty{ 9.0f };

	// reference approach rate duration for scaling
	static const int scaleAR;
	// reference circle size for scaling
	static const float scaleCS;

	// render radius of the object
	float objectRadius;

	// animationLength is the duration from when the object appears on the screen
	// till the ring touches the object and dissapear (object not yet dissapear)
	// circles and sliders will utilize these variables differently
	int animationLength;
	// 300 score (best score)
	int threeHundred;
	// 100 score (a bit worse)
	int oneHundred;
	// 50 score (worst)
	int fifty;

public:
};