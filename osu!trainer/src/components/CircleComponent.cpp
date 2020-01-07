#include "CircleComponent.h"
using namespace std;

void CircleComponent::Render(ShaderList* shaders, int time)
{
	// don't render if it's tapped
	if (!enableRender)
		return;

	Shader* shader = shaders->At("basic");
	shader->Bind();

	// draw the inner circle
	glm::mat4 viewCircle = glm::translate(glm::mat4(1.0f), glm::vec3(object->GetX(), object->GetY(), 0.0f));
	Orthographic::SetViewMatrix(shader, viewCircle);
	
	// render
	Renderer::StrokeWeight(4);
	Renderer::Render(element["circle"]->GetVertexArray(), settings["circle"]["vertices"], GL_LINE_LOOP);

	// draw the approach circle (ring)
	float scale = (float)settings["object"]["ringScale"] * object->GetApproachScale(time) + 1;

	glm::mat4 viewRing = glm::translate(glm::mat4(1.0f), glm::vec3(object->GetX(), object->GetY(), 0.0f));
	viewRing = viewRing * glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, 1.0f));
	Orthographic::SetViewMatrix(shader, viewRing);

	// render
	Renderer::StrokeWeight(2);
	Renderer::Render(element["circle"]->GetVertexArray(), settings["circle"]["vertices"], GL_LINE_LOOP);
}

int CircleComponent::OnEvent(float x, float y)
{
	// distant between cursor and center
	float dist = sqrt(pow(x - object->GetX(), 2) + pow(y - object->GetY(), 2));
	if (dist < objectSize)
	{
		enableRender = false;
		return 0;
	}
	else
	{
		return -1;
	}
}
