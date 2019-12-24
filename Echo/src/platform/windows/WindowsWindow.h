#pragma once

#include <Echo/core/Window.h>
#include <glfw/glfw3.h>

class WindowsWindow : public Window
{
private:
	GLFWwindow* window;

	// contain data in that window
	struct WindowData
	{
		std::string title;
		unsigned int width;
		unsigned int height;
		EventCallbackFunc func;
	};
	WindowData wd;

public:
	// initialize window
	WindowsWindow(WindowSetting ws = WindowSetting());

	virtual void OnUpdate() override;

	inline virtual void SetEventCallback(const EventCallbackFunc& func) final override { wd.func = func; }
	inline virtual void* GetNativeWindow() final override { return window; }
	inline virtual unsigned int GetWidth() final override { return wd.width; }
	inline virtual unsigned int GetHeight() final override { return wd.height; }

	~WindowsWindow();
};
