#include "Attribute.h"
#include "Parser.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Components/CircleRenderer.h>
#include <Components/SliderRenderer.h>

#include "Core.h"

using namespace std;

Core::Core(string path)
{
	// setup time variables
	time = 0;
	start = (int)clock();
	prevFrame = start;

	// initialize the map
	MapInit(path);

	// setup the shaders
	shader.AddShader(shader::basicName, shader::basicVertexPath, shader::basicFragmentPath);
	glm::mat4 proj = glm::ortho(-1.0f * window::wdh, 1.0f * window::wdh, -1.0f, 1.0f);
	// setup circleshader
	shader.BindShader(shader::basicName);
	shader.GetShader(shader::basicName)->SetUniformMat4f("proj", proj);
	shader.GetShader(shader::basicName)->SetUniformMat4f("view", glm::mat4(1.0));
}

// draw all objects
void Core::DrawAllObject()
{
	// go through all objects
	for (int i = index; i < object.size(); i++)
	{
		if (time < object[i].object->GetStartTime())
		{
			// every object afterwards are not supposed to appear yet, so we break the loop here
			break;
		}
		else if (time > object[i].object->GetEndTime())
		{
			index++;
		}
		else
		{
			// draw the object
			object[i].objectRenderer->Draw(time, shader.GetShader(shader::circleName));
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
			// get the data, create the circle and renderer and add it to the vector
			MapCircle parseCircle = Parser::ParseCircle();
			vector<int> beat;
			beat.push_back(parseCircle.BeatStart);
			Object* circle = new Circle(
				parseCircle.X,				// x
				parseCircle.Y,				// y
				beat,		// beatStart
				approachRate,				// AR
				circleSize,					// CS
				overallDifficulty			// OD
			);
			ObjectRenderer* circleRenderer = new CircleRenderer(circle);
			object.push_back(ObjectComponent(circle, circleRenderer));
		}
		//else if (Parser::Peek() == ParserType::SLIDER)
		//{
		//	// get the data, create the slider and add it to the list
		//	MapSlider parseSlider = Parser::ParseSlider();
		//	Object* slider = new Slider(
		//		parseSlider.X,				// x
		//		parseSlider.Y,				// y
		//		parseSlider.BeatStart,		// beatStart
		//		parseSlider.BeatEnd,		// beatEnd
		//		parseSlider.BeatTick,		// beatTick(s)
		//		parseSlider.Equation,		// curve equation
		//		approachRate,				// AR
		//		circleSize,					// CS
		//		overallDifficulty			// OD
		//	);
		//	ObjectRenderer* sliderRenderer = new SliderRenderer(slider);
		//	object.push_back(ObjectComponent(slider, sliderRenderer));
		//}
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
	for (auto x : object)
	{
		delete x.object;
		delete x.objectRenderer;
	}
}