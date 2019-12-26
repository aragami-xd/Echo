#pragma once

#include "Core.h"
#include "Window.h"
#include <EchoHeader.h>

#include <Echo/events/ApplicationEvent.h>
#include <Echo/events/KeyboardEvent.h>
#include <Echo/events/MouseEvent.h>

class ECHO_DLL Application
{
private:
	// window of the program
	std::unique_ptr<Window> window;
	bool running;

	// event queue
	std::vector<std::function<void(Event&)>> eventQueue;
	
	// calling the event invoker
	void OnEvent(Event& e);

	// close window function
	void CloseWindow(WindowCloseEvent& e);
public:
	Application();

	void Run();

	virtual ~Application();
};

/* create app function defined in the app solution */
Application* CreateApp();
