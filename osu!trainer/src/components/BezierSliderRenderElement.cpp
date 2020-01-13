#include "BezierSliderRenderElement.h"
using namespace std;

BezierSliderRenderElement::BezierSliderRenderElement(vector<float>& xcp, vector<float>& ycp)
{
	/*	bezier curve point equation for 4 control points:
		(1-t)^3 * P1 + 3 * (1-t)^2 * t * P2 + 3 * (1-t) * t^2 * P3 + t^3 * P4
		same deal with more control points
	*/

	// calculate the coefficient
	queue<int> coefQueue;
	coefQueue.push(1);
	coefQueue.push(1);
	vector<int> coef = RecursiveCoefficient(xcp.size(), coefQueue);

	// calculate vertices
	for (float i = 0.0f; i <= 1.0f; i += 0.001f)
	{
		center.push_back(CalcVertices(coef, xcp, i));
		center.push_back(CalcVertices(coef, ycp, i));
	}

	vertices = center;

	vl = new VertexLayout();	
	vl->Push<float>(2);
	vb = new VertexBuffer(vertices.data(), vertices.size() * sizeof(float));
	va = new VertexArray();
	va->AddBuffer(*vl, *vb);
}

float BezierSliderRenderElement::CalcVertices(std::vector<int>& coef, std::vector<float>& cp, float inc)
{
	float val = 0;
	for (int i = 0; i < cp.size(); i++)
	{
		val += coef[i] * cp[i] * pow(1 - inc, cp.size() - i) * pow(inc, i);
	}
	return val;
}

vector<int> BezierSliderRenderElement::RecursiveCoefficient(int coef, queue<int>& coefQueue)
{
	// last coefficent to take care of, return the coef queue as a vector
	if (coef == 1)
	{
		vector<int> coefVec;
		while (!coefQueue.empty())
		{
			coefVec.push_back(coefQueue.front());
			coefQueue.pop();
		}
		return coefVec;
	}
	// else, continue calculating the next coef
	else
	{
		int size = coefQueue.size();

		// push the first (and also last) value (always 1) into the queue
		coefQueue.push(1);

		// push the remaining values
		for (int i = 0; i < size - 1; i++)
		{
			int val = coefQueue.front();
			coefQueue.pop();
			coefQueue.push(val + coefQueue.front());
		}
		coefQueue.pop();	// delete the remaining 1 from the back from the previous queue

		coefQueue.push(1);
		
		// recursive call
		return RecursiveCoefficient(coef - 1, coefQueue);
	}
}

BezierSliderRenderElement::~BezierSliderRenderElement()
{
	delete va;
	delete vb;
	delete vl;
}