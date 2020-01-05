#include "osu!trainer.h"
#include <core/StoryboardLayer.h>
#include <core/GameplayLayer.h>

using namespace std;

Program::Program()
{
	// pushing layers
	PushLayer(new StoryboardLayer());
	PushLayer(new GameplayLayer());
}

Program::~Program()
{
}