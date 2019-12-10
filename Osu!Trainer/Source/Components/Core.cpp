#include "Core.h"
#include "../Engine/Attribute.h"
#include "../Buffers/CircleRenderer.h"
#include <iostream>
#include <sstream>

using namespace std;

Core::Core()
{
	va = new VertexArray();
	vbl = new VertexBufferLayout();

	// vertex array and layout
	vbl->Push<float>(2);

	// setup the index buffer
	for (int i = 0; i < ::DotCount * 3; i += 3)
	{
		indices[i] = 0;
		indices[i + 1] = i * 2 + 1;
		indices[i + 2] = i * 2 + 2;
	}

	ib = new IndexBuffer(indices, ::DotCount * 3);
}

Core::~Core()
{
	delete va;
	delete vbl;
	delete ib;
}

// set time
int Core::time = -1000;

// initialize the map
// the text file from the path will be open, and the first line will be read
void Core::MapInit(string path)
{
	map.open(path, fstream::in);
	if (!map)
	{
		cout << "beatmap not loaded" << endl;
		return;
	}

	string line;
	string x, y, beatTime;

	// read the first line
	getline(map, line);
	// dump the data into the variables
	stringstream ss(line);
	ss >> x;
	ss >> y;
	ss >> beatTime;
	// create the circle
	CreateCircle(stof(x), stof(y), stoi(beatTime));

	// read the next line
	getline(map, line);
	stringstream ss1(line);
	ss1 >> x;
	ss1 >> y;
	ss1 >> beatTime;
	// set the data
	CreateCircle(stof(x), stof(y), stoi(beatTime));
	animationTime = circle.back()->GetAnimationTime();
}

// parse the map
void Core::MapParser()
{
	// if the next circle hasn't started animated yet then do nothing
	if (time < animationTime)
		return;

	string line;
	string x, y, beatTime;

	// read the next line
	if (!getline(map, line))
		return;

	stringstream ss(line);
	ss >> x;
	ss >> y;
	ss >> beatTime;
	// set the data
	CreateCircle(stof(x), stof(y), stoi(beatTime));
	animationTime = circle.back()->GetAnimationTime();
}

// create a circle with the desired specs
void Core::CreateCircle(float x, float y, int beatTime)
{
	Color color = { 1.0f, 1.0f, 1.0f, 1.0f };

	// create a new circle and push it into the back of the list
	// to draw multiple circles at the same time
	Circle* newCircle = new Circle(x, y, color, approachRate, circleSize, overallDifficulty, beatTime);
	va->AddBuffer(*(newCircle->GetCircleBuffer()), *vbl);
	va->AddBuffer(*(newCircle->GetRingBuffer(time)), *vbl);

	circle.push_back(newCircle);
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

	if (time > animateCircle->GetBeatTime())
		animateCircle->GetRingBuffer(time)->Unbind();
	else
		animateCircle->GetRingBuffer(time)->Bind();
}

// animate all circle
void Core::AnimateAllCircle()
{
	// loop through every circle in the list and animate each of them individually
	for (auto i = circle.rbegin(); i != circle.rend(); i++)
	{
		AnimatePerCircle(*i);
	}
}

// delete the circle
void Core::DeleteCircle()
{
	// pop the queue and delete the circle
	// no need to worry about which one to delete since it'll always be the first one
	delete circle.front();
	circle.pop_front();
}

// animate the entire screen
void Core::Draw()
{
	time += 30;
	AnimateAllCircle();

	va->Bind();
	glDrawElements(GL_TRIANGLES, DotCount * 3, GL_UNSIGNED_INT, nullptr);

	MapParser();
}