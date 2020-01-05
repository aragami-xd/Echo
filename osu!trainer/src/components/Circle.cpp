#include "Circle.h"
#include "CircleComponent.h"
#include "CircleRenderElement.h"
#include <Settings.h>
using namespace std;

Circle::Circle(float cx, float cy, int beatTime) :
	Object(cx, cy), beat(beatTime)
{
	startTime = beatTime - approachTime;
	endTime = beatTime + score50;
}

int Circle::GetScore(int time)
{
	time = abs(beat - time);
	if (time < score300)
		return 300;
	else if (time < score100)
		return 100;
	else if (time < score50)
		return 50;
	else
		return 0;	// 0 score is a miss
}

float Circle::GetApproachScale(int time)
{
	return abs(beat - time) / (float)approachTime;
}

// circle parsing function
ObjectComponent* CircleParser(stringstream& ss)
{
	ObjectComponent* object = new CircleComponent();

	// create circle
	string x = "0.0f", y = "0.0f", beat = "0";
	if (!ss.eof()) ss >> x;
	if (!ss.eof()) ss >> y;
	if (!ss.eof()) ss >> beat;
	object->AddObject(new Circle(stof(x), stof(y), stoi(beat)));

	// add render element
	float objectRadius = settings["metadata"]["scaleCS"] / (float)settings["metadata"]["cs"];

	RenderElement* element = new CircleRenderElement(objectRadius);
	object->AddElement("circle", element);

	return object;
}