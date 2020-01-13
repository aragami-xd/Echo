#pragma once
#include "Slider.h"
#include "BezierSliderRenderElement.h"
#include "CircleRenderElement.h"

struct SliderParser
{
	static ObjectComponent* SliderParserFunc(std::stringstream& ss);
};

ObjectComponent* SliderParser::SliderParserFunc(std::stringstream& ss)
{

}