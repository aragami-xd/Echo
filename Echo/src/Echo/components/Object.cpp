#include "Object.h"
#include <Settings.h>
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
float Object::AR = settings["metadata"]["ar"];
float Object::OD = settings["metadata"]["od"];
int Object::scaleAR = settings["metadata"]["scaleAR"];

float Object::score300Scaling = settings["metadata"]["score300"];
float Object::score100Scaling = settings["metadata"]["score100"];
float Object::score50Scaling = settings["metadata"]["score50"];