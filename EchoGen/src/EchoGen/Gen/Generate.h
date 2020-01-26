#pragma once

#include <EchoGenCore.h>
#include <EchoGen/Pattern/PatternList.h>

namespace EchoGen
{
	class ECHO_GEN_DLL Generate
	{
	protected:
	public:
		// gen function will write the data onto the map file
		virtual void Gen(PatternList* pattern, std::vector<int>& beat, int& index, std::ofstream& map) = 0;
	};
}