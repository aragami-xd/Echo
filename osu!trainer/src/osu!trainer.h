#pragma once

#include <Echo.h>

class Program : public Application
{
private:
public:
	Program();
	~Program();
};

Application* CreateApp()
{
	return new Program();
}