#pragma once

#include <Echo/events/Event.h>

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;
	EVENT_CLASS_TYPE(WindowClose);
	EVENT_CLASS_CATEGORY(EventCategoryApplication);
};
