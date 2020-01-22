#include "osu!trainer.h"
#include <core/StoryboardLayer.h>
#include <core/GameplayLayer.h>

OsuTrainer::Program::Program()
{
	// pushing layers
	//PushLayer(new StoryboardLayer());
	PushLayer(new GameplayLayer());
}

OsuTrainer::Program::~Program()
{
}