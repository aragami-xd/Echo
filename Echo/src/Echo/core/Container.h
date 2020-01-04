#pragma once

#include <EchoHeader.h>

/* pretty much just a glorified vector of pairs of name and item */

template<typename T>
class Container
{
protected:
	std::vector<std::pair<std::string, T>> container;
public:
	Container() = default;

	// push / emplace / pop back
	inline void push_back(std::pair<std::string, T>& item)				// container::push_back()
	{
		container.push_back(item);
	}
	inline void emplace_back(const std::string& name, T& item)				// container::emplace_back()
	{
		container.push_back({ name, item });
	}
	inline void pop_back()												// container::pop_back()
	{
		container.pop_back();
	}

	// front / back
	inline T front()							// container::front()
	{
		return container.front().second;
	}
	inline T back()								// container::back();
	{
		return container.back().second;
	}

	// iterators
	inline typename std::vector<std::pair<std::string, T>>::iterator begin()	// container::begin()
	{
		return container.begin();
	}
	inline typename std::vector<std::pair<std::string, T>>::iterator end()		// container::end()
	{
		return container.end();
	}
	inline typename std::vector<std::pair<std::string, T>>::iterator rbegin()	// container::rbegin()
	{
		return container.end();
	}
	inline typename std::vector<std::pair<std::string, T>>::iterator rend()		// container::rend();
	{
		return container.begin();
	}
	static typename std::vector<std::pair<std::string, T>>::iterator iterator;

	// size / empty
	inline unsigned int size()					// container.size()
	{
		return container.size();
	}
	inline bool empty()							// container::end()
	{
		return container.empty();
	}

	// push / emplace / pop front
	inline void push_front(std::pair<std::string, T>& item)		// container::push_front()
	{
		container.insert(container.begin(), item);
	}
	inline void emplace_front(const std::string& name, T& item)			// container::emplace_front()
	{
		container.insert(container.begin(), { name, item });
	}
	inline void pop_front()											// container::pop_front()
	{
		container.erase(container.begin());
	}

	// erase
	void erase(const std::string& name);

	// find
	T find(const std::string& name);

	virtual ~Container() {};
};