#pragma once

#include "Object.h"
#include "ObjectRenderer.h"

/* object component consists of an object and a renderer */
struct ObjectComponent
{
	ObjectComponent(Object* oObject, ObjectRenderer* oObjectRenderer) :
		object(oObject), objectRenderer(oObjectRenderer)
	{}

	Object* object;
	ObjectRenderer* objectRenderer;

	~ObjectComponent()
	{
		delete object;
		delete objectRenderer;
	}
};