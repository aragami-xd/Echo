#pragma once

#include <EchoHeader.h>
#include <Core.h>

class ECHO_DLL Object
{
protected:
	Object(const std::vector<int>& beats);

	/* difficulty variables:
	* AR: approach rate: how fast the object appears and disappears on the screen
	* OD: how close to the beat the player has to tap to score point
	*/
	static float AR;
	static float OD;

	// use to scale AR
	static int scaleAR;
	int approachTime;

	// beats
	std::vector<int> beats;
	int beatIndex;

	// timestamps (when the circle appears and disappears)
	int startTime;
	int endTime;

	// score range
	int score300;
	int score100;
	int score50;

	// score range scaling
	static float score300Scaling;
	static float score100Scaling;
	static float score50Scaling;
public:
	// return a score when the user taps, return 0 if tap too early or soon
	virtual int GetScore(int time) = 0;

	/* animation time scale: see how long into the approaching animation
	e.g. startTime = 0; first beat = 500; time = 200 
	-> 200 / 500 = 0.4 
	-> completed 0.4 of the animation
	*/
	virtual float GetApproachScale(int time);

	/* beat time scale: see how long into the beats of the object
	different objects will implement this function differently

	e.g. first beat = 500; last beat = 3000; time = 1000
	-> 1000 / (3000 - 500) = 0.4
	-> completed 0.4 of the beats of the object
	*/
	virtual float GetBeatScale(int time) = 0;

	// get start / end time
	inline int GetStartTime() { return startTime; }
	inline int GetEndTime() { return endTime; }

	~Object() = default;
};