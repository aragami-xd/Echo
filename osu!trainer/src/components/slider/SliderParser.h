#pragma once

#include <components/element/BezierSliderRenderElement.h>
#include <components/element/CircleRenderElement.h>

#include "Slider.h"
#include "SliderComponent.h"

class SliderParser
{
private:
	// parse the string of data into xControlPoints and yControlPoints
	static std::pair<std::vector<float>, std::vector<float>> ParseControlPoints(std::stringstream& data);

	// parse the beats
	static std::vector<int> ParseBeat(std::stringstream& data);
public:
	static ObjectComponent* SliderParserFunc(std::stringstream& ss);
};