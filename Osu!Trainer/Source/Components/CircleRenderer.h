#pragma once

#include <vector>
#include "../Buffers/VertexArray.h"
#include "../Buffers/VertexBufferLayout.h"

class CircleRenderer
{
private:
	// dots to draw the circle
	std::vector<float> circleDot;
	std::vector<float> ringDot;

	// x, y and radius
	float x;
	float y;
	static float objectRadius;

	// buffers
	VertexBufferLayout vbl;
	VertexArray vaCircle;
	VertexArray vaRing;
	VertexBuffer* vbCircle; 
	VertexBuffer* vbRing; 

	// calculate the size of the ring
	float* GetRingDot(int time, int beatTime, int animationLength);

public:
	CircleRenderer(float cx, float cy, float cRad);

	// draw the circle and the ring (deprecated)
	void DrawCircleDep();
	void DrawRingDep(int time, int beatTime, int animationLength);

	// draw the circle and the ring (the new way)
	//void DrawCirlce();
	//void DrawRing(int time, int beatTime, int animationLength);

	~CircleRenderer();
};
