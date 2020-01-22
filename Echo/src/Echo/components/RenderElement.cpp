#include "RenderElement.h"

Echo::RenderElement::RenderElement() :
	vl(nullptr), va(nullptr), vb(nullptr), ib(nullptr)
{
}

Echo::RenderElement::~RenderElement()
{
	if (vl != nullptr) delete vl;
	if (va != nullptr) delete va;
	if (vb != nullptr) delete vb;
	if (ib != nullptr) delete ib;
}