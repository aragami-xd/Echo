#pragma once

#include <Echo.h>

namespace OsuTrainer
{
	class Slider : public Echo::Object
	{
	public:
		Slider(std::vector<int> beat);
		virtual int GetScore(int time);
		virtual float GetApproachScale(int time);
		virtual float GetBeatScale(int time);
		~Slider() = default;
	};
}