#include "SliderParser.h"

std::pair<std::vector<float>, std::vector<float>> OsuTrainer::SliderParser::ParseControlPoints(std::stringstream& data)
{
	std::vector<float> xcp;
	std::vector<float> ycp;
	std::string token = "";

	data >> token;
	while (token != "|")
	{
		xcp.push_back(stof(token));		// xcp
		data >> token;
		ycp.push_back(stof(token));		// ycp
		data >> token;
	}
	return { xcp,ycp };
}

std::vector<int> OsuTrainer::SliderParser::ParseBeat(std::stringstream& data)
{
	std::vector<int> beat;
	std::string token = "";

	data >> token;
	while (token != "|")
	{
		beat.push_back(stoi(token));	// beat
		data >> token;
	}
	return beat;
}

Echo::ObjectComponent* OsuTrainer::SliderParser::SliderParserFunc(std::stringstream& ss)
{
	Echo::ObjectComponent* object = new SliderComponent();
	float objectSize = Echo::settings["metadata"]["scaleCS"] / (float)Echo::settings["metadata"]["cs"];
	object->SetSize(objectSize);

	// parse
	std::pair<std::vector<float>, std::vector<float>> cp = ParseControlPoints(ss);
	std::vector<int> beat = ParseBeat(ss);

	// create slider
	object->AddObject(new Slider(beat));

	// add bezier curve
	Echo::RenderElement* curve = new BezierSliderRenderElement(cp.first, cp.second, objectSize);
	object->AddElement("curve", curve);

	// add moving circle
	Echo::RenderElement* circle = new CircleRenderElement(cp.first.front(), cp.second.front(), objectSize);
	object->AddElement("circle", circle);

	return object;
}