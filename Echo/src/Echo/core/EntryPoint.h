#pragma once

/* entry point creates the main program for the application */
#ifdef ECHO_WINDOWS

extern Application* CreateApp();

int main(int argc, char** argv)
{
	auto app = CreateApp();
	int exitCode = app->Run();
	delete app;

	return exitCode;
}

#endif