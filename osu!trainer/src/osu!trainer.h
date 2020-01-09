#pragma once

#include <Echo.h>

class Program : public Application
{
private:
public:
	Program();
	~Program();
};

/* run the program */
#ifdef ECHO_WINDOWS

int main(int argc, char** argv)
{
	/* for fun only */
#ifdef ECHO_RELEASE
	std::cout << "Welcome to osu!" << std::endl;
#endif

	HINSTANCE EchoDll = LoadLibraryA("C:\\Users\\Rogue\\source\\repos\\Echo\\bin\\Release-windows\\osu!trainer\\Echo.dll");
	if (!EchoDll)
	{
		std::cout << "cannot load library" << std::endl;
		return -1;
	}

	/* run the program once library is loaded */
	Application* app = new Program();
	app->Run();
	delete app;
	return 0;
}

#endif