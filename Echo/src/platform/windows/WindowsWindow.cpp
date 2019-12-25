#include "WindowsWindow.h"
#include <Echo/events/ApplicationEvent.h>
#include <Echo/events/KeyboardEvent.h>
#include <Echo/events/MouseEvent.h>

using namespace std;

WindowsWindow::WindowsWindow(WindowSetting ws)
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

	// blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
}

void WindowsWindow::InitCallback()
{
	// window functions
	glfwSetWindowCloseCallback(window, [](GLFWwindow* w)
		{

		}
	);
}

void WindowsWindow::OnUpdate()
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