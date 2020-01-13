#pragma once

#include "Slider.h"
#include "BezierSliderRenderElement.h"
#include "CircleRenderElement.h"

class SliderComponent : public ObjectComponent
{
public:
	virtual void Render(ShaderList* shaders, int time);
	virtual int OnEvent(float x, float y, int time);
};