#include "Object.h"
using namespace std;

Object::Object(float ox, float oy, vector<int>& obeats/*,
	const Equation& rx, const Equation& ry, const Equation& mx, const Equation& my*/) :

	x(ox), y(oy), beats(obeats), currentBeat(0),
	/*renderEquationX(rx), renderEquationY(ry), movementEquationX(mx), movementEquationY(my),*/
	approachTime(scaleAR / AR)
{
	// score scaling
	score300 = approachTime / (OD * score300Scaling);
	score100 = approachTime / (OD * score100Scaling);
	score50 = approachTime / (OD * score50Scaling);

	startTime = beats.front() - approachTime;
	endTime = beats.back() + score50;
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