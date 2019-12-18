#pragma once

#include <string>
#include <Engine/Instrument.h>

/* object format contains the structs holding the data parsed from the beatmap file */

// circle object
struct MapCircle
{
	// position of the circle
	float X;
	float Y;

	// timestamp that the beat starts
	int BeatStart;

	// the instrument that will be played with the circle
	Instrument instrument;
};