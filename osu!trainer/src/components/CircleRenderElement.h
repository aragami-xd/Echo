#pragma once

#include <Echo.h>

class CircleRenderElement : public RenderElement
{
private:
	std::vector<float> vertices;
public:
	CircleRenderElement(float circleRadius);

	inline float* GetVertices() { return vertices.data(); }
};