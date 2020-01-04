#include "GameplayLayer.h"

#include <Echo/buffers/Orthographic.h>
#include <Echo/core/Timing.h>
#include <Settings.h>

#include <components/Circle.h>
using namespace std;

GameplayLayer::GameplayLayer() :
	Layer("gameplay layer")
{
	LOG_init("gameplay layer");

	// new shader
	shaders = new ShaderList();
	shaders->Push(
		"basic",
		new Shader(
			settings["shader"]["basicVertex"],
			settings["shader"]["basicFragment"]
		)
	);

	// set screen ratio
	Orthographic::SetProjRatio(
		shaders->At("basic"), 
		settings["window"]["width"], 
		settings["window"]["height"]
	);

	// new parser
	parser = new Parser(settings["path"]["beatmapPath"]);
	parser->AddParseFunc("circle", CircleParser);

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
		if (40 > object[i]->GetObject()->GetEndTime())			// first object disappears
			objectIterate++;
		else if (40 < object[i]->GetObject()->GetStartTime())	// last object not yet rendered
			break;
		else
			object[i]->Render(shaders);
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

	for (auto s : *shaders)
		delete s.second;
	delete shaders;
}
