#include "Application.h"
#include "Settings.h"

#include <glad/glad.h>
#include "Timing.h"
using namespace std;

#define EVENT_FUNC(x) bind(&Application::x, this, placeholders::_1)

Application::Application() :
	running(true)
{
	LOG_init("echo");
	
	// window settings
	ws.width = settings["window"]["width"];
	ws.height = settings["window"]["height"];
	ws.title = settings["window"]["title"];

	// create new window
	window = std::unique_ptr<Window>(Window::Create(ws));
	window->SetEventCallbackFunc(EVENT_FUNC(OnEvent));
}

void Application::OnEvent(Event& e)
{
	EventInvoker invoker(e);
	invoker.Invoke<WindowCloseEvent>(EVENT_FUNC(CloseWindow));

	for (auto layer = layerStack.rbegin(); layer != layerStack.rend(); layer++)
		(*(*layer)).OnEvent(e);
}

void Application::PushLayer(Layer* layer)
{
	layerStack.push_back(layer);
}

void Application::PopLayer(std::string& name)
{
	layerStack.push_to_top(name);
	layerStack.pop_back();
}

void Application::PushToTop(std::string& name)
{
	layerStack.push_to_top(name);
}

void Application::Run()
{
	// main body loop
	while (running)
	{
		// update the time
		Timing::Refresh();

		// prepare window for the next frame and update each layer
		window->Update();
		for (Layer* layer : layerStack)
			layer->Update();
	}
}

Application::~Application()
{
}