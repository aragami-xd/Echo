#pragma once

#include <Echo/components/ObjectComponent.h>
#include <Settings.h>

class CircleComponent : public ObjectComponent
{
public:
	virtual void Render(ShaderList* shaders, int time);
	virtual int OnEvent(float x, float y);
};