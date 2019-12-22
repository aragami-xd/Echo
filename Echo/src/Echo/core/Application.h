#pragma once

#include "Core.h"

class ECHO_API Application
{
public:
	Application();

	int Run();

	virtual ~Application();
};

/* create app function defined in the app solution */
Application* CreateApp();