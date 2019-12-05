#include "Core.h"

#include <iostream>
#include <sstream>

// for the program to work properly, the reference to window must be passed into the core
Core::Core()
{
	std::cout << "core constructor requires reference to the working window to work properly" << std::endl;
	throw std::exception();
}

Core::Core(GLFWwindow* window) : Window(window)
{
}

// set time
int Core::time = 0;

// initialize the map
// the text file from the path will be open, and the first line will be read
void Core::MapInit(std::string path)
{
	map.open(path, std::fstream::in);
	if (!map)
	{
		std::cout << "beatmap not loaded" << std::endl;
		return;
	}

	std::string line;
	std::string x, y, beatTime;

	// read the first line
	getline(map, line);
	// dump the data into the variables
	std::stringstream ss(line);
	ss >> x;
	ss >> y;
	ss >> beatTime;
	// create the circle
	CreateCircle(std::stof(x), std::stof(y), std::stoi(beatTime));

	// read the next line
	getline(map, line);
	std::stringstream ss1(line);
	ss1 >> x;
	ss1 >> y;
	ss1 >> beatTime;
	// set the data
	CreateCircle(std::stof(x), std::stof(y), std::stoi(beatTime));
	animationTime = circle.back()->GetAnimationTime();
}

// parse the map
void Core::MapParser()
{
	// if the next circle hasn't started animated yet then do nothing
	if (time < animationTime)
		return;
	if (map.eof())
		return;

	std::string line;
	std::string x, y, beatTime;

	// read the next line
	getline(map, line);
	std::stringstream ss(line);
	ss >> x;
	ss >> y;
	ss >> beatTime;
	// set the data
	CreateCircle(std::stof(x), std::stof(y), std::stoi(beatTime));
	animationTime = circle.back()->GetAnimationTime();
}

// create a circle with the desired specs
void Core::CreateCircle(float x, float y, int beatTime)
{
	// create a new circle and push it into the back of the list
	// to draw multiple circles at the same time
	Circle* newCircle = new Circle();
	circle.push_back(newCircle);

	// set color
	newCircle->CreateColor(0.0f, 0.2f, 1.0f, 0.8f);
	// set attributes
	newCircle->SetAR(approachRate);
	newCircle->SetCS(circleSize);
	newCircle->SetOD(overallDifficulty);
	// map data
	newCircle->SetX(x);
	newCircle->SetY(y);
	newCircle->SetBeatTime(beatTime);

	newCircle->CreateCircle();
}

// animate the circle
// animateCircle is the pointer to a certain circle
void Core::AnimatePerCircle(Circle* animateCircle)
{
	// if the circle is not supposed to appear yet then do nothing
	if (time < animateCircle->GetAnimationTime())
		return;
	// if this condition is true then the circle is never pressed, causing a miss
	else if (time > animateCircle->GetEndTime())
	{
		// handling misses
		// DeleteCircle();
		return;
	}

	// generate that circle
	animateCircle->GenCircle();
}

// animate all circle
void Core::AnimateAllCircle()
{
	// loop through every circle in the list and animate each of them individually
	for (auto x : circle)
	{
		AnimatePerCircle(x);
	}
}

// delete the circle
void Core::DeleteCircle()
{
	// pop the queue and delete the circle
	// no need to worry about which one to delete since it'll always be the first one
	Circle* delCircle = circle.front();
	// circle.pop_front();
	delete delCircle;
}

// animate the entire screen
void Core::Draw()
{
	time += 30;
	AnimateAllCircle();
	MapParser();
}