#pragma once

#include <EchoHeader.h>

/* object contains basic data of the object, not visual data */
class Object
{
protected:
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
	static float scaleOD;

	// beats and timestamps (when the circle appears and disappears)
	std::vector<int> beats;
	int currentBeat;
	int startTime;
	int endTime;

	// render equation: the line that determine the shape of the object
	// final equation will be the sum of all equation(x,y) of the vecto
	std::vector<std::function<float(void*, void*)>> renderEquation;

	// movement equation: how the object moves
	std::vector<std::function<float(void*, void*)>> movementEquation;
};