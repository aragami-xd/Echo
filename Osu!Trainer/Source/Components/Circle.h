#pragma once

#include "Object.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/Shader.h"
#include "CircleRenderer.h"

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

	// the circle renderer
	CircleRenderer* renderer;

public:
	// circle constructor
	Circle(float x, float y, int beat, float AR, float CS, float OD);

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

	// getScore will return the score when the circle is tapped at a certain moment
	int GetScore(int timestamp);

	void Draw(int time);

	~Circle();
};