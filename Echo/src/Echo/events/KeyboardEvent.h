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
	EVENT_CLASS_CATEGORY(EventCategoryKeyboard);

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

	EVENT_CLASS_TYPE(KeyDown);

	inline int GetKeyCount() { return count; }
};

// key released event
class KeyUpEvent : public KeyEvent
{
public:
	KeyUpEvent(char keyInput) :
		KeyEvent(keyInput)
	{}

	EVENT_CLASS_TYPE(KeyUp);
};