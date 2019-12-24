#pragma once

#include "Event.h"
using namespace std;

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;
	EVENT_CLASS_TYPE(WindowClose);
	EVENT_CLASS_CATEGORY(ApplicationEventCategory);
};

class WindowResizeEvent : public Event
{
private:
	unsigned int width;
	unsigned int height;
public:
	WindowResizeEvent(unsigned int windoww, unsigned windowh) :
		width(windoww), height(windowh)
	{}

	EVENT_CLASS_TYPE(WindowResize);
	EVENT_CLASS_CATEGORY(ApplicationEventCategory);

	inline unsigned int GetWidth() { return width; }
	inline unsigned int GetHeight() { return height; }

	inline virtual string GetEventDetail() final override {
		return (string(GetEventName()) + " " + to_string(width) + " " + to_string(height));
	}
};