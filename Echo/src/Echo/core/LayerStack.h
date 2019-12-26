#pragma once

#include "Container.h"
#include "Layer.h"

class LayerStack : public Container<Layer>
{
private:
public:
	// push a layer to the top
	void push_to_first(std::string& name);

	// push a layer to the bottom
	void push_to_bottom(std::string& name);

	// swap layers
	void swap(std::string& layer1, std::string& layer2);
};