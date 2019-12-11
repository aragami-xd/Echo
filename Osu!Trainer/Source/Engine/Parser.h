#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// circle object
struct MapCircle
{
	// position of the circle
	float X{ 0.0f };
	float Y{ 0.0f };

	// timestamp that the beat starts
	int BeatStart{ 0 };

	// the instrument that will be played with the circle
	Instrument instrument{ Instrument::STD_DRUM };
};

// slider object
struct MapSlider
{
	// position of the start of the slider
	float X{ 0.0f };
	float Y{ 0.0f };

	// timestamp that the beat starts and ends
	int BeatStart{ 0 };
	int BeatEnd{ 0 };

	// the slider curve equation
	string Equation{ "" };

	// instrumental that will be played at the start/end of the circle and each tick
	Instrument instrument{ Instrument::STD_DRUM };
	Instrument tick{ Instrument::STD_TICK };
};

// object instrument: drump, clap, whistle, tick...
enum class Instrument
{
	STD_DRUM = 0,
	STD_CLAP = 1,
	STD_WHISTLE = 2,
	STD_TICK = 3,
};

// types of object
enum class ParserType
{
	CIRCLE = 1,
	SLIDER = 2,
};

/* the parser contains only static function, used to parse the data from the beatmap file */
class Parser
{
private:
	// the map itself
	static ifstream map;

	// the current line
	static std::string line;

public:
	// load the map
	static void Load(string path)
	{
		// check the map
		map.open(path);
		if (!map.open)
		{
			cout << "beatmap not loaded" << endl;
			//throw exception();
		}

		// when the map is loaded, the first line will be read
		getline(map, line);
		return;
	}

	// peek ahead one line to know which type the next object is
	static ParserType Peek()
	{
		if (line.find("#circle") != line.npos)
			return ParserType::CIRCLE;
		else if (line.find("#slider") != line.npos)
			return ParserType::SLIDER;
	}

	/* parsing functions
		- peek ahead before reading these object in to know which type of
		object appears next (circle, slider...)
		- if call the right function then nothing special will happen
		- if call the wrong type and the stream is too long, the function
		will discard the remaining
		- if call the wrong type and the stream is too short, the function
		will fill the missing data with the default one
	*/

	// if stringstream.eof(): a wrong function has been called, print out warning
	static inline bool StreamEnd(stringstream& ss)
	{
		if (ss.eof())
		{
			cout << "warning: wrong object type parsed" << endl;
			return false;
		}
		return true;
	}

	// read the line in as a circle
	static MapCircle ParseCircle()
	{
		float x = 0.0f, y = 0.0f;
		int beatStart = 0;
		Instrument instrument = Instrument::STD_DRUM;

		stringstream ss(line);
		string token;

		ss >> token;		// discard first type token

		if (StreamEnd(ss))
		{
			ss >> token;	// x
			x = stof(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// y
			y = stof(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// beatTime
			beatStart = stoi(token);
		}

		// read the next line
		getline(map, line);

		return { x, y, beatStart, instrument };
	}

	// read the line in as a slider
	static MapSlider ParseSlider()
	{
		float x = 0.0f, y = 0.0f;
		int beatStart = 0, beatEnd = 0;
		string equation = "1";
		Instrument instrument = Instrument::STD_DRUM;
		Instrument tick = Instrument::STD_TICK;

		stringstream ss(line);
		string token;

		ss >> token;		// discard the first type token

		if (StreamEnd(ss))
		{
			ss >> token;	// x
			x = stof(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// y
			y = stof(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// beatStart
			beatStart = stoi(token);
		}

		if (StreamEnd(ss))
		{
			ss >> token;	// beatEnd
			beatEnd = stoi(token);
		}

		if (StreamEnd(ss))
		{
			ss >> equation;	// slider curve equation
		}

		// read the next line
		getline(map, line);

		return { x, y, beatStart, beatEnd, equation, instrument, tick };
	}

};