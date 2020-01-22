#pragma once

#include "Event.h"

namespace Echo
{
	class WindowCloseEvent : public Echo::Event
	{
	public:
		WindowCloseEvent() = default;
		EVENT_CLASS_TYPE(WindowClose);
	};
}