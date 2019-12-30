#include "Object.h"
using namespace std;

Object::Object(float ox, float oy) :
	x(ox), y(oy), startTime(0), endTime(0)
{
	approachTime = scaleAR / AR;

	// score scaling
	score300 = approachTime / (OD * score300Scaling);
	score100 = approachTime / (OD * score100Scaling);
	score50 = approachTime / (OD * score50Scaling);
}

/* static variables */
float Object::AR = 10.0f;
float Object::CS = 5.0f;
float Object::OD = 10.0f;

int Object::scaleAR = 4500;
float Object::scaleCS = 0.3f;

float Object::score300Scaling = 1.2f;
float Object::score100Scaling = 1.4f;
float Object::score50Scaling = 1.5f;