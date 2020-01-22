#include "Application.h"
#include "Settings.h"
#include <Echo/components/Timing.h>

#include <glad/glad.h>
#include <glfw/glfw3.h>

Echo::Application::Application() :
	running(true)
{
	LOG_init("echo");

	// window settings
	ws.width = settings["window"]["width"];
	ws.height = settings["window"]["height"];
	ws.title = settings["window"]["title"];

	// create new window
	window = std::unique_ptr<Window>(Window::Create(ws));
	window->SetEventCallbackFunc(EVENT_FUNC(Echo::Application::OnEvent));
}

void Echo::Application::OnEvent(Event& e)
{
	EventInvoker invoker(e);
	invoker.Invoke<WindowCloseEvent>(EVENT_FUNC(Echo::Application::CloseWindow));

	for (auto layer = layerStack.rbegin(); layer != layerStack.rend(); layer++)
		(*(*layer)).OnEvent(e);
}

void Echo::Application::CloseWindow(WindowCloseEvent& e)
{
	running = false;
}

void Echo::Application::PushLayer(Layer* layer)
{
	layerStack.push_back(layer);
}

void Echo::Application::PopLayer(const std::string& name)
{
	layerStack.push_to_top(name);
	layerStack.pop_back();
}

void Echo::Application::PushToTop(const std::string& name)
{
	layerStack.push_to_top(name);
}

void Echo::Application::Run()
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

Echo::Application::~Application()
{
}