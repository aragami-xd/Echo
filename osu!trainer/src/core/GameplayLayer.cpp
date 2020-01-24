#include "GameplayLayer.h"
#include <components/OsuScoring.h>
#include <components/circle/CircleParser.h>
#include <components/slider/SliderParser.h>
#include <OsuSettings.h>

OsuTrainer::GameplayLayer::GameplayLayer() :
	Layer("gameplay layer"), mouseX(0), mouseY(0)
{
	LOG_init("gameplay layer");

	// new shaders
	shaders = new Echo::ShaderList();
	shaders->Push("basic", new Echo::Shader(OsuTrainer::settings["shader"]["basicVertex"], OsuTrainer::settings["shader"]["basicFragment"]));
	//shaders->Push("line", new Shader(settings["shader"]["lineVertex"], settings["shader"]["lineFragment"]));

	// set screen ratio for all shaders
	glm::mat4 ratio = glm::ortho(0.0f, (float)Echo::settings["window"]["width"], 0.0f, (float)Echo::settings["window"]["height"]);
	for (auto shader : *shaders)
		Echo::Orthographic::SetProjMatrix(shader.second, ratio);

	// new parser
	parser = new Echo::Parser(OsuTrainer::settings["path"]["beatmapPath"]);
	parser->AddParseFunc("circle", OsuTrainer::CircleParser::CircleParserFunc);
	parser->AddParseFunc("slider", OsuTrainer::SliderParser::SliderParserFunc);

	// parse everything
	LOG_message("parsing");
	while (1)
	{
		Echo::ObjectComponent* oc = parser->Parse();
		if (oc == nullptr)
			break;
		else
			object.push_back(oc);
	}
	LOG_message("parsed total: " + std::to_string(object.size()));

	// scoring system
	scoring = new OsuScoring();
}

void OsuTrainer::GameplayLayer::Update()
{
	// loop through the objects and only render the ones within the time range
	for (int i = objectIterate; i < object.size(); i++)
	{
		int time = Echo::Timing::GetTime();
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

void OsuTrainer::GameplayLayer::OnEvent(Echo::Event& e)
{
	Echo::EventInvoker invoker(e);
	invoker.Invoke<Echo::KeyDownEvent>(EVENT_FUNC(GameplayLayer::Tapping));
	invoker.Invoke<Echo::KeyUpEvent>(EVENT_FUNC(GameplayLayer::Release));
	invoker.Invoke<Echo::MouseMoveEvent>(EVENT_FUNC(GameplayLayer::MouseMove));
}

void OsuTrainer::GameplayLayer::Tapping(Echo::KeyDownEvent& e)
{
	if ((e.GetKey() == OsuTrainer::settings["keymapping"]["key1"] ||
		e.GetKey() == OsuTrainer::settings["keymapping"]["key2"]) && !keyDown)
	{
		keyDown = true;
		int score = object[objectIterate]->OnEvent(mouseX, mouseY, Echo::Timing::GetTime());
		scoring->AddScore(score);
	}
}

void OsuTrainer::GameplayLayer::Release(Echo::KeyUpEvent& e)
{
	keyDown = false;
}

void OsuTrainer::GameplayLayer::MouseMove(Echo::MouseMoveEvent& e)
{
	// flip mouseY bc of y-axis direction
	mouseX = e.GetX();
	mouseY = Echo::settings["window"]["height"] - e.GetY();
}

OsuTrainer::GameplayLayer::~GameplayLayer()
{
	LOG_message("result");
	LOG_message("score: " + std::to_string(scoring->GetScore()));
	LOG_message("highest combo: " + std::to_string(scoring->GetMaxCombo()));

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