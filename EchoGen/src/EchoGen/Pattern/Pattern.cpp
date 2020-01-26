#include "Pattern.h"

EchoGen::Pattern::Pattern(const std::string& path) :
	refDist(0)
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
		std::stringstream ss(line);
		ss >> x;
		ss >> y;
		vertices.push_back(glm::vec4(std::stof(x), std::stof(y), 0.0f, 0.0f));
	}

	// calculate the reference distant
	if (vertices.size() < 2)
	{
		LOG_warning("pattern has 1 vertex only");
	}
	else
	{
		refDist = glm::distance(vertices[0], vertices[1]);
	}
}