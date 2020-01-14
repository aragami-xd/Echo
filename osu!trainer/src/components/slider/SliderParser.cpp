#include "SliderParser.h"
using namespace std;

pair<vector<float>, vector<float>> SliderParser::ParseControlPoints(stringstream& data)
{
	vector<float> xcp;
	vector<float> ycp;

	string token = "";

	while (token != "$")
	{
		data >> token;						// xcp
		xcp.push_back(stof(token));
		data >> token;						// delim, cannot be "$"
		data >> token;						// ycp
		ycp.push_back(stof(token));
		data >> token;						// delim, might be "$"
	}
	return { xcp,ycp };
}

vector<int> SliderParser::ParseBeat(stringstream& data)
{
	vector<int> beat;
	string token = "";

	while (token != "$")
	{
		data >> token;			// beat
		beat.push_back(stoi(token));
		data >> token;			// delim
	}
	return beat;
}

ObjectComponent* SliderParser::SliderParserFunc(stringstream& ss)
{
	ObjectComponent* object = new SliderComponent();
	float objectSize = settings["metadata"]["scaleCS"] / (float)settings["metadata"]["cs"];
	object->SetSize(objectSize);

	// create slider
	pair<vector<float>, vector<float>> cp = ParseControlPoints(ss);
	vector<int> beat = ParseBeat(ss);
	object->AddObject(new Slider(cp.first.front(), cp.second.front(), beat));

	// add bezier curve
	RenderElement* curve = new BezierSliderRenderElement(cp.first, cp.second, objectSize);
	object->AddElement("curve", curve);

	// add moving circle
	RenderElement * circle = new CircleRenderElement(objectSize);
	object->AddElement("circle", circle);

	return object;
}