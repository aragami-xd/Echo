#pragma once

#include <EchoHeader.h>
#include "Layer.h"

namespace Echo
{
	class LayerStack
	{
	private:
		using stack = std::vector<Layer*>;
		stack layerStack;
	public:
		// push and pop
		inline void push_back(Layer* layer) { layerStack.push_back(layer); }
		inline void pop_back() { layerStack.pop_back(); }

		// iterators
		inline stack::iterator begin() { return layerStack.begin(); }
		inline stack::iterator end() { return layerStack.end(); }
		inline stack::reverse_iterator rbegin() { return layerStack.rbegin(); }
		inline stack::reverse_iterator rend() { return layerStack.rend(); }

		// push a layer to the top. note this will push to the back of the layerStack
		void push_to_top(const std::string& name);

		// swap layers
		void swap(const std::string& layer1, const std::string& layer2);
	};
}