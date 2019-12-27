#include "Object.h"
#include "Attribute.h"
#include <mutex>
using namespace std;

once_flag flagObject;

const int Object::scaleAR = object::objectSpeedScaling;
const float Object::scaleCS = object::objectSizeScaling;

float Object::approachRate;
float Object::circleSize;
float Object::overallDifficulty;

float Object::objectSize;
int Object::animationLength;
int Object::threeHundred;
int Object::oneHundred;
int Object::fifty;

Object::Object(float obj_x, float obj_y, vector<int>& obj_beats, /*string& obj_equation, vector<Instrument>& obj_instrument,*/ float AR, float CS, float OD) :
	x(obj_x), y(obj_y), beats(obj_beats)/*, equation(obj_equation), instruments(obj_instrument)*/, beatIndex{ 0 }
{
	call_once(flagObject, [AR, CS, OD]() {
		// AR, CS, OD
		approachRate = AR;
		circleSize = CS;
		overallDifficulty = OD;

		objectSize = scaleCS / circleSize;

		// timestamp variables
		animationLength = (int)(scaleAR / approachRate);
		threeHundred = (int)(animationLength / (3 * overallDifficulty));
		oneHundred = (int)(threeHundred * 1.1);
		fifty = (int)(threeHundred * 1.3);
	});

	startTime = beats.front() - animationLength;
	endTime = beats.back() - fifty;
}

void Object::EquationParser()
{
}
