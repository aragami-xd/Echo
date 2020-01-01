#include "ObjectComponent.h"
using namespace std;

ObjectComponent::ObjectComponent() :
	object(nullptr)
{
}

void ObjectComponent::AddObject(Object* o)
{
	if (object == nullptr)
		object = o;
	else
		LOG_warning("object occupied");
}

void ObjectComponent::AddElement(string& name, RenderElement* e)
{
	element.insert({ name, e });
}

void ObjectComponent::RemoveElement(string& name)
{
	element.erase(name);
}

Object* ObjectComponent::GetObject()
{
	return object;
}

RenderElement* ObjectComponent::GetElement(std::string& name)
{
	return element[name];
}

ObjectComponent::~ObjectComponent()
{
	delete object;
	for (auto ie : element)
		delete ie.second;
}
