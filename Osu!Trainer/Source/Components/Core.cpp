#include "Core.h"
#include "CircleRenderer.h"
#include "../Engine/Attribute.h"
#include "../Engine/Parser.h"
#include <Windows.h>
using namespace std;

Core::Core()
{
	// setup time variables
	time = 0;
	start = (int)clock();
	prevFrame = start;

	shader = new Shader(::VertexPath, ::FragmentPath);
	shader->SetUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
}

void Core::DrawOneCircle(Circle* circle)
{
	circle->Draw(time);
}

void Core::DrawOneSlider(Slider* slider)
{
}

void Core::DrawAllObject()
{
	// loop through circle
	for (int i = circleIndex; i < allCircle.size(); i++)
	{
		// every circle afterwards are not supposed to appear yet
		if (time < allCircle[i]->GetStartTime())	
			break;
		else if (time > allCircle[i]->GetEndTime())
			circleIndex++;

		DrawOneCircle(allCircle[i]);
	}

	// loop through sliders
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
				circle.BeatStart,		// beatStart
				approachRate,			// AR
				circleSize,				// CS
				overallDifficulty		// OD
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
				slider.BeatStart,		// beatStart
				slider.BeatEnd,			// beatEnd
				slider.BeatTick,		// beatTick(s)
				slider.Equation,		// curve equation
				approachRate,			// AR
				circleSize,				// CS
				overallDifficulty		// OD
			);
			allSlider.push_back(newSlider);
		}
	}
}

void Core::Draw()
{
	DrawAllObject();
	
	// update the time
	time = (int)clock() - start;
	//cout << "fps: " << 1000 / (float)(time - prevFrame) << "\r";
	//prevFrame = time;
}

Core::~Core()
{
	for (int i = 0; i < allCircle.size(); i++)
		delete allCircle[i];
	for (int i = 0; i < allSlider.size(); i++)
		delete allSlider[i];
	delete shader;
}