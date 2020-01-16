#include "CircleComponent.h"
using namespace std;

void CircleComponent::Render(ShaderList* shaders, int time)
{
	// don't render if it's tapped
	if (!enableRender)
		return;

	// get the data
	Shader* shader = shaders->At("basic");
	shader->Bind();

	auto circle = element["circle"];

	/* draw the inner circle */
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(circle->GetX(time), circle->GetY(time), 0.0f));
	Orthographic::SetViewMatrix(shader, view);

	// render
	shader->SetShaderUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
	Renderer::StrokeWeight(4);
	Renderer::Render(circle->GetVertexArray(), settings["circle"]["vertices"], GL_LINE_LOOP);

	/* draw the approach circle (ring) */
	float scale = (float)settings["object"]["ringScale"] * object->GetApproachScale(time) + 1;

	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(circle->GetX(time), circle->GetY(time), 0.0f));
	view = view * glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, 1.0f));
	Orthographic::SetViewMatrix(shader, view);
		
	// render
	shader->SetShaderUniform4f("uColor", 0.6f, 0.7f, 0.8f, 1.0f);
	Renderer::StrokeWeight(2);
	Renderer::Render(circle->GetVertexArray(), settings["circle"]["vertices"], GL_LINE_LOOP);
}

int CircleComponent::OnEvent(float x, float y, int time)
{
	// distant between cursor and center
	float dist = sqrt(pow(x - element["circle"]->GetX(time), 2) + pow(y - element["circle"]->GetY(time), 2));
	if (dist < objectSize)
	{
		enableRender = false;
		return object->GetScore(time);
	}
	else
	{
		return -1;
	}
}
