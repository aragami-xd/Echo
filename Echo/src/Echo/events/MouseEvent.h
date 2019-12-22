#pragma once

#include "Event.h"

// mouse event
class MouseEvent : public Event
{
protected:
	float x, y;

	MouseEvent(float xm, float ym) : 
		x(xm), y(ym) 
	{}
public:
	inline float GetMX() { return x; }
	inline float GetMY() { return y; }
};

// mouse button event
class MouseButtonEvent : public MouseEvent
{
protected:
	bool leftButton;
public:
	MouseButtonEvent(float xm, float ym, bool left) :
		MouseEvent(xm, ym), leftButton(left)
	{}
	
	EVENT_CLASS_CATEGORY(EventCategoryMouse);

	inline bool isLeftButton() { return leftButton; }
};

// mouse button down
class MouseDownEvent : public MouseButtonEvent
{
private:
	int count;
public:
	MouseDownEvent(float xm, float ym, bool left, int countbtn) :
		MouseButtonEvent(xm, ym, left), count(countbtn)
	{}

	EVENT_CLASS_TYPE(MouseDown);

	inline bool GetButtonCount() { return count; }
};

// mouse button up
class MouseUpEvent : public MouseButtonEvent
{
public:
	MouseUpEvent(float xm, float ym, bool leftbtn) :
		MouseButtonEvent(xm, ym, leftbtn)
	{}

	EVENT_CLASS_TYPE(MouseUp);
};

// mouse move
class MouseMoveEvent : public MouseEvent
{
public:
	MouseMoveEvent(float xm, float ym) :
		MouseEvent(xm, ym)
	{}

	EVENT_CLASS_TYPE(MouseMove);
	EVENT_CLASS_CATEGORY(EventCategoryMouse);
};

// mouse wheel
class MouseWheelEvent : public MouseEvent
{
private:
	bool wheelUp;
	int wheelStep;
protected:
	MouseWheelEvent(float xm, float ym, bool up, int step) :
		MouseEvent(xm, ym), wheelUp(up), wheelStep(step)
	{}

	EVENT_CLASS_TYPE(MouseWheel);
	EVENT_CLASS_CATEGORY(EventCategoryMouse);

	inline bool isWheelUp() { return wheelUp; }
	inline int GetWheelStep() { return wheelStep; }
};
