#pragma once

#include <Echo.h>
#include <core/StoryboardLayer.h>

class Program : public Application
{
public:
	Program();
	~Program() = default;
};

Application* CreateApp()
{
	return new Program();
}