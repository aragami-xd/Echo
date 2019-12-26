#pragma once

#include <Engine/Object.h>
#include <Buffers/VertexArray.h>
#include <Buffers/IndexBuffer.h>
#include <Buffers/Shader.h>

#include <vector>

class Circle : public Object
{
private:
	// when the beat of the circle is mapped to (i.e. animation ends)
	int beatTime{ 0 };

public:
	// circle constructor
	Circle(float x, float y, std::vector<int>& beat, float AR, float CS, float OD);

	// get beat time, animation time and end time
	inline virtual int GetBeatTime() final { return beatTime; }

	// getScore will return the score when the circle is tapped at a certain moment
	int GetScore(int timestamp);
};