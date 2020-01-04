#include "Orthographic.h"
#include <EchoHeader.h>
using namespace std;

void Orthographic::SetViewMatrix(Shader* shader, float x, float y)
{
	shader->Bind();
	shader->SetShaderUniformMat4f("view", glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f)));
}

void Orthographic::SetScaleMatrix(Shader* shader, float x, float y)
{
	shader->Bind();
	shader->SetShaderUniformMat4f("view", glm::scale(glm::mat4(1.0f), glm::vec3(x, y, 1.0f)));
}

void Orthographic::SetProjRatio(Shader* shader, float w, float h)
{
	shader->Bind();
	shader->SetShaderUniformMat4f("proj", glm::ortho(0.0f, w, 0.0f, h));
}
