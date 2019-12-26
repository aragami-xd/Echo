#pragma once

#include <Buffers/Shader.h>

#include "Object.h"

class ObjectRenderer
{
protected:
	// pointer to object
	Object* object{ nullptr };
	float opacity{ 0.0f };

	ObjectRenderer() {};

	// fade in and out animation
	inline virtual void FadeIn() 
	{ 
		opacity += (opacity < 1.0f ? 10 : 0);
	}
	inline virtual void FadeOut()
	{
		opacity -= (opacity > 0.0f ? 10 : 0);
	}

public:
	virtual void Draw(int time, Shader* shader) = 0;
};