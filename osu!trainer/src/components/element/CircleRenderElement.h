#pragma once

#include <Echo.h>

class CircleRenderElement : public RenderElement
{
private:
	float x;
	float y;
	std::vector<float> vertices;
public:
	CircleRenderElement(float x, float y, float circleRadius);

	inline float* GetVertices() { return vertices.data(); }

	inline virtual float GetX(float time) { return x; }
	inline virtual float GetY(float time) { return y; }

	~CircleRenderElement();
};