#include "CircleParser.h"
using namespace std;

ObjectComponent* CircleParser::CircleParserFunc(stringstream& ss)
{
	ObjectComponent* object = new CircleComponent();
	object->SetSize(settings["metadata"]["scaleCS"] / (float)settings["metadata"]["cs"]);

	string x, y, beat;
	ss >> x;
	ss >> y;
	ss >> beat;

	object->AddObject(new Circle(stoi(beat)));

	// add render element
	RenderElement* element = new CircleRenderElement(stof(x), stof(y), object->GetSize());
	object->AddElement("circle", element);

	return object;
}