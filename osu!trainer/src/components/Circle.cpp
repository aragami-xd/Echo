#include "Circle.h"
using namespace std;

Circle::Circle(float cx, float cy, int beatTime) :
	Object(cx, cy, vector<int>({ beatTime })/*, noEquation, noEquation, noEquation, noEquation*/)
{}

int Circle::GetScore()
{
	return 0;
}
