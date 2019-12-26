#pragma once

#include <EchoHeader.h>

/* pretty much just a glorified vector of pairs of name and item */

template<class T>
class Container
{
protected:
	std::vector<std::pair<std::string, T>> container;
	std::vector<std::pair<std::string, T>> it;
	int id;
public:
	Container() = default;

	/* for push and emplace, pass a nullptr as string::name to use the default name */

	// push / pop back
	inline void push_back(std::pair<std::string&, T&> item) 
	{
		if (item.first == nullptr)
			item.first == typeid(T)+to_string(++id);
		container.push_back(item);
	}
	inline void emplace_back(std::string& name, T& item)
	{
		if (name == nullptr)
			name == typeid(T)+to_string(++id);
		container.push_back({ name, item }); 
	}
	inline void pop_back() 
	{ 
		container.pop_back(); 
	}
	
	// front / back
	inline T front() 
	{ 
		return container.front().second; 
	}
	inline T back() 
	{ 
		return container.back().second;
	}

	// begin / end
	inline std::vector<std::pair<std::string, T>> begin()
	{
		return container.begin(); 
	}
	inline std::vector<std::pair<std::string, T>> end()
	{ 
		return container.end(); 
	}

	// size / empty
	inline unsigned int size()
	{
		return container.size();
	}
	inline bool empty() 
	{ 
		return container.empty(); 
	}

	// push / pop front
	void push_front(std::pair<std::string&, T&> item);
	void emplace_front(std::string& name, T& item);
	void pop_front();

	// erase
	void erase(std::string& name);

	// find
	T find(const std::string& name);

	virtual ~Container() {};
};