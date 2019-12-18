#include "Slider.h"
using namespace std;

// equation parser
void Slider::EquationParser()
{
}

Slider::Slider(float x, float y, int beatStart, int beatEnd, std::vector<int> beatTick, string s_equation, float AR, float CS, float OD) :
	Object(x, y, AR, CS, OD)
{
	beatStartTime = beatStart;
	beatEndTime = beatEnd;
	beatTickTime = beatTick;
	equation = s_equation;

	startTime = beatStartTime - animationLength;
	endTime = beatEndTime + fifty;
}

void Slider::Draw(int time)
{
}
