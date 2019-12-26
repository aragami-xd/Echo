#include "CircleRenderer.h"
#include <Engine/Color.h>
#include <Engine/Attribute.h>
#include <mutex>

using namespace std;
constexpr float PI = 3.1415;

once_flag flag1, flag2, flag3;

VertexBufferLayout CircleRenderer::vbl;

CircleRenderer::CircleRenderer(Object* circle)
{
	object = circle;

	call_once(flag1, []() { vbl.Push<float>(2); });

	/* deprecated buffer functions */
	// calculate the dots on the circle and the initial ring
	float angle = 0;
	float baseX = 0, baseY = 0;
	for (int i = 0; i <= object::dotCount; i++)
	{
		angle = 2 * PI * i / object::dotCount;
		baseX = object->GetObjectSize() * cos(angle);
		baseY = object->GetObjectSize() * sin(angle);

		circleDot.push_back(object->GetX() + baseX);
		ringDot.push_back(object->GetX() + baseX * 2);

		circleDot.push_back(object->GetY() + baseY);
		ringDot.push_back(object->GetY() + baseY * 2);
	}

	// create and bind the buffers
	vbCircle = new VertexBuffer(circleDot.data(), sizeof(float) * circleDot.size(), GL_STATIC_DRAW);
	vbRing = new VertexBuffer(ringDot.data(), sizeof(float) * ringDot.size(), GL_STREAM_DRAW);

	vaCircle.AddBuffer(*vbCircle, vbl);
	vaRing.AddBuffer(*vbRing, vbl);
}

/* buffer drawing functions */
// get the ringDotBuf array at a certain time
float* CircleRenderer::GetRingDot(int time)
{
	// calculate new dots on the ring, based on the timestamp
	float remaining = (abs((object->GetBeatTime() - time)) / (float)object->GetAnimationLength()) + 1;

	float angle = 0;
	for (int i = 0; i < ringDot.size(); i += 2)
	{
		angle = 2 * PI * i / object::dotCount;

		ringDot[i] = object->GetX() + object->GetObjectSize() * cos(angle) * remaining;
		ringDot[i + 1] = object->GetY() + object->GetObjectSize() * sin(angle) * remaining;
	}

	return ringDot.data();
}

// draw circle using buffer
void CircleRenderer::DrawCircle()
{
	vaCircle.Bind();
	glDrawArrays(GL_LINE_LOOP, 0, object::dotCount);
}
// draw approach circle (ring) using buffer
void CircleRenderer::DrawRing(int time)
{
	vbRing->Update(GetRingDot(time), sizeof(float) * ringDot.size(), GL_STREAM_DRAW);
	vaRing.Bind();
	glDrawArrays(GL_LINE_LOOP, 0, object::dotCount);
}
// draw the object using buffer
void CircleRenderer::Draw(int time, Shader* shader)
{
	shader->Bind();

	shader->SetUniform1f("borderThickness", object::circleBorderThickness);
	shader->SetUniformVec4f("color", COLOR_LIGHT_BLUE.rgba);
	DrawCircle();

	shader->SetUniform1f("borderThickness", object::ringBorderThickness);
	shader->SetUniformVec4f("color", COLOR_WHITE.rgba);
	DrawRing(time);
}

CircleRenderer::~CircleRenderer()
{
	delete vbCircle;
	delete vbRing;
}