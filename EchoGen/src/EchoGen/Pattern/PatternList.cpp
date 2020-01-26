#include "PatternList.h"

EchoGen::PatternList::PatternList(const std::string& name)
{
	// open the file
	std::string libPath = std::filesystem::current_path().string() + "/lib/";
	std::ifstream file(libPath + name);
	if (!file)
	{
		LOG_warning("cannot open patternlist file: " + name);
		return;
	}

	// parse the file and create the patterns
	std::string line;
	while (getline(file, line))
	{
		patterns.push_back({ line, new EchoGen::Pattern(libPath + line + ".txt") });
	}
}

EchoGen::Pattern* EchoGen::PatternList::At(int index)
{
	return patterns[index].second;
}

EchoGen::Pattern* EchoGen::PatternList::At(std::string& name)
{
	for (int i = 0; i < patterns.size(); i++)
		if (patterns[i].first == name)
			return patterns[i].second;
}

EchoGen::PatternList::~PatternList()
{
	for (int i = 0; i < patterns.size(); i++)
		delete patterns[i].second;
}