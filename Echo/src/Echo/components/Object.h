#pragma once

#include <EchoHeader.h>

/* object contains basic data of the object, not visual data */

// the final result will the sum of all operation functions inside this vector
//using Equation = std::function<float(float, float)>;

// a dummy equation always return 1
//const Equation noEquation = [](float a, float b) { return 1.0f; };

class Object
{
protected:
	Object(float ox, float oy, std::vector<int>& obeats/*,
		const Equation& rx, const Equation& ry, const Equation& mx, const Equation& my*/);

	// x and y of the starting point
	float x;
	float y;

	/* difficulty variables:
	* AR: approach rate: how fast the object appears and disappears on the screen
	* CS: how large the object is
	* OD: how close to the beat the player has to tap to score point
	*/
	static float AR;
	static float CS;
	static float OD;

	// use to scale AR and CS
	static int scaleAR;
	static float scaleCS;

	int approachTime;

	// beats and timestamps (when the circle appears and disappears)
	std::vector<int> beats;
	int currentBeat;
	int startTime;
	int endTime;

	// render equations: the line that determine the shape of the object
	//Equation renderEquationX;
	//Equation renderEquationY;

	//// movement equation: how the object moves
	//Equation movementEquationX;
	//Equation movementEquationY;

	// score range
	int score300;
	int score100;
	int score50;

	// score range scaling
	static float score300Scaling;
	static float score100Scaling;
	static float score50Scaling;

	// return coordination based on the equation above
	//float ParseEquation(Equation& equation);

public:
	// return a score when the user taps
	virtual int GetScore(int time) = 0;
};
