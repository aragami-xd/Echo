#pragma once

#include <Core.h>
#include <Echo/events/Event.h>

class ECHO_DLL Layer
{
private:
	std::string name;
	bool enabled;
public:
	Layer(const std::string& layerName) :
		name(layerName), enabled(true)
	{}
	inline std::string GetLayerName() { return name; }

	inline void Attach() { enabled = true; }
	inline void Detach() { enabled = false; }

	virtual void Update() {}
	virtual void OnEvent(Event& e) {}

	virtual ~Layer() = default;
};