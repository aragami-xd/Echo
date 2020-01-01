#pragma once

#include "Object.h"
#include "RenderElement.h"

class ECHO_DLL ObjectComponent
{
	using Elements = std::unordered_map<std::string, RenderElement*>;
protected:
	Object* object;
	Elements element;
public:
	ObjectComponent();

	// if object is occupied, warn the user
	void AddObject(Object* object);
	void AddElement(std::string& name, RenderElement* element);
	void RemoveElement(std::string& name);
	
	Object* GetObject();
	RenderElement* GetElement(std::string& name);

	~ObjectComponent();
};