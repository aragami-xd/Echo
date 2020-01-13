#include "GameplayLayer.h"
#include <components/OsuScoring.h>
#include <components/circle/CircleParser.h>
#include <components/slider/SliderParser.h>

using namespace std;

GameplayLayer::GameplayLayer() :
	Layer("gameplay layer"), mouseX(0), mouseY(0)
{
	LOG_init("gameplay layer");

	// new shaders
	shaders = new ShaderList();
	shaders->Push("basic", new Shader(settings["shader"]["basicVertex"], settings["shader"]["basicFragment"]));
	//shaders->Push("line", new Shader(settings["shader"]["lineVertex"], settings["shader"]["lineFragment"]));

	// set screen ratio for all shaders
	glm::mat4 ratio = glm::ortho(0.0f, (float)settings["window"]["width"], 0.0f, (float)settings["window"]["height"]);
	for (auto shader : *shaders)
		Orthographic::SetProjMatrix(shader.second, ratio);

	// new parser
	parser = new Parser(settings["path"]["beatmapPath"]);
	parser->AddParseFunc("circle", CircleParser::CircleParserFunc);

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
	LOG_message("parse total: " + to_string(object.size()));

	// scoring system
	scoring = new OsuScoring();
}

void GameplayLayer::Update()
{
	// loop through the objects and only render the ones within the time range
	for (int i = objectIterate; i < object.size(); i++)
	{
		int time = Timing::GetTime();
		if (time > object[i]->GetObject()->GetEndTime())		// first object disappears
		{
			objectIterate++;
			if (!object[i]->IsEnabled())						// set as a miss if the object goes out of scope
				scoring->AddScore(0);
		}
		else if (time < object[i]->GetObject()->GetStartTime())	// last object not yet rendered
			break;
		else
			object[i]->Render(shaders, time);
	}
}

void GameplayLayer::OnEvent(Event& e)
{
	EventInvoker invoker(e);
	invoker.Invoke<KeyDownEvent>(EVENT_FUNC(GameplayLayer::Tapping));
	invoker.Invoke<KeyUpEvent>(EVENT_FUNC(GameplayLayer::Release));
	invoker.Invoke<MouseMoveEvent>(EVENT_FUNC(GameplayLayer::MouseMove));
}

void GameplayLayer::Tapping(KeyDownEvent& e)
{
	if ((e.GetKey() == settings["keymapping"]["key1"] ||
		e.GetKey() == settings["keymapping"]["key2"])  && !keyDown)
	{
		keyDown = true;
		int score = object[objectIterate]->OnEvent(mouseX, mouseY, Timing::GetTime());
		scoring->AddScore(score);
	}
}

void GameplayLayer::Release(KeyUpEvent& e)
{
	keyDown = false;
}

void GameplayLayer::MouseMove(MouseMoveEvent& e)
{
	// flip mouseY bc of y-axis direction
	mouseX = e.GetX();
	mouseY = settings["window"]["height"] - e.GetY();
}

GameplayLayer::~GameplayLayer()
{
	LOG_message("result");
	LOG_message("score: " + to_string(scoring->GetScore()));
	LOG_message("highest combo: " + to_string(scoring->GetMaxCombo()));

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

	// delete scoring
	delete scoring;
}