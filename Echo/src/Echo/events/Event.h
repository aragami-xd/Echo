#pragma once

#include <Echo/core/Core.h>
#include <Echo/EchoHeader.h>

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

// a macro automatically defines the event information functions
#define EVENT_CLASS_TYPE(type)\
	virtual EventType GetEventType() const override { return EventType::type; }\
	virtual std::string GetEventName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)\
	virtual EventCategory GetEventCategory() const override  { return EventCategory::category; }
	
// event
class Event
{
public:
	// see if event has been handled or not
	bool Handled = false;
	
	// functions returning information about the event
	virtual EventType GetEventType() const = 0;
	virtual EventCategory GetEventCategory() const = 0;
	virtual std::string GetEventName() const = 0;
	inline virtual std::string GetEventDetail() const {
		return GetEventName();
	}

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
	Event& event;
public:
	EventDispatcher(Event& edEvent) :
		event(edEvent)
	{}

	// if the dispatched event matches the subscribed event then call the function
	template<typename T, typename F>
	bool Dispatch(const F& func)
	{
		if (event.GetEventType() == T::GetEventType())
		{
			event.Handled = func(static_cast<T&>(event));
			return true;
		}
		return false;
	}
};

// inline std::ostream& operator << (std::ostream& os, const Event& e) { return os << e.GetEventDetail(); }