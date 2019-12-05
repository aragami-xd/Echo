#pragma once

#include <fstream>
#include <string>

class Beatmap
{
private:
	/* private variables */
	// the text file contains all of the pre-generated circle coordinate
	std::fstream map;

	// beat per minute (if you don't know what it is, google it)
	int bpm;

	// star
	float star;

	// difficulty title (in terms of stars)
	enum title
	{
		EASY = 1,
		MEDIUM = 2,
		HARD = 3,
		INSANE = 4,
		EXTREME = 5,
		EXTRA = 6,
		FOUR_DIMENSIONS = 7
	};

public:
};