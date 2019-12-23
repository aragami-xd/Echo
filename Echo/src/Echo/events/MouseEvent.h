#pragma once

#include "Event.h"

// mouse button event
class MouseButtonEvent : public Event
{
protected:
	int button;
public:
	MouseButtonEvent(int left) :
		button(left)
	{}

	inline virtual EventCategory GetEventCategory() const final override {
		return EventCategory::EventCategoryMouseButton;
	}

	inline int GetButton() { return button; }
};

// mouse button down
class MouseDownEvent : public MouseButtonEvent
{
public:
	MouseDownEvent(int left) :
		MouseButtonEvent(left)
	{}
	
	inline virtual EventType GetEventType() const final override {
		return EventType::MouseDown;
	}
};

// mouse button up
class MouseUpEvent : public MouseButtonEvent
{
public:
	MouseUpEvent(int left) :
		MouseButtonEvent(left)
	{}

	inline virtual EventType GetEventType() const final override {
		return EventType::MouseUp;
	}
};

// mouse move
class MouseMoveEvent : public Event
{
private:
	float x, y;
public:
	MouseMoveEvent(float xm, float ym) : 
		x(xm), y(ym)
	{}

	inline virtual EventType GetEventType() const final override {
		return EventType::MouseMove;
	}

	inline virtual EventCategory GetEventCategory() const final override {
		return EventCategory::EventCategoryMouse;
	}

	inline float GetX() { return x; }
	inline float GetY() { return y; }
};

// mouse wheel
class MouseWheelEvent : public Event
{
private:
	float xoffset, yoffset;
public:
	MouseWheelEvent(float xo, float yo) :
		xoffset(xo), yoffset(yo)
	{}

	inline virtual EventType GetEventType() const final override {
		return EventType::MouseWheel;
	}

	inline virtual EventCategory GetEventCategory() const final override {
		return EventCategory::EventCategoryMouse;
	}

	inline float GetXOffset() { return xoffset; }
	inline float GetYOffset() { return yoffset; }
};
