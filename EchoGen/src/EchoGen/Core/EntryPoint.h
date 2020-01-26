#pragma once

/* entry point creates the main program for the application */
#ifdef ECHO_GEN_WINDOWS

extern EchoGen::Application* CreateApp();

int main(int argc, char** argv)
{
	auto app = CreateApp();
	app->Run();
	delete app;
}

#endif