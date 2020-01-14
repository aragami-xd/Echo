#pragma once

#include <components/element/CircleRenderElement.h>
#include "CircleComponent.h"
#include "Circle.h"

class CircleParser
{
public:
	// circle parsing function
	static ObjectComponent* CircleParserFunc(std::stringstream& ss);
};