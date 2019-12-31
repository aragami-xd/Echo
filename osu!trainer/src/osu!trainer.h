#pragma once

#include <Echo.h>

class Program : public Application
{
private:
	// shaders
	ShaderList shaders;

	// parser
	Parser* parser;
	
	// object component vector
	std::vector<ObjectComponent*> object;
public:
	Program();
	~Program();
};

Application* CreateApp()
{
	return new Program();
}