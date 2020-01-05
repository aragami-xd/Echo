#pragma once

#include "Object.h"
#include "RenderElement.h"
#include <Echo/core/ShaderList.h>

class ECHO_DLL ObjectComponent
{
	using Elements = std::unordered_map<std::string, RenderElement*>;
protected:
	Object* object = nullptr;
	Elements element;

public:
	// if object is occupied, warn the user and not add the object
	inline void AddObject(Object* object)
	{
		if (this->object == nullptr)
			this->object = object;
		else
			LOG_warning("object occupied");
	}

	// add
	inline void AddElement(const std::string& name, RenderElement* element)
	{
		this->element.insert({ name, element });
	}

	// remove (warning: element will not be deleted)
	inline void RemoveElement(const std::string& name)
	{
		element.erase(name);
	}

	// get
	inline Object* GetObject()
	{
		return object;
	}

	inline RenderElement* GetElement(const std::string& name)
	{
		return element[name];
	}

	// iterators
	inline Elements::iterator ElementBegin() { return element.begin(); }
	inline Elements::iterator ElementEnd() { return element.end(); }

	// render
	virtual void Render(ShaderList* shaders, int time) = 0;
};