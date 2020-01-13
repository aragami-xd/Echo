#pragma once

#include <Echo.h>

class BezierSliderRenderElement : public RenderElement
{
private:
	std::vector<float> vertices;
public:
	BezierSliderRenderElement(float xs, float ys, float xe, float ye, std::vector<float> xcp, std::vector<float> ycp);

	inline float* GetVertices() { return vertices.data(); }
};