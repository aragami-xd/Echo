#pragma once

#include "Event.h"

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;
	EVENT_CLASS_TYPE(WindowClose);
};