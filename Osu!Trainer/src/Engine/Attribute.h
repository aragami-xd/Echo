#pragma once
#include <string>

/* this file contain public attributes related to how the game is set up */

/* window size and ratio */
namespace window
{
	const int windowWidth = 1280;	// height
	const int windowHeight = 720;	// width
	const float wdh = windowWidth / (float)windowHeight;	// width divide height
	const float hdw = windowHeight / (float)windowWidth;	// height divide width
};

/* lib paths */
namespace lib
{
	// beatmap
	const std::string beatmapPath = "Osu!Trainer/lib/Beatmaps/map.txt";
};

/* object */
namespace object
{
	// number of dots to draw the circle
	const int dotCount = 120;

	// object attributes
	const float objectSpeedScaling = 5000;		// for scaleAR, in ms
	const float objectSizeScaling = 0.8f;		// for scaleCS
	const float ringSizeScaling = 2.0f;			// ring size relative to circle

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

/* shader stuff */
namespace shader
{
	// basic shader
	const std::string basicVertexPath = "Osu!Trainer/src/Shaders/Shader.vert";
	const std::string basicFragmentPath = "Osu!Trainer/src/Shaders/Shader.frag";
	const std::string basicName = "basicShader";

	// circle shader
	const std::string circleVertexPath = "Osu!Trainer/src/Shaders/CircleShader.vert";
	const std::string circleFragmentPath = "Osu!Trainer/src/Shaders/CircleShader.frag";
	const std::string circleName = "circleShader";
}