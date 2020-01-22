#pragma once

#include <Echo.h>

namespace OsuTrainer
{
	class OsuScoring : public Echo::Scoring
	{
	public:
		virtual void AddScore(int sscore);
	};
}