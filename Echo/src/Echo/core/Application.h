#pragma once
#include <EchoHeader.h>
#include <nlohmann/json.hpp>

#include <Echo/events/ApplicationEvent.h>
#include <Echo/events/KeyboardEvent.h>
#include <Echo/events/MouseEvent.h>

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "ShaderList.h"

#include <Echo/components/Parser.h>

using json = nlohmann::json;

class ECHO_DLL Application
{
protected:
	// window of the program
	std::unique_ptr<Window> window;
	WindowSetting ws;
	bool running;
	
	// layers
	LayerStack layerStack;

	// calling the event invoker
	void OnEvent(Event& e);

	// close window function
	inline void CloseWindow(WindowCloseEvent& e) { running = false; }
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
