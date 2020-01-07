#pragma once

#include <Echo.h>

class CircleComponent : public ObjectComponent
{
public:
	virtual void Render(ShaderList* shaders, int time);
	virtual int OnEvent(float x, float y);
};