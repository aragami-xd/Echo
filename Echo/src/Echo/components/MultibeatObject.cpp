#include "MultibeatObject.h"
#pragma once

MultibeatObject::MultibeatObject(float xs, float ys, float xe, float ye,
	std::vector<float>& xcp, std::vector<float> ycp, std::vector<int> mbobeats) :
	Object(xs, ys), xEnd(xe), yEnd(ye), xControlPoints(xcp), yControlPoints(ycp), beats(mbobeats)
{}
