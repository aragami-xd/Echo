#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Components/MapCircle.h>
#include <Components/MapSlider.h>

// types of object
enum class ParserType
{
	NONE = -1,
	CIRCLE = 1,
	SLIDER = 2,
};

/* the parser contains only static functions, used to parse the data from the beatmap file */
class Parser
{
private:
	// the map itself
	static std::fstream map;

	// the current line
	static std::string line;

	// metadata - song setup (there will be metadata for song detail)
	static float approachRate;
	static float circleSize;
	static float overallDifficulty;
	static float hpDrain;

public:
	// load the map
	static void Load(std::string& path)
	{
		// check the map
		map.open(path);
		if (!map)
		{
			std::cout << "beatmap not loaded" << std::endl;
			return;
		}

		// when the map is loaded, the first line will be read
		getline(map, line);
		return;
	}

	// peek ahead one line to know which type the next object is
	static ParserType Peek()
	{
		if (line.empty())
			return ParserType::NONE;	// eof
		else if (line.find("#circle") != line.npos)
			return ParserType::CIRCLE;	// circle
		else if (line.find("#slider") != line.npos)
			return ParserType::SLIDER;	// slider
		else
			throw std::exception();		// this shouldn't happen
	}

	/* parsing functions
		- you should peek ahead before reading these object in to know which
		type of	object appears next (circle, slider...)
		- if call the right function then nothing special will happen
		- if call the wrong type and the stream is too long, the function
		will discard the remaining
		- if call the wrong type and the stream is too short, the function
		will fill the missing data with the default one
	*/

	// if stringstream::eof(): a wrong function has been called, print out warning
	static inline bool StreamEnd(std::stringstream& ss)
	{
		if (ss.eof())
		{
			std::cout << "warning: wrong object type parsed" << std::endl;
			return false;
		}
		return true;
	}

	// read the line in as a circle
	static MapCircle ParseCircle()
	{
		// default data
		float x = 0.0f, y = 0.0f;
		int beatStart = 0;
		Instrument instrument = Instrument::STD_DRUM;

		std::stringstream ss(line);
		std::string token;

		ss >> token;		// discard first type token

		if (StreamEnd(ss))
		{
			ss >> token;	// x
			x = std::stof(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// y
			y = std::stof(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// beatTime
			beatStart = std::stoi(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// instrument passed in as int
			instrument = (Instrument)(std::stoi(token));
		}

		// read the next line
		getline(map, line);

		return { x, y, beatStart, instrument };
	}

	// read the line in as a slider
	static MapSlider ParseSlider()
	{
		// default data
		float x = 0.0f, y = 0.0f;
		int beatStart = 0, beatEnd = 0;
		std::vector<int> beatTick = {};
		std::string equation = "1";
		Instrument instrument = Instrument::STD_DRUM;
		Instrument tick = Instrument::STD_TICK;

		std::stringstream ss(line);
		std::string token;

		ss >> token;		// discard the first type token

		if (StreamEnd(ss))
		{
			ss >> token;	// x
			x = std::stof(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// y
			y = std::stof(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// beatStart
			beatStart = std::stoi(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// beatEnd
			beatEnd = std::stoi(token);
		}

		if (StreamEnd(ss))
		{
			ss >> equation;	// slider curve equation
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// instrument
			instrument = (Instrument)(std::stoi(token));
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// tick instrument
			tick = (Instrument)(std::stoi(token));
		}

		while (!ss.eof())
		{
			ss >> token;
			beatTick.push_back(std::stoi(token));
		}

		// read the next line
		getline(map, line);

		return { x, y, beatStart, beatEnd, beatTick, equation, instrument, tick };
	}
};

// define static variables
std::fstream Parser::map;
std::string Parser::line = "";
float Parser::approachRate = 0.0f;
float Parser::circleSize = 0.0f;
float Parser::overallDifficulty = 0.0f;
float Parser::hpDrain = 0.0f;