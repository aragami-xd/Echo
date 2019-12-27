#include "Container.h"
using namespace std;

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