#include "CircleRenderElement.h"
#include <OsuSettings.h>

OsuTrainer::CircleRenderElement::CircleRenderElement(float cx, float cy, float circleRadius) :
	x(cx), y(cy)
{
	// caculate the vertices coordinate
	for (double i = 0; i < 2 * PI; i += 2 * PI / OsuTrainer::settings["circle"]["vertices"]) {
		vertices.push_back(cos(i) * circleRadius);
		vertices.push_back(sin(i) * circleRadius);
	}
	vertices.insert(vertices.end(), { circleRadius, 0.0f });

	// create buffers
	vl = new Echo::VertexLayout();		// vl
	vb = new Echo::VertexBuffer(vertices.data(), vertices.size() * sizeof(float));	// vb
	va = new Echo::VertexArray();			// va
	vl->Push<float>(2);
	va->AddBuffer(*vl, *vb);
}

OsuTrainer::CircleRenderElement::~CircleRenderElement()
{
	delete vl;
	delete vb;
	delete va;
}