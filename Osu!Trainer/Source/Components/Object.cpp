#include "Object.h"
#include "../Engine/Attribute.h"
using namespace std;

const int Object::scaleAR = 5000;
const float Object::scaleCS = 1.0f;

float Object::approachRate = 9.0f;
float Object::circleSize = 5.0f;
float Object::overallDifficulty = 9.0f;

float Object::objectRadius = 0.0f;
int Object::animationLength = 0;
int Object::threeHundred = 0;
int Object::oneHundred = 0;
int Object::fifty = 0;

Object::Object(float o_x, float o_y, float AR, float CS, float OD) :
	x(o_x), y(o_y)
{
	// AR, CS, OD
	approachRate = AR;
	circleSize = CS;
	overallDifficulty = OD;

	// object radius
	objectRadius = scaleCS / circleSize;

	// timestamp variables
	animationLength = (int)(scaleAR / approachRate);
	threeHundred = (int)(animationLength / (3 * overallDifficulty));
	oneHundred = (int)(threeHundred * 1.1);
	fifty = (int)(threeHundred * 1.3);
}