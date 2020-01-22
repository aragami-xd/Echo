#pragma once

#include "Pattern.h"

namespace EchoGen
{
	/* PatternList will parse a list of patterns from a file */
	class ECHO_GEN_DLL PatternList
	{
	private:
		// vector of patterns paired with a name
		std::vector<std::pair<std::string, Pattern*>> patterns;
	public:
		PatternList(const std::string& path, const std::string& extension = "txt");

		// get pattern by index or name
		Pattern* At(int index);
		Pattern* At(std::string& name);

		~PatternList();
	};
}