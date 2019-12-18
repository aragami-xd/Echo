#pragma once

#include <string>
#include <vector>
#include <Engine/Instrument.h>

/* object format contains the structs holding the data parsed from the beatmap file */

// slider object
struct MapSlider
{
	// position of the start of the slider
	float X;
	float Y;

	// timestamp that the beat starts and ends and its ticks
	int BeatStart;
	int BeatEnd;
	std::vector<int> BeatTick;

	// the slider curve equation
	std::string Equation;

	// instrumental that will be played at the start/end of the circle and each tick
	Instrument instrument;
	Instrument tick;
};
