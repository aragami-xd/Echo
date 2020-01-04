#pragma once

#include <EchoHeader.h>
#include "Layer.h"

class LayerStack
{
private:
	std::vector<Layer*> layerStack;
public:
	// push and pop
	inline void push_back(Layer* layer) { layerStack.push_back(layer); }
	inline void pop_back() { layerStack.pop_back(); }

	// iterators
	inline std::vector<Layer*>::iterator begin() { return layerStack.begin(); }
	inline std::vector<Layer*>::iterator end() { return layerStack.end(); }
	inline std::vector<Layer*>::reverse_iterator rbegin() { return layerStack.rbegin(); }
	inline std::vector<Layer*>::reverse_iterator rend() { return layerStack.rend(); }

	// push a layer to the top. note this will push to the back of the layerStack
	void push_to_top(const std::string& name);

	// swap layers
	void swap(const std::string& layer1, const std::string& layer2);
};