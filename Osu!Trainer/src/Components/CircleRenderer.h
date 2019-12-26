#pragma once

#include <vector>
#include <Buffers/VertexArray.h>
#include <Buffers/VertexBufferLayout.h>
#include <Engine/ObjectRenderer.h>

#include "Circle.h"

class CircleRenderer : public ObjectRenderer
{
private:
	// dots to draw the circle
	std::vector<float> circleDot;
	std::vector<float> ringDot;

	// buffers
	static VertexBufferLayout vbl;
	VertexArray vaCircle;
	VertexArray vaRing;
	VertexBuffer* vbCircle;
	VertexBuffer* vbRing;

	// calculate the size of the ring
	float* GetRingDot(int time);

	// draw the circle and the ring using buffers vertices (deprecated)
	void DrawCircle();
	void DrawRing(int time);

public:
	CircleRenderer(Object* circle);

	virtual void Draw(int time, Shader* shader) final;

	~CircleRenderer();
};
