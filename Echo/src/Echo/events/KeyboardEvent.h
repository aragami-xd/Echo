#pragma once

#include "Event.h"

namespace Echo
{
	/* key event */
	class KeyEvent : public Event
	{
	protected:
		KeyEvent(char k) :
			key(k)
		{}
		char key;
	public:
		inline char GetKey() { return key; }
	};

	/* key down event */
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

	/* key up event */
	class KeyUpEvent : public KeyEvent
	{
	public:
		KeyUpEvent(char k) :
			KeyEvent(k)
		{}

		EVENT_CLASS_TYPE(KeyUp);
	};
}