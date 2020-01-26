#pragma once

#include <EchoGenCore.h>
#include <EchoGenHeader.h>

namespace EchoGen
{
	class ECHO_GEN_DLL Application
	{
	protected:
	public:
		Application();
		virtual void Run();
		~Application();
	};
}

/* create app function defined in the app solution */
EchoGen::Application* CreateApp();