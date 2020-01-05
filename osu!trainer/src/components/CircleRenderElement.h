#pragma once

#include <Echo/components/RenderElement.h>

class CircleRenderElement : public RenderElement
{
private:
	std::vector<float> vertices;
public:
	CircleRenderElement(
		float circleRadius,
		float circleThickness = 0.1f,
		glm::vec4 circleColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
	);

	inline float* GetVertices() { return vertices.data(); }
};