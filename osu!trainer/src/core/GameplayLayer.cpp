#include "GameplayLayer.h"
#include <Echo/core/Timing.h>
#include <Settings.h>

#include <components/Circle.h>
using namespace std;

GameplayLayer::GameplayLayer() :
	Layer(std::string("gameplay layer"))
{
	// new shader
	shaders.Push(
		string(settings["shader"]["basic"]),
		new Shader(
			string(settings["shader"]["basicVertex"]),
			string(settings["shader"]["basicFragment"])
		)
	);

	// new parser
	parser = new Parser(settings["path"]["beatmapPath"]);
	parser->AddParseFunc(string("circle"), CircleParser);

	// parse everything
	while (1)
	{
		ObjectComponent* oc = parser->Parse();
		if (oc == nullptr)
			break;
		else
			object.push_back(oc);
	}
	LOG_message(object.size());
}

void GameplayLayer::Update()
{
	// loop through the objects and only render the ones within the time range
	for (int i = objectIterate; i < object.size(); i++)
	{
		if (Timing::GetTime() > object[i]->GetObject()->GetEndTime())			// first object disappears
			objectIterate++;
		else if (Timing::GetTime() < object[i]->GetObject()->GetStartTime())	// last object not yet rendered
			break;
		else
			break;
	}
}

void GameplayLayer::OnEvent(const Event& e)
{
}

GameplayLayer::~GameplayLayer()
{
	delete parser;

	for (auto oc : object)
		delete oc;

	for (auto s : shaders)
		delete s.second;
}
