#pragma once

#include "Object.h"
#include "Color.h"
#include "ShaderList.h"
#include "ObjectComponent.h"

#include <vector>
#include <ctime>


class Core
{
private:
	// time attributes
	int start;		// game start
	int time;		// current time
	int prevFrame;	// previous frame

	//shader
	ShaderList shader;

	// all the circle and slider parsed from the map
	std::vector<ObjectComponent> object;
	int index{ 0 };

	// metadata - song setup
	float approachRate{ 9.5f };
	float circleSize{ 5.0f };
	float overallDifficulty{ 9.0f };
	float hpDrain{ 6.0f };

	// color list
	std::vector<Color> colorList{ COLOR_LIGHT_BLUE, COLOR_LIGHT_YELLOW };

	// initialize the map
	void MapInit(std::string path);

	// function handles which circle or slider to be drawn
	void DrawAllObject();

public:
	Core(std::string path);				

	// draw everything on the screen
	void Draw();

	~Core();
};