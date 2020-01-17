#include "Object.h"
#include <Settings.h>
using namespace std;

Object::Object(const vector<int>& beat) :
	beats(beat), beatIndex(0), startTime(0), endTime(0)
{
	approachTime = scaleAR / AR;

	// score scaling
	score300 = approachTime / (OD * score300Scaling);
	score100 = approachTime / (OD * score100Scaling);
	score50 = approachTime / (OD * score50Scaling);
}

float Object::GetApproachScale(int time)
{
	if (time < beats.front())
		return abs(beats.front() - time) / (float)approachTime;
	else
		return 0;
}

/* static variables */
float Object::AR = settings["metadata"]["ar"];
float Object::OD = settings["metadata"]["od"];
int Object::scaleAR = settings["metadata"]["scaleAR"];

float Object::score300Scaling = settings["metadata"]["score300"];
float Object::score100Scaling = settings["metadata"]["score100"];
float Object::score50Scaling = settings["metadata"]["score50"];