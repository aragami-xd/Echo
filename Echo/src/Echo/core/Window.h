#pragma once

#include <EchoHeader.h>
#include <Echo/core/Core.h>
#include <Echo/events/Event.h>

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
	virtual void OnUpdate() = 0;

	// set the event callback function
	virtual void SetEventCallback(const EventCallbackFunc& func) = 0;

	virtual unsigned int GetWidth() = 0;
	virtual unsigned int GetHeight() = 0;
	virtual void* GetNativeWindow() = 0;

	virtual ~Window() = default;
};