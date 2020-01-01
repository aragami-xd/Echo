#include "osu!trainer.h"

#include <components/Circle.h>
#include <core/StoryboardLayer.h>
#include <core/GameplayLayer.h>
#include <Settings.h>
using namespace std;

Program::Program()
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

	// push a new layer
	PushLayer(StoryboardLayer());
	PushLayer(GameplayLayer());
}

Program::~Program()
{
	delete parser;

	for (ObjectComponent* o : object)
		delete o;

	for (auto s : shaders)
		delete s.second;
}
