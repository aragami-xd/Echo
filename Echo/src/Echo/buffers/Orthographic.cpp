#include "Orthographic.h"

void Orthographic::SetViewMatrix(Shader* shader, glm::mat4 matrix)
{
	shader->Bind();
	shader->SetShaderUniformMat4f("view", matrix);
}

void Orthographic::SetProjMatrix(Shader* shader, glm::mat4 matrix)
{
	shader->Bind();
	shader->SetShaderUniformMat4f("proj", matrix);
}
