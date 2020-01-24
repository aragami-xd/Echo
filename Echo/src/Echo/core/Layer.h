#pragma once

#include <EchoCore.h>
#include <Echo/events/Event.h>

namespace Echo
{
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

		~Layer() = default;
	};
}