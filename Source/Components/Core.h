#pragma once

#include <list>
#include <string>
#include <fstream>

#include "Circle.h"
#include "Beatmap.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/VertexBuffer.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/Shader.h"


class Core
{
private:
	// time will keep track of how long into the map it is
	static int time;

	// the beatmap text file
	std::ifstream map;

	// openGL elements
	VertexArray* va;
	VertexBufferLayout* vbl;
	unsigned int indices[::DotCount * 3];
	IndexBuffer* ib;

	// the circles appear on the screen at a certain moment
	std::list<Circle*> circle;

	// 4 attributes of the game: AR, CS, OD, HP
	float approachRate{ 9.5f };
	float circleSize{ 5.0f };
	float overallDifficulty{ 9.5f };
	float hpDrain{ 6.0f };

	/* player hp, score, accurary and combo (score is basically useless in the real game tbh) */
	// hp is how much health left the player has. HP Drain (HP) will determine how fast health reduces
	// and how much player earn (or lose) when tapping a circle. hp always reduces gradually
	int hp{ 100 };
	// score of a circle = Circle::GetScore() * combo
	int score{ 0 };
	// accuracy = average accuracy of every circle till that point. 300 = 100%, 100 = 75%, 50 = 50%, miss = 0%
	float accuracy{ 100.0f };
	// combo is how many circles have been tapped in a row without miss
	int combo{ 0 };

	// animationTime will keep track of when the next animation will start playing so it can read the next line
	int animationTime{ 0 };

	/* functions */
	// parse the map based on its text file
	void MapParser();

	// create a circle with the specified specs
	void CreateCircle(float x, float y, int beatTime);

	// delete a circle after it's pressed or out of time
	void DeleteCircle();

	// animate a single circle
	void AnimatePerCircle(Circle* animateCircle);

	// animate every circle
	void AnimateAllCircle();

public:
	// core will setup some vertex array and buffer
	Core();

	// initialize the map
	void MapInit(std::string path);

	// draw the entire screen
	void Draw();

	// delete the buffers when the core is deleted
	~Core();
};