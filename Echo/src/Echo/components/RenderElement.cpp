#include "RenderElement.h"

RenderElement::RenderElement(glm::vec4 objectColor) :
	vl(nullptr), va(nullptr), vb(nullptr), ib(nullptr), color(objectColor)
{
}

RenderElement::~RenderElement()
{
	if (vl != nullptr) delete vl;
	if (va != nullptr) delete va;
	if (vb != nullptr) delete vb;
	if (ib != nullptr) delete ib;
}