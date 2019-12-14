#pragma once

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
	static float approachRate;
	// CS determines how large the object will be
	// scaling with the static CS variable
	static float circleSize;
	// OD determines how "accurate" you have to press to hit the circle
	// you can only tap in the 50 score range (best if 300), higher OD means this range is tighter
	static float overallDifficulty;

	// reference approach rate duration for scaling
	static const int scaleAR;
	// reference circle size for scaling
	static const float scaleCS;

	// render radius of the object
	static float objectRadius;

	// animationLength is the duration from when the object appears on the screen
	// till the ring touches the object and dissapear (object not yet dissapear)
	// circles and sliders will utilize these variables differently
	static int animationLength;
	// 300 score (best score)
	static int threeHundred;
	// 100 score (a bit worse)
	static int oneHundred;
	// 50 score (worst)
	static int fifty;

public:
	// set the metadata of the circle and other variables
	static void SetMetadata(float AR, float CS, float OD)
	{
		// AR, CS, OD
		approachRate = AR;
		circleSize = CS;
		overallDifficulty = OD;

		// object radius
		objectRadius = scaleCS / circleSize;

		// timestamp variables
		animationLength = (int)(scaleAR / approachRate);
		threeHundred = (int)(animationLength / (3 * overallDifficulty));
		oneHundred = (int)(threeHundred * 1.1);
		fifty = (int)(threeHundred * 1.3);
	}
};