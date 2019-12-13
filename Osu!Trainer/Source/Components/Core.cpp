#include "Core.h"
#include "../Engine/Parser.h"
using namespace std;

Core::Core()
{
}

void Core::DrawOneCircle(Circle* circle)
{
}

void Core::DrawOneSlider(Slider* slider)
{
}

void Core::DrawAllObject()
{
	for (auto x : allCircle)
	{
	}

	for (auto x : allSlider)
	{
	}
}

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
			Circle* newCircle = new Circle(
				circle.X,				// x
				circle.Y,				// y
				approachRate,			// AR
				circleSize,				// CS
				overallDifficulty,		// OD
				circle.BeatStart,		// beatStart
				colorList.front()		// circleColor
			);
			allCircle.push_back(newCircle);
		}
		else if (Parser::Peek() == ParserType::SLIDER)
		{
			// get the data, create the slider and add it to the list
			MapSlider slider = Parser::ParseSlider();
			Slider* newSlider = new Slider(
				slider.X,				// x
				slider.Y,				// y
				approachRate,			// AR
				circleSize,				// CS
				overallDifficulty,		// OD
				slider.BeatStart,		// beatStart
				slider.BeatEnd,			// beatEnd
				slider.BeatTick,		// beatTick(s)
				colorList.front(),		// sliderColor
				colorList.front()		// sliderBallColor
			);
			allSlider.push_back(newSlider);
		}
	}
}

void Core::Draw()
{
}

Core::~Core()
{
}