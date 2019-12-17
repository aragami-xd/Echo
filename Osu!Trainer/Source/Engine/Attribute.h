#pragma once
#include <string>

/* this file contain public attributes related to how the game is set up */

// number of dots to draw the circle
constexpr int DotCount = 120;

// height and width of the window and window aspect ratio
constexpr int WindowWidth = 1280;	// height
constexpr int WindowHeight = 720;	// width
const float WidthDivHeight = WindowWidth / (float)WindowHeight;	// width divide height
const float HeightDivWidth = WindowHeight / (float)WindowWidth;	// height divide width

// paths
const std::string BasicVertexPath = "Osu!Trainer/Source/Shaders/Shader.vert";
const std::string BasicFragmentPath = "Osu!Trainer/Source/Shaders/Shader.frag";

const std::string CircleVertexPath = "Osu!Trainer/Source/Shaders/CircleShader.vert";
const std::string CircleFragmentPath = "Osu!Trainer/Source/Shaders/CircleShader.frag";

const std::string BeatmapPath = "Osu!Trainer/Library/Beatmaps/map.txt";		// beatmap