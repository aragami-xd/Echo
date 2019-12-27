#pragma once

#include <EchoHeader.h>

// event type
enum class EventType
{
	None = 0,
	WindowClose,
	MouseDown, MouseUp, MouseMove, MouseWheel,
	KeyDown, KeyUp
};

#define EVENT_CLASS_TYPE(x)\
	static inline EventType StaticEventType() { return EventType::x; }\
	inline virtual EventType GetEventType() final override { return EventType::x; }\

class Event
{
protected:
	Event() = default;
public:
	inline virtual EventType GetEventType() = 0;
};

class EventInvoker
{
private:
	Event& eiEvent;
public:
	EventInvoker(Event& et) :
		eiEvent(et)
	{}

	// comparing the function against the event type
	template<typename T>
	void Invoke(std::function<void(T&)> func)
	{
		if (T::StaticEventType() == eiEvent.GetEventType())
			func(*(T*)&eiEvent);
	}
};