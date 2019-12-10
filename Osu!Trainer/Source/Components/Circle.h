#pragma once

#include "Color.h"
#include "../Engine/Attribute.h"
#include "../Buffers/VertexBuffer.h"

class Circle
{
private:
	// location of the circle
	float x{ 0.0f };
	float y{ 0.0f };

	/* approach rate (AR) and circle size (CS) (used for scaling) and overal difficulty (OD) */
	// AR determines how fast (how long) the circle will show on the screen
	// scaling with the static AR variable
	// generally, AR9 - AR9.5 is the sweet spot
	float approachRate{ 9.0f };
	// CS determines how large the circle will be
	// scaling with the static CS variable
	// generally, CS4 - CS5 is the sweet spot
	float circleSize{ 5.0f };
	// OD determines how tight you have to press to hit the circle
	// you can only tap in the 50 score range (best if 300), higher OD means this range is tighter
	// generally, OD9 - OD 9.5 is the sweet spot
	float overallDifficulty{ 9.0f };

	// reference approach rate duration for scaling
	static const int scaleAR;
	// reference circle size for scaling
	static const float scaleCS;

	// animationLength is the duration from when the circle appears on the screen
	// till the ring touches the circle and dissapear (circle not yet dissapear)
	int animationLength;
	// 300 score (best score)
	int threeHundred;
	// 100 score (a bit worse)
	int oneHundred;
	// 50 score (worst)
	// outside of this range will be a miss (i.e. way too soon or early)
	int fifty;

	// render radius of the circle
	float circleRadius;

	// when the circle appears on the screen
	int animationTime;
	// when the beat of the circle is mapped to (i.e. animation ends)
	int beatTime{ 0 };
	// when the circle disappears
	int endTime;

	// color of the circle
	Color circleColor{ 1.0f, 1.0f, 1.0f, 1.0f };

	// points on the surface of the circle, used to draw the circle later on
	float circleDot[::DotCount * 2 + 2];
	float ringDot[::DotCount * 2 + 2];

	// vertex buffers created from the data above
	VertexBuffer* vbCircle, * vbRing;

public:
	// circle constructor
	Circle(float x, float y, Color color, float AR, float CS, float OD, int beat);

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