#pragma once

#include <Echo/core/Core.h>
#include <Echo/events/Event.h>

class ECHO_DLL Layer
{
public:
	virtual void Attach() = 0;
	virtual void Detach() = 0;
	virtual void Update() = 0;
	virtual void OnEvent(const Event& e) = 0;

	virtual ~Layer() = default;
};