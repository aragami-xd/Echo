#pragma once

#include <EchoGen/Gen/Generate.h>

namespace OsuGen
{
	class GenCircle : public EchoGen::Generate
	{
	private:
		// a base distance between circles based on metadata
		float dist;
		float refDist;

		// pattern data
		int patternIndex;
		std::vector<glm::vec4> vertices;
	public:
		virtual void Gen(EchoGen::PatternList* pattern, std::vector<int>& beat, int& index, std::ofstream& map);
	};
}