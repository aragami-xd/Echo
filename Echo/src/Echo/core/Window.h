#pragma once

#include <EchoHeader.h>
#include <Core.h>
#include <Echo/events/Event.h>

namespace Echo
{
	struct WindowSetting
	{
		WindowSetting(std::string t = "Echo", unsigned int w = 960, unsigned int h = 540) :
			title(t), width(w), height(h)
		{}

		std::string title;
		unsigned int width, height;
	};

	class Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		// update each frame
		virtual void Update() = 0;

		virtual void SetEventCallbackFunc(const EventCallbackFunc& func) = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowSetting& ws = WindowSetting());

		~Window() = default;
	};
}