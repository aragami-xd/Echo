#include "CircleComponent.h"
#include <Echo/buffers/Renderer.h>
#include <Echo/buffers/Orthographic.h>
using namespace std;

void CircleComponent::Render(ShaderList* shaders)
{
	Shader* basic = shaders->At("basic");
	basic->Bind();
	Orthographic::SetScaleMatrix(basic, 1, 1);
	Orthographic::SetViewMatrix(basic, object->GetX(), object->GetY());

	Renderer::Render(
		element["circle"]->GetVertexArray(),
		settings["circle"]["vertices"],
		GL_LINE_LOOP
	);
}
