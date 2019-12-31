#include "Orthographic.h"
#include <EchoHeader.h>
using namespace std;

void Orthographic::SetViewMatrix(Shader* shader, float x, float y)
{
	shader->Bind();
	shader->SetShaderUniformMat4f(string("view"), glm::translate(glm::mat4(1.0f), glm::vec3(-x, -y, 0.0f)));
}
