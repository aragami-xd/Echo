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
}

void Application::Run()
{
	while (running)
	{
		window->Update();
	}
}

Application::~Application()
{
}