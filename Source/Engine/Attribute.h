#pragma once

/* this file contain public attributes related to how the game is set up */

// number of dots to draw the circle
const unsigned int DotCount = 120;

// height and width of the window and window aspect ratio
const int WindowWidth = 720;	// height
const int WindowHeight = 480;	// width
const float WidthDivHeight = WindowWidth / (float)WindowHeight;	// width divide height
const float HeightDivWidth = WindowHeight / (float)WindowWidth;	// height divide width