#include "Application.h"
using namespace std;

Application::Application() :
	running(true)
{
	//window = unique_ptr<Window>();
}

/* this acts as main.cpp */
int Application::Run()
{
	while (true)
	{
		//window->OnUpdate();
	}
}

Application::~Application()
{
}