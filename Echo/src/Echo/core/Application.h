#pragma once
#include <EchoHeader.h>

#include <Echo/events/ApplicationEvent.h>
#include <Echo/events/KeyboardEvent.h>
#include <Echo/events/MouseEvent.h>

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

class ECHO_DLL Application
{
private:
	// window of the program
	std::unique_ptr<Window> window;
	bool running;

	// layers
	LayerStack layerStack;

	// calling the event invoker
	void OnEvent(Event& e);

	// close window function
	void CloseWindow(WindowCloseEvent& e);
public:
	Application();

	// run
	void Run();

	// push and pop layer
	void PushLayer(const Layer& layer);
	void PopLayer(std::string& name);
	void PushToTop(std::string& name);

	virtual ~Application();
};

/* create app function defined in the app solution */
Application* CreateApp();
