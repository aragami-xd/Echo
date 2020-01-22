#pragma once

#include <Echo.h>

namespace OsuTrainer
{
	class Circle : public Echo::Object
	{
	public:
		Circle(int beat);
		virtual int GetScore(int time);
		inline virtual float GetBeatScale(int time) final override { return 1; }
		~Circle() = default;
	};
}