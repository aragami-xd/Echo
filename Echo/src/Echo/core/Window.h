#pragma once

#include <EchoHeader.h>
#include <Echo/core/Core.h>
#include <Echo/events/Event.h>

struct WindowSetting
{
	std::string Title;
	unsigned int Width;
	unsigned int Height;

	// constructor and default setting
	WindowSetting(
		const std::string& title = "Echo",
		const unsigned int width = 1280,
		const unsigned int height = 720) :
		Title(title), Width(width), Height(height)
	{}
};

class ECHO_DLL Window
{
public:

};