#include "osu!trainer.h"

#include <components/Circle.h>
using namespace std;

Program::Program() 
{
	// parse the settings.json file
	ifstream data(filesystem::current_path().string() + "/../Echo/src/Settings.json");
	settings = json::parse(data);

	// window settings
	ws.width = settings["window"]["width"];
	ws.height = settings["window"]["height"];
	ws.title = settings["window"]["title"];

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

	// push a new layer
	PushLayer(StoryboardLayer());
}

Program::~Program()
{
	delete parser;

	for (Object* o : object)
		delete o;

	for (auto s : shaders)
		delete s.second;
}
