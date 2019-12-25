#pragma once

#include "Event.h"
using namespace std;

class KeyEvent : public Event
{
protected:
	KeyEvent(char k) :
		key(k)
	{}

	char key;
public:
};

class KeyDownEvent : public KeyEvent
{
private:
	int count;
public:
	KeyDownEvent(char k, int c) :
		KeyEvent(k), count(c)
	{}

	EVENT_CLASS_TYPE(KeyDown);

	inline int GetCount() { return count; }
};

class KeyUpEvent : public KeyEvent
{
public:
	KeyUpEvent(char k) :
		KeyEvent(k)
	{}

	EVENT_CLASS_TYPE(KeyUp);
};
