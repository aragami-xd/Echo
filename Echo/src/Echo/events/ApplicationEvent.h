#pragma once

#include <Echo/events/Event.h>

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;
	inline virtual EventType GetEventType() const final override { 
		return EventType::WindowClose;
	}
	inline virtual EventCategory GetEventCategory() const final override { 
		return EventCategory::EventCategoryApplication;
	}
};
