#include "Pattern.h"

EchoGen::Pattern::Pattern(const std::string& path)
{
	// load the pattern
	std::fstream file(path);
	if (!file)
	{
		LOG_warning("cannot open pattern file: " + path);
		return;
	}

	// parse the pattern
	std::string line;
	std::string x, y;
	while (getline(file, line))
	{
		if (line[0] == '#')		// if the line is not a comment
		{
			std::stringstream ss;
			ss >> x;
			ss >> y;
			vertices.push_back(glm::vec2(stof(x), stof(y)));
		}
	}
}