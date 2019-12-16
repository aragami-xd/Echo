#pragma once
#include <string>

/* this file contain public attributes related to how the game is set up */

// number of dots to draw the circle
constexpr int DotCount = 60;

// height and width of the window and window aspect ratio
constexpr int WindowWidth = 640;	// height
constexpr int WindowHeight = 480;	// width
const float WidthDivHeight = WindowWidth / (float)WindowHeight;	// width divide height
const float HeightDivWidth = WindowHeight / (float)WindowWidth;	// height divide width

// paths
const std::string VertexPath = "Osu!Trainer/Source/Shaders/Shader.vert";		// vertex shader
const std::string FragmentPath = "Osu!Trainer/Source/Shaders/Shader.frag";		// fragment shader
const std::string BeatmapPath = "Osu!Trainer/Library/Beatmaps/map.txt";			// beatmap