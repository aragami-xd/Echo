#include "CircleComponent.h"
#include <Echo/buffers/Renderer.h>
#include <Echo/buffers/Orthographic.h>
#include <Echo/core/Timing.h>
#include <Settings.h>
using namespace std;

void CircleComponent::Render(ShaderList* shaders, int time)
{
	Shader* basic = shaders->At("basic");
	basic->Bind();

	// draw the inner circle
	// translate then scale
	glm::mat4 viewCircle = glm::translate(glm::mat4(1.0f), glm::vec3(object->GetX(), object->GetY(), 0.0f));
	viewCircle = viewCircle * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	Orthographic::SetViewMatrix(basic, viewCircle);

	Renderer::Render(
		element["circle"]->GetVertexArray(),
		settings["circle"]["vertices"],
		GL_LINE_LOOP
	);

	// draw the approach circle (ring)
	glm::mat4 viewRing = glm::translate(glm::mat4(1.0f), glm::vec3(object->GetX(), object->GetY(), 0.0f));
	viewRing = viewRing * glm::scale(glm::mat4(1.0f),
		glm::vec3(
			(float)settings["object"]["ringScale"] * object->GetApproachScale(time) + 1,
			(float)settings["object"]["ringScale"] * object->GetApproachScale(time) + 1,
			1.0f
		)
	);
	Orthographic::SetViewMatrix(basic, viewRing);

	Renderer::Render(
		element["circle"]->GetVertexArray(),
		settings["circle"]["vertices"],
		GL_LINE_LOOP
	);
}