#pragma once

#include "Object.h"
#include "RenderElement.h"
#include <Echo/core/ShaderList.h>

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
	void AddElement(const std::string& name, RenderElement* element);
	void RemoveElement(const std::string& name);
	
	Object* GetObject();
	RenderElement* GetElement(const std::string& name);

	virtual void Render(ShaderList* shaders) = 0;

	~ObjectComponent();
};