#include "Application.h"
using namespace std;

#define EVENT_FUNC(x) bind(&Application::x, this, placeholders::_1)

Application::Application() :
	running(true)
{
	LOG_init("echo");
	window = std::unique_ptr<Window>(Window::Create());
	window->SetEventCallbackFunc(EVENT_FUNC(OnEvent));
}

void Application::CloseWindow(WindowCloseEvent& e)
{
	running = false;
}

void Application::OnEvent(Event& e)
{
	EventInvoker invoker(e);
	invoker.Invoke<WindowCloseEvent>(EVENT_FUNC(CloseWindow));

	for (auto i = layerStack.end(); i != layerStack.begin(); i--)
		i->OnEvent(e);
}

void Application::PushLayer(const Layer& layer)
{
	layerStack.push_back(layer);
}

void Application::PopLayer(std::string& name)
{
	layerStack.push_to_top(name);
	layerStack.pop_back();
}

void Application::PushToFront(std::string& name)
{
	layerStack.push_to_top(name);
}

void Application::Run()
{
	while (running)
	{
		window->Update();
		for (Layer i : layerStack)
			i.Update();
	}
}

Application::~Application()
{
}