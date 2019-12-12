#pragma once

#include "Object.h"
#include "../Buffers/VertexBuffer.h"

class Circle : public Object
{
private:
	// when the circle appears on the screen
	int animationTime;
	// when the beat of the circle is mapped to (i.e. animation ends)
	int beatTime{ 0 };
	// when the circle disappears
	int endTime;

	// color of the circle
	Color circleColor{ COLOR_LIGHT_BLUE };

	// points on the surface of the circle, used to draw the circle later on
	float circleDot[::DotCount * 2 + 2];
	float ringDot[::DotCount * 2 + 2];

	// vertex buffers created from the data above
	VertexBuffer* vbCircle, * vbRing;

public:
	// circle constructor
	Circle(float x, float y, float AR, float CS, float OD, int beat, Color color);

	// get beat time, animation time and end time
	inline int GetBeatTime() {
		return beatTime;
	}
	inline int GetAnimationTime() {
		return animationTime;
	}
	inline int GetEndTime() {
		return endTime;
	}

	// get the vertex buffers
	inline VertexBuffer* GetCircleBuffer()
	{
		return vbCircle;
	}
	// ring buffer will bind new data and return the buffer depend on the timestamp
	VertexBuffer* GetRingBuffer(int timestamp);

	// getScore will return the score when the circle is tapped at a certain moment
	int GetScore(int timestamp);

	// delete the buffers
	~Circle();
};