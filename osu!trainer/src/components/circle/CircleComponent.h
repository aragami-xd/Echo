#pragma once

#include <Echo.h>

namespace OsuTrainer
{
	class CircleComponent : public Echo::ObjectComponent
	{
	public:
		virtual void Render(Echo::ShaderList* shaders, int time);
		virtual int OnEvent(float x, float y, int time);
	};
}