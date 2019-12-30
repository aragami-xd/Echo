#include "Parser.h"
using namespace std;

Parser::Parser(std::string path)
{
	try
	{
		map.open(path);
	}
	catch (ifstream::failure e)
	{
		LOG_warning(e.what());
	}
}

void Parser::AddParseFunc(std::string& type, const std::function<Object * (std::stringstream&)>& func)
{
	parseFunc.insert({ type, func });
}

void Parser::RemoveParseFunc(std::string& name)
{
	if (!parseFunc.erase(name))
		LOG_warning(name + " not found");
}

Object* Parser::Parse()
{
	// if eof
	if (!getline(map, line))
	{
		return nullptr;
	}
	// else call parser function based on the keyword
	else
	{
		stringstream ss(line);
		string type;
		ss >> type;
		parseFunc[type](ss);
	}
}


