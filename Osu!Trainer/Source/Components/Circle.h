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
	int startTime;
	// when the beat of the circle is mapped to (i.e. animation ends)
	int beatTime{ 0 };
	// when the circle disappears
	int endTime;

	// dots to draw the circle
	std::vector<float> circleDot;
	std::vector<float> ringDot;

public:
	// circle constructor
	Circle(float x, float y, int beat);

	// get beat time, animation time and end time
	inline int GetBeatTime() {
		return beatTime;
	}
	inline int GetStartTime() {
		return startTime;
	}
	inline int GetEndTime() {
		return endTime;
	}

	// get the vertex buffers
	inline float* GetCircleDot()
	{
		return circleDot.data();
	}
	// ring buffer will bind new data and return the buffer depend on the timestamp
	float* GetRingDot(int timestamp);

	// getScore will return the score when the circle is tapped at a certain moment
	int GetScore(int timestamp);

	void Draw(int time);
};