#pragma once

#include "Instrument.h"
#include <vector>
#include <string>

/* object class is the gameplay object that will be drawn on the screen */
class Object
{
protected:
	// constructor
	Object(float x, float y, std::vector<int>& beats, /*std::string& equation, std::vector<Instrument>& instruments,*/ float AR, float CS, float OD);

	// x and y of the object on the screen at it's first beat
	float x;
	float y;

	// AR determines how fast (how long) the object will show on the screen before you have to click it
	static float approachRate;
	// CS determines how large the object will be
	static float circleSize;
	// OD determines how "accurate" you have to press to hit the circle, higher means tigther timing
	static float overallDifficulty;

	// reference approach rate duration for scaling
	static const int scaleAR;
	// reference circle size for scaling
	static const float scaleCS;

	// render size of the object
	static float objectSize;

	static int animationLength;	// how long the object appears before its first beat
	static int threeHundred;	// 300 score (best score)
	static int oneHundred;		// 100 score (a bit worse)
	static int fifty;			// 50 score (worst)

	// when the object appears and disappears on the screen
	int startTime;
	int endTime;

	// beats of the object and beat index (index of the next beat)
	std::vector<int> beats;
	unsigned int beatIndex;

	// equation string used for creating the object
	std::string equation;

	// instruments
	std::vector<Instrument> instruments;

	// parse the equation
	void EquationParser();

public:
	inline float GetX() { 
		return x;
	}
	inline float GetY() { 
		return y;
	}
	inline float GetObjectSize() { 
		return objectSize;
	}
	inline int GetAnimationLength() { 
		return animationLength;
	}
	inline int GetStartTime() { 
		return startTime;
	}
	inline int GetEndTime() { 
		return endTime;
	}
	inline int GetBeatTime() {
		return beats.at(beatIndex);
	}
};