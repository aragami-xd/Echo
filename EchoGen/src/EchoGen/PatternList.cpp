#include "PatternList.h"

EchoGen::PatternList::PatternList(const std::string& path, const std::string& extension)
{
	// open the file
	std::ifstream file(path);
	if (!file)
	{
		LOG_warning("cannot open patternlist file: " + path);
		return;
	}

	// parse the file and create the patterns
	std::string line;
	while (getline(file, line))
	{
		patterns.push_back({ line, new EchoGen::Pattern(line + "." + extension) });
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