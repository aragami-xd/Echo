#pragma once

#include <components/element/CircleRenderElement.h>
#include "CircleComponent.h"
#include "Circle.h"

namespace OsuTrainer
{
	class CircleParser
	{
	public:
		// circle parsing function
		static Echo::ObjectComponent* CircleParserFunc(std::stringstream& ss);
	};
}