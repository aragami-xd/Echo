#include "CircleParser.h"

Echo::ObjectComponent* OsuTrainer::CircleParser::CircleParserFunc(std::stringstream& ss)
{
	Echo::ObjectComponent* object = new CircleComponent();
	object->SetSize(Echo::settings["metadata"]["scaleCS"] / (float)Echo::settings["metadata"]["cs"]);

	std::string x, y, beat;
	ss >> x;
	ss >> y;
	ss >> beat;

	object->AddObject(new Circle(stoi(beat)));

	// add render element
	Echo::RenderElement* element = new OsuTrainer::CircleRenderElement(stof(x), stof(y), object->GetSize());
	object->AddElement("circle", element);

	return object;
}