#include "RenderElement.h"

RenderElement::RenderElement() :
	vl(nullptr), va(nullptr), vb(nullptr), ib(nullptr)
{
}

RenderElement::~RenderElement()
{
	if (vl != nullptr) delete vl;
	if (va != nullptr) delete va;
	if (vb != nullptr) delete vb;
	if (ib != nullptr) delete ib;
}
