#include "osu!gen.h"
#include <Gen/GenCircle.h>

OsuGen::Program::Program()
{
	patterns = new EchoGen::PatternList("PatternList.txt");

	int index = 0;
	std::ofstream map("map.txt");
	std::vector<int> beat = { 0,500,1000 };

	GenCircle gc;
	gc.Gen(patterns, beat, index, map);
}

void OsuGen::Program::Run()
{
}

OsuGen::Program::~Program()
{
	delete patterns;
}