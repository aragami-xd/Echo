#pragma once

#include <Echo/core/Window.h>
#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace Echo
{
	class WindowsWindow : public Echo::Window
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

		// initialize callback function
		void InitCallback();
	public:
		// initialize window
		WindowsWindow(const WindowSetting& ws = WindowSetting());

		virtual void Update() override;

		inline virtual void SetEventCallbackFunc(const EventCallbackFunc& func) final override { wd.func = func; }
		inline virtual void* GetNativeWindow() const final override { return window; }
		inline virtual unsigned int GetWidth() const final override { return wd.width; }
		inline virtual unsigned int GetHeight() const final override { return wd.height; }

		~WindowsWindow();
	};
}
