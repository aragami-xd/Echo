#pragma once

#include "Slider.h"
#include <components/element/BezierSliderRenderElement.h>
#include <components/element/CircleRenderElement.h>

namespace OsuTrainer
{
	class SliderComponent : public Echo::ObjectComponent
	{
	public:
		virtual void Render(Echo::ShaderList* shaders, int time);
		virtual int OnEvent(float x, float y, int time);
	};
}