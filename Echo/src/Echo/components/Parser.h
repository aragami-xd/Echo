#pragma once

#include <EchoHeader.h>
#include "ObjectComponent.h"

class ECHO_DLL Parser
{
	using ParseFunc = std::function<ObjectComponent * (std::stringstream&)>;
private:
	std::fstream map;
	std::string line;

	// individual parser functions
	std::unordered_map<std::string, ParseFunc> parseFunc;
public:
	Parser(const std::string& path);

	void AddParseFunc(const std::string& type, const ParseFunc& func);
	void RemoveParseFunc(const std::string& name);

	ObjectComponent* Parse();
};