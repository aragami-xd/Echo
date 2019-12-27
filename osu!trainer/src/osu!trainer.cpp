#include <Echo.h>
#include "StoryboardLayer.h"

class Program : public Application
{
private:
public:
	Program()
	{
		PushLayer(StoryboardLayer());
	}

	~Program() = default;
};

Application* CreateApp()
{
	return new Program();
}