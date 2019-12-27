#include <Echo.h>

class Program : public Application
{
public:
	Program() /*= default;*/
	{
		PushLayer(Layer layer = Layer());
	}

	void Click(MouseDownEvent& e);

	~Program() = default;
};

Application* CreateApp()
{
	return new Program();
}