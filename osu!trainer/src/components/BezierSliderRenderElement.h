#pragma once

#include <Echo.h>

class BezierSliderRenderElement : public RenderElement
{
private:
	std::vector<float> center;		// the spine of the slider
	std::vector<float> vertices;		// the outer vertices of the slider

	// find all the coeffcient for the bezier curve equation
	std::vector<int> RecursiveCoefficient(int coef, std::queue<int>& coefQueue);

	// calculate the vertices value based on the control points, coef and incremental step
	float CalcVertices(std::vector<int>& coef, std::vector<float>& cp, float inc);
public:
	BezierSliderRenderElement(std::vector<float>& xcp, std::vector<float>& ycp);

	inline float* GetVertices() { return vertices.data(); }

	~BezierSliderRenderElement();
};