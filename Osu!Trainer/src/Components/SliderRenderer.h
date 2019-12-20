#pragma once

#include <vector>
#include <Buffers/VertexArray.h>
#include <Buffers/VertexBufferLayout.h>
#include <Engine/ObjectRenderer.h>

#include "Slider.h"

class SliderRenderer : public ObjectRenderer
{
private:

public:
	SliderRenderer(Object* slider);

	virtual void DrawBuf(int time, Shader* shader) final;
	virtual void DrawFrag(int time, Shader* shader) final;

	~SliderRenderer();
};