#include "Attribute.h"
#include "Parser.h"
#include <Components/Circle.h>
#include <Components/Slider.h>

#include "Core.h"

using namespace std;

Core::Core(string path, ShaderList s) :
	shader(s)
{
	// setup time variables
	time = 0;
	start = (int)clock();
	prevFrame = start;

	// initialize the map
	MapInit(path);

	// bind shader
	shader.CircleShader->Bind();
}

// draw all objects
void Core::DrawAllObject()
{
	// go through all objects
	for (int i = objectIndex; i < allObject.size(); i++)
	{
		if (time < allObject[i]->GetStartTime())
		{
			// every object afterwards are not supposed to appear yet, so we break the loop here
			break;
		}
		else if (time > allObject[i]->GetEndTime())
		{
			//delete allObject[i];
			objectIndex++;
		}
		else
		{
			// draw the object
			allObject[i]->Draw(time);
		}

	}
}

// initialize the map
void Core::MapInit(std::string path)
{
	// load the map in the parser
	Parser::Load(path);

	// continue parsing the map until eof
	while (Parser::Peek() != ParserType::NONE)
	{
		if (Parser::Peek() == ParserType::CIRCLE)
		{
			// get the data, create the circle and add it to the list
			MapCircle circle = Parser::ParseCircle();
			Object* newCircle = new Circle(
				circle.X,				// x
				circle.Y,				// y
				circle.BeatStart,		// beatStart
				approachRate,			// AR
				circleSize,				// CS
				overallDifficulty		// OD
			);
			allObject.push_back(newCircle);
		}
		else if (Parser::Peek() == ParserType::SLIDER)
		{
			// get the data, create the slider and add it to the list
			MapSlider slider = Parser::ParseSlider();
			Object* newSlider = new Slider(
				slider.X,				// x
				slider.Y,				// y
				slider.BeatStart,		// beatStart
				slider.BeatEnd,			// beatEnd
				slider.BeatTick,		// beatTick(s)
				slider.Equation,		// curve equation
				approachRate,			// AR
				circleSize,				// CS
				overallDifficulty		// OD
			);
			allObject.push_back(newSlider);
		}
	}
}

// draw everything on the screen
void Core::Draw()
{
	DrawAllObject();

	// update the time
	time = (int)clock() - start;
}

Core::~Core()
{
	for (int i = 0; i < allObject.size(); i++)
		delete allObject[i];
}