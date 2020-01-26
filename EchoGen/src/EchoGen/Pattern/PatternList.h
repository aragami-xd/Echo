#pragma once

#include "Pattern.h"

namespace EchoGen
{
	/* PatternList will parse a list of patterns from a file */
	class ECHO_GEN_DLL PatternList
	{
		using PList = std::vector<std::pair<std::string, Pattern*>>;
	private:
		// vector of patterns paired with a name
		PList patterns;
	public:
		PatternList(const std::string& name);

		// get pattern by index or name
		Pattern* At(int index);
		Pattern* At(std::string& name);

		// data
		inline int Size() { return patterns.size(); }
		inline PList::iterator Begin() { return patterns.begin(); }
		inline PList::iterator End() { return patterns.end(); }

		~PatternList();
	};
}