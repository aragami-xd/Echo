#pragma once

#include "Pattern.h"

/* PatternList will parse a list of patterns from a file */
class PatternList
{
private:
	// vector of patterns paired with a name
	std::vector<std::pair<std::string, Pattern*>> patterns;
public:
	PatternList(const std::string& path, const std::string& extension = "txt");
	
	// get pattern by index or name
	Pattern* operator[](int index);
	Pattern* operator[](std::string& name);

	~PatternList();
};