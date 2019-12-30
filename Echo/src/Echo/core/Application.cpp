#include "Application.h"

#include <glad/glad.h>
using namespace std;

#define EVENT_FUNC(x) bind(&Application::x, this, placeholders::_1)

Application::Application() :
	running(true)
{
	LOG_init("echo");
	window = std::unique_ptr<Window>(Window::Create(ws));
	window->SetEventCallbackFunc(EVENT_FUNC(OnEvent));
}

void Application::OnEvent(Event& e)
{
	EventInvoker invoker(e);
	invoker.Invoke<WindowCloseEvent>(EVENT_FUNC(CloseWindow));

	for (auto layer = layerStack.rbegin(); layer != layerStack.rend(); layer++)
		layer->OnEvent(e);
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

void Application::PushToTop(std::string& name)
{
	layerStack.push_to_top(name);
}

void Application::Run()
{
	while (running)
	{
		window->Update();

		for (Layer layer : layerStack)
			layer.Update();
	}
}

Application::~Application()
{
}