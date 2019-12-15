#include "Slider.h"
using namespace std;

// equation parser
void Slider::EquationParser()
{
}

Slider::Slider(float sx, float sy, int sBeatStart, int sBeatEnd, std::vector<int> sBeatTick, string sEquation)
{
	x = sx;
	y = sy;
	beatStartTime = sBeatStart;
	beatEndTime = sBeatEnd;
	beatTickTime = sBeatTick;
	equation = sEquation;

	startTime = beatStartTime - animationLength;
	endTime = beatEndTime + fifty;

}