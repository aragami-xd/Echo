#pragma once

#include "Event.h"

// key event
class KeyEvent : public Event
{
protected:
	KeyEvent(char keyInput) :
		key(keyInput)
	{}

	char key;
public:
	inline virtual EventCategory GetEventCategory() const final override { 
		return EventCategory::EventCategoryKeyboard;
	}

	inline char GetKey() { return key; }
};

// key pressed event
class KeyDownEvent : public KeyEvent
{
private:
	int count;
public:
	KeyDownEvent(char keyInput, int keyCount) :
		KeyEvent(keyInput), count(keyCount)
	{}

	inline virtual EventType GetEventType() const final override { 
		return EventType::KeyDown;
	}

	inline int GetKeyCount() { return count; }
};

// key released event
class KeyUpEvent : public KeyEvent
{
public:
	KeyUpEvent(char keyInput) :
		KeyEvent(keyInput)
	{}

	inline virtual EventType GetEventType() const final override { 
		return EventType::KeyUp;
	}
};