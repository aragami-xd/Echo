#pragma once

#include <Echo/core/Core.h>
#include <Echo/events/Event.h>

class ECHO_DLL Layer
{
private:
	std::string name;
	bool enabled;
public:
	Layer(std::string& layerName) :
		name(layerName), enabled(true)
	{}
	inline std::string GetLayerName() { return name; }

	inline virtual void Attach() { enabled = true; }
	inline virtual void Detach() { enabled = false; }

	virtual void Update() {};
	virtual void OnEvent(const Event& e) {};

	virtual ~Layer() = default;
};