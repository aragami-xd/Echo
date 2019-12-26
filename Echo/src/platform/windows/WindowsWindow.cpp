#include "WindowsWindow.h"
#include <Echo/events/ApplicationEvent.h>
#include <Echo/events/KeyboardEvent.h>
#include <Echo/events/MouseEvent.h>

using namespace std;

Window* Window::Create(const WindowSetting& ws)
{
	return new WindowsWindow(ws);
}

WindowsWindow::WindowsWindow(const WindowSetting& ws)
{
	wd.width = ws.width;
	wd.height = ws.height;
	wd.title = ws.title;

	// glfw hints
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_VERSION_MAJOR, 4);

	// initialize a new window
	if (!glfwInit())
	{
		glfwSetErrorCallback([](int error, const char* message) { LOG_error(message); });
	}

	window = glfwCreateWindow(wd.width, wd.height, wd.title.data(), nullptr, nullptr);
	if (!window)
	{
		glfwSetErrorCallback([](int error, const char* message) { LOG_error(message); });
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, &wd);

	// blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	// initialize callback functions
	InitCallback();
}

void WindowsWindow::InitCallback()
{
	// window functions
	glfwSetWindowCloseCallback(window, [](GLFWwindow* w)
		{
			WindowData& wd = *(WindowData*)glfwGetWindowUserPointer(w);
			WindowCloseEvent event;
			wd.func(event);
		}
	);

	// keyboard functions
	glfwSetKeyCallback(window, [](GLFWwindow* w, int key, int scancode, int action, int mods)
		{
			WindowData& wd = *(WindowData*)glfwGetWindowUserPointer(w);
			switch (action)
			{
				case(GLFW_PRESS):
				{
					KeyDownEvent event((char)key, 0);
					wd.func(event);
					break;
				}
				case(GLFW_REPEAT):
				{
					KeyDownEvent event((char)key, 1);
					wd.func(event);
					break;
				}
				case(GLFW_RELEASE):
				{
					KeyUpEvent event((char)key);
					wd.func(event);
					break;
				}
			}
		}
	);

	// mouse functions
	glfwSetMouseButtonCallback(window, [](GLFWwindow* w, int button, int action, int mods)
		{
			WindowData& wd = *(WindowData*)glfwGetWindowUserPointer(w);
			switch (action)
			{
				case(GLFW_PRESS):
				{
					MouseDownEvent event(button);
					wd.func(event);
					break;
				}
				case(GLFW_RELEASE):
				{
					MouseUpEvent event(button);
					wd.func(event);
					break;
				}
			}
		}
	);

	glfwSetCursorPosCallback(window, [](GLFWwindow* w, double x, double y)
		{
			WindowData& wd = *(WindowData*)glfwGetWindowUserPointer(w);
			MouseMoveEvent event((float)x, (float)y);
			wd.func(event);
		}
	);

	glfwSetScrollCallback(window, [](GLFWwindow* w, double x, double y)
		{
			WindowData& wd = *(WindowData*)glfwGetWindowUserPointer(w);
			MouseWheelEvent event((float)x, (float)y);
			wd.func(event);
		}
	);
}

void WindowsWindow::Update()
{
	// swap buffers and poll for events
	glfwSwapBuffers(window);
	glfwPollEvents();
}

WindowsWindow::~WindowsWindow()
{
	LOG_message("terminate program");
	glfwTerminate();
}