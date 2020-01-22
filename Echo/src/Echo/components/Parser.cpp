#include "Parser.h"

Echo::Parser::Parser(const std::string& path)
{
	LOG_init("new parser");
	map.open(path);
	if (!map)
		LOG_warning("path not exist");
}

void Echo::Parser::AddParseFunc(const std::string& type, const ParseFunc& func)
{
	parseFunc.insert({ type, func });
}

void Echo::Parser::RemoveParseFunc(const std::string& name)
{
	if (!parseFunc.erase(name))
		LOG_warning(name + " not found");
}

Echo::ObjectComponent* Echo::Parser::Parse()
{
	// if eof
	if (!getline(map, line))
	{
		return nullptr;
	}
	// else call parser function based on the keyword
	else
	{
		std::stringstream ss(line);
		std::string type;
		ss >> type;
		return parseFunc[type](ss);
	}
}