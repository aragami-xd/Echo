#pragma once

#include "Object.h"

/* extension of the object class */

class ECHO_DLL MultibeatObject : public Object
{
protected:
	MultibeatObject(float xs, float ys, float xe, float ye,
		std::vector<float>& xcp, std::vector<float>ycp, std::vector<int> mbobeats);

	float xEnd;
	float yEnd;

	// control points to render the object (crucial for rendering curves)
	std::vector<float> xControlPoints;
	std::vector<float> yControlPoints;

	// beats
	std::vector<int> beats;
public:
};