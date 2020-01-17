#pragma once

#include <Echo.h>

class BezierSliderRenderElement : public RenderElement
{
private:
	// control points and equation coefficient
	std::vector<float> xControlPoints;
	std::vector<float> yControlPoints;
	std::vector<int> coefficient;

	// the outer vertices of the slider
	std::vector<float> vertices;

	// find all the coeffcient for the bezier curve equation
	std::vector<int> RecursiveCoefficient(int coef, std::queue<int>& coefQueue);

	// calculate the center value based on the control points, coef and incremental step
	float CalcCenter(std::vector<int>& coef, std::vector<float>& cp, float inc);

	/*
	* calculate the coordinate of the vertices based on the center spine
	* the function takes 2 points next to each other to form a perpendicular line goes through them
	* and return the point left or right to that line based on the direction
	*/
	std::pair<float, float> CalcVertices(float x1, float y1, float x2, float y2, float size, bool direction);
public:
	BezierSliderRenderElement(std::vector<float>& xcp, std::vector<float>& ycp, float circleRadius);

	inline float* GetVertices() { return vertices.data(); }

	virtual float GetX(float time);
	virtual float GetY(float time);

	~BezierSliderRenderElement();
};