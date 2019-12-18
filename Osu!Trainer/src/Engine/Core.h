#pragma once

#include "Object.h"
#include "Color.h"
#include <Components/ShaderList.h>

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
	std::vector<Object*> allObject;
	// current index of the circle and slider
	int objectIndex{ 0 };

	// metadata - song setup
	float approachRate{ 9.5f };
	float circleSize{ 5.0f };
	float overallDifficulty{ 9.0f };
	float hpDrain{ 6.0f };

	// color list
	std::vector<Color> colorList{ COLOR_WHITE, COLOR_LIGHT_BLUE, COLOR_LIGHT_YELLOW };

	// initialize the map
	void MapInit(std::string path);

	// function handles which circle or slider to be drawn
	void DrawAllObject();

public:
	Core(std::string path, ShaderList shader);

	// draw everything on the screen
	void Draw();

	~Core();
};