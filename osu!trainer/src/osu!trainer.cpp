#include <Echo.h>

class Program : public Application
{
public:
	Program() {}
	~Program() {}
};

Application* CreateApp()
{
	return new Program();
}