#pragma once

#include <Echo.h>

/* note that the circle render element has nothing to do with circle object
	* this element is only use to depict anything rounded on the screen
	* components like slider can include circle render element
	* yes, i'm suck at naming, that's why we have 2 different "circles"
*/

namespace OsuTrainer
{
	class CircleRenderElement : public Echo::RenderElement
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
}