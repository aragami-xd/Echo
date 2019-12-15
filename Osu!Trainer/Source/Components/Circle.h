#pragma once

#include "Object.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/Shader.h"

#include <vector>

class Circle : public Object
{
private:
	// when the circle appears on the screen
	int animationTime;
	// when the beat of the circle is mapped to (i.e. animation ends)
	int beatTime{ 0 };
	// when the circle disappears
	int endTime;

	// dots on the surface of the inner circle at (x,y) = (0.0f, 0.0f)
	// they're the same with every circle, a translation matrix will handle where they're placed
	std::vector<float> circleDot;
	// dots on the surface of the outer ing, they're tied with the circle
	std::vector<float> ringDot;

public:
	// circle constructor
	Circle(float x, float y, int beat);

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
	inline std::vector<float> GetCircleDot()
	{
		return circleDot;
	}
	// ring buffer will bind new data and return the buffer depend on the timestamp
	std::vector<float> GetRingDot(int timestamp);

	// getScore will return the score when the circle is tapped at a certain moment
	int GetScore(int timestamp);
};