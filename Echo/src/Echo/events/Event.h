#pragma once

#include <EchoHeader.h>

// event type
enum class EventType
{
	None = 0,
	WindowClose, WindowResize,
	MouseDown, MouseUp, MouseMove, MouseWheel,
	KeyDown, KeyUp
};

enum class EventCategory
{
	None = 0,
	ApplicationEventCategory,
	MouseButtonEventCategory,
	MouseEventCategory,
	KeyEventCategory,
};

#define EVENT_CLASS_TYPE(type)\
	inline virtual EventType GetEventType() final override { return EventType::type; }\
	inline virtual char* GetEventName() final override { return #type; }

#define EVENT_CLASS_CATEGORY(category)\
	inline virtual EventCategory GetEventCategory() final override { return EventCategory::category; }

class Event
{
public:
	bool handled = false;

	inline virtual EventType GetEventType() = 0;
	inline virtual EventCategory GetEventCategory() = 0;
	inline virtual char* GetEventName() = 0;
	inline virtual std::string GetEventDetail() { return GetEventName(); }

	inline bool IsCategory(EventCategory category) {
		return GetEventCategory() == category;
	}
};

class EventDispatcher
{
private:
	Event& e;
public:
	EventDispatcher(Event& et) :
		e(et)
	{}
};