#include "Orthographic.h"

void Echo::Orthographic::SetModelMatrix(Shader* shader, const glm::mat4& matrix)
{
	shader->Bind();
	shader->SetShaderUniformMat4f("model", matrix);
}

void Echo::Orthographic::SetViewMatrix(Shader* shader, const glm::mat4& matrix)
{
	shader->Bind();
	shader->SetShaderUniformMat4f("view", matrix);
}

void Echo::Orthographic::SetProjMatrix(Shader* shader, const glm::mat4& matrix)
{
	shader->Bind();
	shader->SetShaderUniformMat4f("proj", matrix);
}