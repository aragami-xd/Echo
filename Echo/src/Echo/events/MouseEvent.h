#pragma once

#include "Event.h"

class MouseButtonEvent : public Event
{
protected:
	MouseButtonEvent(int btn) :
		button(btn)
	{}

	int button;
public:
};

class MouseDownEvent : public MouseButtonEvent
{
public:
	MouseDownEvent(int btn) :
		MouseButtonEvent(btn)
	{}

	EVENT_CLASS_TYPE(MouseDown);
};

class MouseUpEvent : public MouseButtonEvent
{
public:
	MouseUpEvent(int btn) :
		MouseButtonEvent(btn)
	{}

	EVENT_CLASS_TYPE(MouseUp);
};

class MouseMoveEvent : public Event
{
private:
	float x;
	float y;
public:
	MouseMoveEvent(float mx, float my) :
		x(mx), y(my)
	{}

	EVENT_CLASS_TYPE(MouseMove);

	inline float GetX() { return x; }
	inline float GetY() { return y; }
};

class MouseWheelEvent : public Event
{
private:
	float xoffset;
	float yoffset;
public:
	MouseWheelEvent(float mx, float my) :
		xoffset(mx), yoffset(my)
	{}

	EVENT_CLASS_TYPE(MouseWheel);

	inline float GetXOffset() { return xoffset; }
	inline float GetYOffset() { return yoffset; }
};