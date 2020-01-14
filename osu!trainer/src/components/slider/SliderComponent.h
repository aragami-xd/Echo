#pragma once

#include "Slider.h"
#include <components/element/BezierSliderRenderElement.h>
#include <components/element/CircleRenderElement.h>

class SliderComponent : public ObjectComponent
{
public:
	virtual void Render(ShaderList* shaders, int time);
	virtual int OnEvent(float x, float y, int time);
};