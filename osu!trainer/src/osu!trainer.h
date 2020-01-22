#pragma once

#include <Echo.h>

namespace OsuTrainer
{
	class Program : public Echo::Application
	{
	private:
	public:
		Program();
		~Program();
	};
}

Echo::Application* CreateApp()
{
	return new OsuTrainer::Program();
}