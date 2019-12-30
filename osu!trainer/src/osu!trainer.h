#pragma once

#include <Echo.h>
#include <core/StoryboardLayer.h>

class Program : public Application
{
private:
	// settings json
	json settings;

	// shaders
	ShaderList shaders;

	// parser
	Parser* parser;
	
	// object vector
	std::vector<Object*> object;
public:
	Program();
	~Program();
};

Application* CreateApp()
{
	return new Program();
}