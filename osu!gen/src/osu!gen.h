#pragma once

#include <EchoGen.h>

namespace OsuGen
{
	class Program : public EchoGen::Application
	{
	private:
	public:
	};
}

EchoGen::Application* CreateApp()
{
	return new OsuGen::Program();
}