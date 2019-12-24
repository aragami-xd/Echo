#pragma once

#include "Core.h"
//#include "Window.h"
#include <EchoHeader.h>

class ECHO_DLL Application
{
private:
	//std::unique_ptr<Window> window;
	bool running;
public:
	Application();

	int Run();

	virtual ~Application();
};

/* create app function defined in the app solution */
Application* CreateApp();
