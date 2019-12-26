#include "Container.h"
using namespace std;

template<class T>
inline void Container<T>::push_front(std::pair<std::string&, T&> item)
{
	if (item.first == nullptr)
		item.first == typeid(T)+to_string(++id);
	container.insert(container.begin(), item);
}

template<class T>
inline void Container<T>::emplace_front(std::string& name, T& item)
{
	if (name == nullptr)
		name == typeid(T)+to_string(++id);
	container.insert(container.begin(), { name, item });
}

template<class T>
inline void Container<T>::pop_front()
{
	container.erase(container.begin());
}

template<class T>
inline void Container<T>::erase(std::string& name)
{
	for (int i = 0; i < container.size(); i++)
		if (container[i].first == name)
		{
			erase(container.begin() + i);
			return;
		}
	LOG_pair(LOG_warning(name), LOG_message("not found"));
}

template<class T>
inline T Container<T>::find(const std::string& name)
{
	for (int i = 0; i < container.size(); i++)
		if (container[i].first == name)
			return T();
	LOG_pair(LOG_warning(name), LOG_message("not found"));
	return nullptr;
}