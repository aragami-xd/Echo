#pragma once

#include <Echo/core/Core.h>
#include <Echo/events/Event.h>

class ECHO_DLL Layer
{
private:
	static int id;
	std::string name;
public:
	Layer(std::string& layerName = "layer" + to_string(id)) :
		name(layerName)
	{}

	virtual void Attach() {};
	virtual void Detach() {};
	virtual void Update() {};
	virtual void OnEvent(const Event& e) {};

	inline std::string GetLayerName() { return name; }

	virtual ~Layer() = default;
};