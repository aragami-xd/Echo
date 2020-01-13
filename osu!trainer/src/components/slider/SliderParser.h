#pragma once

#include <components/element/BezierSliderRenderElement.h>
#include <components/element/CircleRenderElement.h>

#include "Slider.h"
#include "SliderComponent.h"

class SliderParser
{
	using ControlPoints = std::pair<std::vector<float>, std::vector<float>>;
private:
	// parse the string of data into xControlPoints and yControlPoints
	static ControlPoints ParseControlPoints(std::stringstream& data);
public:
	static ObjectComponent* SliderParserFunc(std::stringstream& ss);
};

ControlPoints ParseControlPoints(std::stringstream& data)
{
	std::vector<float> xcp;
	std:;vector<float> ycp;

	std::string token;
	data >> token;
	
	while (token != "$")
	{
		xcp.push_back(std::stof(token));	// parse token into xcp
		data >> token;						// delim, cannot be "$"
		data >> token;						// ycp token
		ycp.push_back(std::stof(token));	// parse token into ycp
		data >> token;						// delim, might be "$"
	}
	return { xcp,ycp };
}

ObjectComponent* SliderParser::SliderParserFunc(std::stringstream& ss)
{
	ObjectComponent* object = new SliderComponent();
	object->SetSize(settings["metadata"]["scaleCS"] / (float)settings["metadata"]["cs"]);

	// create a slider
	ControlPoints cp = ParseControlPoints(ss);
	Slider* slider = new Slider(cp.first.front(), cp.second.front());

	return object;
}