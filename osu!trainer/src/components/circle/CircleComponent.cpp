#include "CircleComponent.h"

void OsuTrainer::CircleComponent::Render(Echo::ShaderList* shaders, int time)
{
	// don't render if it's tapped
	if (!enableRender)
		return;

	/* get the data */
	Echo::Shader* shader = shaders->At("basic");			// shader
	shader->Bind();

	Echo::RenderElement* circle = element["circle"];		// circle render element

	/* draw the inner circle */
	// translate
	glm::mat4 viewCircle = glm::translate(glm::mat4(1.0f), glm::vec3(circle->GetX(time), circle->GetY(time), 0.0f));
	Echo::Orthographic::SetViewMatrix(shader, viewCircle);

	// render
	shader->SetShaderUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
	Echo::Renderer::Render(circle->GetVertexArray(), Echo::settings["circle"]["vertices"], GL_LINE_LOOP, 4);

	/* draw the approach circle (ring) */
	// translate and scale
	float scale = (float)Echo::settings["object"]["ringScale"] * object->GetApproachScale(time) + 1;

	glm::mat4 viewRing = glm::translate(glm::mat4(1.0f), glm::vec3(circle->GetX(time), circle->GetY(time), 0.0f));
	viewRing = viewRing * glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, 1.0f));
	Echo::Orthographic::SetViewMatrix(shader, viewRing);

	// render
	shader->SetShaderUniform4f("uColor", 0.6f, 0.7f, 0.8f, 1.0f);
	Echo::Renderer::Render(circle->GetVertexArray(), Echo::settings["circle"]["vertices"], GL_LINE_LOOP, 4);
}

int OsuTrainer::CircleComponent::OnEvent(float x, float y, int time)
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