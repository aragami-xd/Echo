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

	// set screen ratio for the basic shader
	glm::mat4 ratio = glm::ortho(0.0f, (float)settings["window"]["width"], 0.0f, (float)settings["window"]["height"]);
	Orthographic::SetProjMatrix(shaders->At("basic"), ratio);

	// new parser
	parser = new Parser(settings["path"]["beatmapPath"]);
	parser->AddParseFunc("circle", CircleParser);

	// parse everything
	LOG_message("parsing");
	while (1)
	{
		ObjectComponent* oc = parser->Parse();
		if (oc == nullptr)
			break;
		else
			object.push_back(oc);
	}
	LOG_message("parse total: " + object.size());
}

void GameplayLayer::Update()
{
	// loop through the objects and only render the ones within the time range
	for (int i = objectIterate; i < object.size(); i++)
	{
		int time = Timing::GetTime();
		if (time > object[i]->GetObject()->GetEndTime())			// first object disappears
			objectIterate++;
		else if (time < object[i]->GetObject()->GetStartTime())	// last object not yet rendered
			break;
		else
			object[i]->Render(shaders, time);
	}
}

void GameplayLayer::OnEvent(const Event& e)
{
}

GameplayLayer::~GameplayLayer()
{
	LOG_erase("erase gameplay layer");

	// delete parser
	delete parser;

	// delete everything inside objectComponent
	for (auto oc : object)
	{
		delete oc->GetObject();
		for (auto e = oc->ElementBegin(); e != oc->ElementEnd(); e++)
			delete& e;
	}

	// delete shaders
	for (auto shader : *shaders)
		delete shader.second;
	delete shaders;
}