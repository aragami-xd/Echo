#pragma once
#include <string>

/* this file contain public attributes related to how the game is set up */

/* window size and ratio */
namespace window
{
	const int WindowWidth = 1280;	// height
	const int WindowHeight = 720;	// width
	const float WidthDivHeight = WindowWidth / (float)WindowHeight;	// width divide height
	const float HeightDivWidth = WindowHeight / (float)WindowWidth;	// height divide width
};

/* paths */
namespace path
{
	// basic shader
	const std::string BasicVertexPath = "Osu!Trainer/src/Shaders/Shader.vert";
	const std::string BasicFragmentPath = "Osu!Trainer/src/Shaders/Shader.frag";

	// circle shader
	const std::string CircleVertexPath = "Osu!Trainer/src/Shaders/CircleShader.vert";
	const std::string CircleFragmentPath = "Osu!Trainer/src/Shaders/CircleShader.frag";

	// beatmap
	const std::string BeatmapPath = "Osu!Trainer/lib/Beatmaps/map.txt";
};

/* object */
namespace object
{
	// number of dots to draw the circle
	const int DotCount = 120;

	// object attributes
	const float ObjectSpeedScaling = 5000;	// for scaleAR, in ms
	const float ObjectSizeScaling = 0.4f;		// for scaleCS

	// shader attributes
	const float circleBorderThickness = 0.07f;
	const float circleAccentThickness = 0.2f;
	const float ringBorderThickness = 0.05f;
};

/* key mapping */
namespace keymapping
{
	// key mapping
	const char key1 = 'q';
	const char key2 = 'e';
}