#include "SliderComponent.h"
#include <OsuSettings.h>

void OsuTrainer::SliderComponent::Render(Echo::ShaderList* shaders, int time)
{
	/* get the data */
	Echo::Shader* shader = shaders->At("basic");		// shader
	shader->Bind();

	Echo::RenderElement* bezier = element["curve"];	// slider curve
	Echo::RenderElement* circle = element["circle"];	// circle

	float timeRatio = object->GetBeatScale(time);	// object beat scaling

	/* render the slider body */
	Echo::Orthographic::SetViewMatrix(shader, glm::mat4(1.0f));

	shader->SetShaderUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);
	Echo::Renderer::Render(bezier->GetVertexArray(), 1 / (float)OsuTrainer::settings["bezier"]["step"], GL_LINE_STRIP, 5);

	/* render the slider circle */
	// translate
	// translate the circle based on the time ratio above
	glm::mat4 viewCircle = glm::translate(
		glm::mat4(1.0f),
		glm::vec3(bezier->GetX(timeRatio), bezier->GetY(timeRatio), 0.0f)
	);
	Echo::Orthographic::SetViewMatrix(shader, viewCircle);

	// render
	shader->SetShaderUniform4f("uColor", 0.6f, 0.7f, 0.8f, 1.0f);
	Echo::Renderer::Render(circle->GetVertexArray(), OsuTrainer::settings["circle"]["vertices"], GL_LINE_LOOP, 4);

	/* render the slider approach circle */
	// translate and scale
	float scale = (float)OsuTrainer::settings["object"]["ringScale"] * object->GetApproachScale(time) + 1;

	glm::mat4 viewRing = glm::translate(
		glm::mat4(1.0f),
		glm::vec3(bezier->GetX(timeRatio), bezier->GetY(timeRatio), 0.0f)
	);
	viewRing = viewRing * glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, 1.0f));
	Echo::Orthographic::SetViewMatrix(shader, viewRing);

	// render
	shader->SetShaderUniform4f("uColor", 0.6f, 0.7f, 0.8f, 1.0f);
	Echo::Renderer::Render(circle->GetVertexArray(), OsuTrainer::settings["circle"]["vertices"], GL_LINE_LOOP, 4);
}

int OsuTrainer::SliderComponent::OnEvent(float x, float y, int time)
{
	return 0;
}