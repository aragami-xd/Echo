#pragma once

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
	static int threeHundred;	// 300 score (best score)
	static int oneHundred;		// 100 score (a bit worse)
	static int fifty;			// 50 score (worst)

	// when the object appears and disappears on the screen
	int startTime{ 0 };
	int endTime{ 0 };

	// constructor
	Object(float x, float y, float AR, float CS, float OD);

public:
	inline float GetX() { return x; }
	inline float GetY() { return y; }
	inline float GetObjectRadius() { return objectRadius; }
	inline int GetAnimationLength() { return animationLength; }
	inline int GetStartTime() { return startTime; }
	inline int GetEndTime() { return endTime; }

	// get beat time will be different with each type of object
	virtual int GetBeatTime() = 0;
};