#include <Echo.h>

class Program : public Application
{
public:
	Program() = default;
	~Program() = default;
};

Application* CreateApp()
{
	return new Program();
}