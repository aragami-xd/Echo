#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

struct ParserCircle
{
	// position of the circle
	float X;
	float Y;
	// timestamp that the beat starts
	int BeatStart;
	// the instrument that will be played with the circle
	Instrument instrument;
};

struct ParserSlider
{
	// position of the start of the slider
	float X;
	float Y;
	// timestamp that the beat starts and ends
	int BeatStart;
	int BeatEnd;
	// the slider curve equation
	string Equation;
	// instrumental that will be played at the start/end of the circle and each tick
	Instrument instrument;
	Instrument tick;
};

enum class Instrument
{
	STD_DRUM = 0,
	STD_CLAP = 1,
	STD_WHISTLE = 2,
	MANIA_NOTE1 = 3,
	MANIA_NOTE2 = 4,
	MANIA_NOTE3 = 5,
	MANIA_NOTE4 = 6,
};

class Parser
{
private:
	static ifstream map;

public:
	static void Load(string path)
	{
		// check the map
		map.open(path);
		if (!map.open)
		{
			cout << "beatmap not loaded" << endl;
			throw exception();
		}
		return;
	}

	static auto Parse()
	{
		string line, token;
		getline(map, line);

		// if that line contains data of the circle
		if (line[0] == 'c')
		{
			float x, y;
			int beatStart;

			// convert tokens into float and int
			stringstream ss(line);
			ss >> token;	// discard first type token
			ss >> token;	// x
			x = stof(token);
			ss >> token;	// y
			y = stof(token);
			ss >> token;	// beatTime
			beatStart = stoi(token);
		}
		else if (line[0] == 's')
		{
		}
	}
};