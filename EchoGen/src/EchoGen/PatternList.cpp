#include "PatternList.h"
using namespace std;

PatternList::PatternList(const std::string& path, const string& extension)
{
	// open the file
	ifstream file(path);
	if (!file)
	{
		LOG_warning("cannot open patternlist file: " + path);
		return;
	}

	// parse the file and create the patterns
	string line;
	while (getline(file, line))
	{
		patterns.push_back({ line, new Pattern(line + "." + extension) });
	}
}

Pattern* PatternList::operator[](int index)
{
	return patterns[index].second;
}

Pattern* PatternList::operator[](string& name)
{
	for (int i = 0; i < patterns.size(); i++)
		if (patterns[i].first == name)
			return patterns[i].second;
}

PatternList::~PatternList()
{
	for (int i = 0; i < patterns.size(); i++)
		delete patterns[i].second;
}
