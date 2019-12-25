#include "Application.h"
#include <platform/windows/WindowsWindow.h>
using namespace std;

Application::Application() :
	running(true)
{
	LOG_init("init program");
	window = unique_ptr<Window>(new WindowsWindow());
	LOG_init("init program sucessful");
}

/* this acts as main.cpp */
int Application::Run()
{
	while (true)
	{
		window->OnUpdate();
	}
}

Application::~Application()
{
}