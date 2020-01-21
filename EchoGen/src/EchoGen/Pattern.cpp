#include "Pattern.h"
using namespace std;

Pattern::Pattern(const string& path)
{
	// load the pattern
	fstream file(path);
	if (!file)
	{
		LOG_warning("cannot open pattern file: " + path);
		return;
	}

	// parse the pattern
	string line;
	string x,y;
	while (getline(file, line))
	{
		if (line[0] == '#')		// if the line is not a comment	
		{
			stringstream ss;
			ss >> x;
			ss >> y;
			vertices.push_back(glm::vec2(stof(x), stof(y)));
		}
	}
}
