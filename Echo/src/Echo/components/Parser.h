#pragma once

#include <EchoHeader.h>
#include "Object.h"

// parser functions
using ParseFunc = std::unordered_map<std::string, std::function<Object * (std::stringstream&)>>;

class ECHO_DLL Parser
{
private:
	std::fstream map;
	std::string line;

	// individual parser functions
	ParseFunc parseFunc;
public:
	Parser(std::string path);

	void AddParseFunc(std::string& type, const std::function<Object * (std::stringstream&)>& func);
	void RemoveParseFunc(std::string& name);

	Object* Parse();
};