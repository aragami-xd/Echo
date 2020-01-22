#pragma once
#include <EchoHeader.h>

#include <Echo/events/ApplicationEvent.h>
#include <Echo/events/KeyboardEvent.h>
#include <Echo/events/MouseEvent.h>

#include <Core.h>

#include "Window.h"
#include "LayerStack.h"

namespace Echo
{
#define EVENT_FUNC(x) bind(&x, this, std::placeholders::_1)

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

		// close window event function
		void CloseWindow(WindowCloseEvent& e);
	public:
		Application();

		// run
		void Run();

		// push and pop layer
		void PushLayer(Layer* layer);
		void PopLayer(const std::string& name);
		void PushToTop(const std::string& name);

		virtual ~Application();
	};
}

/* create app function defined in the app solution */
Echo::Application* CreateApp();