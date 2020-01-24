#pragma once

#include <EchoGenHeader.h>
#include <EchoGenCore.h>

namespace EchoGen
{
	class ECHO_GEN_DLL Application
	{
	protected:
	public:
		Application();

		// run
		virtual void Run();

		~Application();
	};
}