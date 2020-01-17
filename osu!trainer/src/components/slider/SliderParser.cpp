#include "SliderParser.h"
using namespace std;

pair<vector<float>, vector<float>> SliderParser::ParseControlPoints(stringstream& data)
{
	vector<float> xcp;
	vector<float> ycp;
	string token = "";

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

vector<int> SliderParser::ParseBeat(stringstream& data)
{
	vector<int> beat;
	string token = "";

	data >> token;
	while (token != "|")
	{
		beat.push_back(stoi(token));	// beat
		data >> token;
	}
	return beat;
}

ObjectComponent* SliderParser::SliderParserFunc(stringstream& ss)
{
	ObjectComponent* object = new SliderComponent();
	float objectSize = settings["metadata"]["scaleCS"] / (float)settings["metadata"]["cs"];
	object->SetSize(objectSize);

	// parse
	pair<vector<float>, vector<float>> cp = ParseControlPoints(ss);
	vector<int> beat = ParseBeat(ss);

	// create slider
	object->AddObject(new Slider(beat));

	// add bezier curve
	RenderElement* curve = new BezierSliderRenderElement(cp.first, cp.second, objectSize);
	object->AddElement("curve", curve);

	// add moving circle
	RenderElement* circle = new CircleRenderElement(cp.first.front(), cp.second.front(), objectSize);
	object->AddElement("circle", circle);

	return object;
}