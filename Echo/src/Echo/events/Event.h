#pragma once

#include <Echo/core/Core.h>
#include <EchoHeader.h>

/* the event system is running on blocking mechanics: halt the program and execute the event */

// event types: window, keyboard (key) and mouse
enum class EventType
{
	None = 0,
	WindowClose,
	KeyDown, KeyUp,
	MouseDown, MouseUp, MouseMove, MouseWheel
};

// event categories. using bitfield so an event can have more than 1 category
enum class EventCategory
{
	None = 0,
	EventCategoryApplication,
	EventCategoryMouse,
	EventCategoryMouseButton,
	EventCategoryKeyboard
};

// event
class Event
{
public:
	// see if event has been handled or not
	bool Handled = false;

	// functions returning information about the event
	virtual EventType GetEventType() const = 0;
	virtual EventCategory GetEventCategory() const = 0;

	// check to see if an event belongs to a certain category or not
	inline bool IsInCategory(EventCategory category)
	{
		return (GetEventCategory() == category ? true : false);
	}
};

// event disapatcher
class EventDispatcher
{
private:
public:

};

// inline std::ostream& operator << (std::ostream& os, const Event& e) { return os << e.GetEventDetail(); }