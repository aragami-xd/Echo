#pragma once

#include <vector>
#include <Buffers/VertexArray.h>
#include <Buffers/VertexBufferLayout.h>

class CircleRenderer
{
private:
	// x, y and radius
	float x;
	float y;
	static float radius;

	/* deprecated draw functions: drawing the circle using vertices from the vertex array and vertex buffers */
	// dots to draw the circle
	std::vector<float> circleDotBuf;
	std::vector<float> ringDotBuf;

	// buffers
	static VertexBufferLayout vblBuf;
	VertexArray vaCircleBuf;
	VertexArray vaRingBuf;
	VertexBuffer* vbCircleBuf;
	VertexBuffer* vbRingBuf;

	// calculate the size of the ring
	float* GetRingDotBuf(int time, int beatTime, int animationLength);

	/* new fragment shader function: drawing the circle using the fragment shader */
	// boundaries of the circle and ring
	std::vector<float> circleVerticesFrag;
	std::vector<float> ringVerticesFrag;

	// buffers
	static VertexBufferLayout vblFrag;
	VertexArray vaCircleFrag;
	VertexArray vaRingFrag;
	VertexBuffer* vbCircleFrag;
	VertexBuffer* vbRingFrag;

	// calculate the boundaries of the ring
	float* GetRingVerticesFrag(int time, int beatTime, int animationLength);

public:
	CircleRenderer(float x, float y, float radius);

	// draw the circle and the ring using buffers vertices (deprecated)
	void DrawCircleBuf();
	void DrawRingBuf(int time, int beatTime, int animationLength);

	// draw the circle and the ring using fragment shaders (the new way)
	void DrawCircleFrag();
	void DrawRingFrag(int time, int beatTime, int animationLength);

	~CircleRenderer();
};
