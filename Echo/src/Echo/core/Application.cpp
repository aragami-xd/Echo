#include "Application.h"
#include "Settings.h"
#include "Timing.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
using namespace std;

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
	window->SetEventCallbackFunc(EVENT_FUNC(Application::OnEvent));
}

void Application::OnEvent(Event& e)
{
	EventInvoker invoker(e);
	invoker.Invoke<WindowCloseEvent>(EVENT_FUNC(Application::CloseWindow));

	for (auto layer = layerStack.rbegin(); layer != layerStack.rend(); layer++)
		(*(*layer)).OnEvent(e);
}

void Application::CloseWindow(WindowCloseEvent& e)
{
	running = false;
}

void Application::PushLayer(Layer* layer)
{
	layerStack.push_back(layer);
}

void Application::PopLayer(const std::string& name)
{
	layerStack.push_to_top(name);
	layerStack.pop_back();
}

void Application::PushToTop(const std::string& name)
{
	layerStack.push_to_top(name);
}

void Application::Run()
{
	// start the timer
	Timing::StartProgram();

	// main body loop
	while (running)
	{
		// clear color
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 0.1f);

		// running each layer
		for (Layer* layer : layerStack)
			layer->Update();

		// swap buffers and polling
		window->Update();
	}
}

Application::~Application()
{
}