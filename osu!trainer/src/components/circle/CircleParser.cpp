#include "CircleParser.h"
using namespace std;

ObjectComponent* CircleParser::CircleParserFunc(stringstream& ss)
{
	ObjectComponent* object = new CircleComponent();
	object->SetSize(settings["metadata"]["scaleCS"] / (float)settings["metadata"]["cs"]);

	// create circle
	string x = "0.0f", y = "0.0f", beat = "0";
	if (!ss.eof()) ss >> x;
	if (!ss.eof()) ss >> y;
	if (!ss.eof()) ss >> beat;
	object->AddObject(new Circle(stof(x), stof(y), stoi(beat)));

	// add render element
	RenderElement* element = new CircleRenderElement(object->GetSize());
	object->AddElement("circle", element);

	return object;
}